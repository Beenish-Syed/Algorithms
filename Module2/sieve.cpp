/* Title: sieve.cpp
* Abstract: This program reads a positive number from the user and tells the prime numbers up till that number
* Author: Beenish Syed
 * ID: 1426
 * Date: 05/05/2019 
 */
 
#include <iostream>
#include <cmath>

using namespace std;


int findSqrt(int number)
{
    double result = sqrt(number);
    int x= (int)result;
   // cout<<"Sqrt is: "<<x<<"\n";
    return x;
}

int main()
{
    int n;
    int *numbers;
    int j;
    cout<<"Input the integer:\n";
    cin>>n;
    
    numbers = new int[n];
    for(int p=2; p<=n; p++)
    {
        numbers[p] = p;
    }
    int sqrt = findSqrt(n);

    for (int p=2; p<=sqrt; p++)
    {
        if(numbers[p]!=0) // the number is not yet eliminated
        {
            j = p*p;
            while(j<=n)
            {
                numbers[j]=0;
                j = j+p; //multiples of the number
            }
        }
    }
    cout<<"the prime numbers are:\n";
    for(int i=0; i<=n; i++)
    {
        if(numbers[i]!=0)
        {
            if(i>2)
            {
                cout<<","<<" ";
            }
           cout<<numbers[i];
        }
    }
    cout<<"\n";
    
    return 0;
}