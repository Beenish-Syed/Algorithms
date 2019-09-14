/* Title: power.cpp
* Abstract: this program computes 2n for a nonnegative integer n entered by the user.
* Author: Beenish Syed
 * ID: 1426
 * Date: 05/10/2019 
 */
 
#include <iostream>
#include <cmath>

using namespace std;

int power(int m)
{
    if(m==0)
    {
        return 1;
    }
    else
    {
        //return 2*power(m-1);
        return power(m-1)+power(m-1);
    }
}
int main()
{
    int n=0;
    cout<<"Enter the number:"<<"\n";
    cin>>n;
    int result= power(n);
    cout<<"Your answer is: "<<result<<"\n";
    return 0; 
    
}