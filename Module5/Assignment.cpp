/* Title: Assignment.cpp
* Abstract: This program finds the optimum assignment cost
* Author: Beenish Syed
 * ID: 1426
 * Date: 05/27/2019 
 */
#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include <queue>
using namespace std;

int size;
int costMatrix[16][16];
int minimum; 
int numOfPermutations=0;
int minimumAssignment[16];

int print(int array[])
{
    numOfPermutations++;
    int cost=0;
    cout<<"Permutation "<<numOfPermutations<<": <";
    for(int i=1; i<=size; i++)
    {
        cout<<array[i]<<" ";
        cost+=costMatrix[i][array[i]];
    }
    cout<<">  Cost: "<<cost;
    cout<<"\n";
    return cost;
}
void solution()
{
    int cost=0;
    cout<<"Solution: <";
    for(int i=1; i<=size; i++)
    {
        cout<<minimumAssignment[i]<<" ";
        cost+=costMatrix[i][minimumAssignment[i]];
    }
    cout<<"> Cost: "<<cost<<"\n";
}
void permutations(int n, int array[])
{
    int temp;
    if(n==1)
    {
        int cost=print(array);
        if(numOfPermutations==1)
        {
            minimum=cost;
            for(int i=1; i<=size; i++)
            {
                minimumAssignment[i]=array[i];
            }
        }
        else
        {
            if(cost<minimum)
            {
                minimum=cost;
                //store the minimum 
                for(int i=1; i<=size; i++)
                {
                    minimumAssignment[i]=array[i];
                }
            }
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            permutations(n-1, array);
            if(n%2==0)
            {
                temp=array[1];
                array[1]= array[n];
                array[n]=temp;
            }
            else
            {
                temp=array[i];
                array[i]= array[n];
                array[n]=temp;
            }
        }
    }
}

int main()
{
    int jobs;
    int people;
    cout<<"Enter the number of jobs: ";
    cin>>jobs;
    people=jobs;
    int array[people];
    size=jobs;
    for(int i=1; i<=jobs; i++)
    {
        array[i]=i;
    }
    cout<<"Enter the assignment costs for each person: \n";
    for(int i=1; i<=people; i++)
    {
        cout<< "Person"<<i<<": ";
        for(int j=1; j<=jobs; j++)
        {
            cin>>costMatrix[i][j];
        }
    }
    permutations(jobs, array);
    solution();
}