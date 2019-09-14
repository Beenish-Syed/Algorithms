/* Title: equal_group.cpp
* Abstract: given n positive integers, this program partition them into two 
            disjoint groups with the same sum of their elements.
* Author: Beenish Syed
 * ID: 1426
 * Date: 05/13/2019 
 */
#include <iostream>  
#include <math.h>
using namespace std;  

void convertBinary(int *p, int num, int input)
{
     int a[15], n, i;    
    n=5;
    
    for(i=0; i<input; i++)    
    {    
        a[i]=num%2;    
        num= num/2;  
    }    
    int f=0;
    for(i=i-1;i>=0 ;i--)    
    {    
        p[f]=a[i];
        f++;  
    }   
}
bool checkSum(int *p, int *array, int input, int sum)
{
    int temp=0;
    for(int i=0; i<input; i++)
    {
        if(p[i]==1)
        {
            temp= temp+array[i];
        }
    }
    if(temp == sum)
    {
        return true;
    }
    else 
    {
        return false;
    }
}
int getsum(int *arr, int input)
{
    int sum=0;
    for(int i=0; i<input; i++)
    {
        sum= sum+arr[i];
    }
    return sum;
}
int numberOfCombinations(int n)
{
    return pow(2,n)-1;
}

int main()  
{  
    int *binary;
    int *arrayNumbers; 
    int input;
    cout<<"Enter the number of input: ";
    cin>>input;
    binary = new int[input];
    arrayNumbers = new int[input];
    cout<<"Enter your numbers:"<<"\n";
    for(int i=0; i<input; i++)
    {
        cin>>arrayNumbers[i];
    }
   
    int groupOne[input]; 
    int groupTwo[input];
    int sum= getsum(arrayNumbers, input); 
    bool check; 
    int combination = numberOfCombinations(input);
    int sumTwo=0;
    bool done=false;

    //loop for each combination 
    for(int i=1; i<= combination; i++)
    {
        convertBinary(binary, i, input);
        check = checkSum(binary, arrayNumbers, input, sum/2);
        if (check==true)
        {
            int one=0;
            int two = 0;
            //add numbers of group to the array
            for(int j=0; j<input; j++)
            {
                if(binary[j]==1)
                {
                    groupOne[one]=arrayNumbers[j];
                    one++;
                }
                else if(binary[j]==0)
                {
                    groupTwo[two]=arrayNumbers[j];
                    sumTwo+=arrayNumbers[j];
                    two++;
                }
            }
            if(sumTwo==sum/2)
            {
                int i=0; 
                int j=0;
                cout<<"The two equal sum groups are: ";
                while(i<one)
                {
                    cout<<groupOne[i]<<" ";
                    i++;
                }
                cout<<"VS ";
                while(j<two)
                {
                  cout<<groupTwo[j]<<" ";
                    j++;
                }
                done=true;
                cout<<"\n";
                break;
            }
        }
    }
    if(done==false)
    {
        cout<<"Equal groups don't exist"<<"\n";
    }
}  