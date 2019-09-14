/* Title: ShortRep.cpp
* Abstract: This program takes a list of number and represents them in non- decreasing short representation
* Author: Beenish Syed
 * ID: 1426
 * Date: 05/25/2019 
 */
#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>


using namespace std;

void printSortedArray(int arr[], int s)
{
    cout<<"Printing sorted array:"<<"\n";
    for(int i=0; i<s; i++)
    {
       cout<<arr[i];
     
        if ( (arr[i]+1) == arr[i+1] )
        {
            while( (arr[i]+1) == arr[i+1])
            {
                i++;
            }
            cout<<"-"<<arr[i];
        }
        cout<<" ";
    }
    cout<<"\n";
}

int* merge(int array1[], int size1, int array2[], int size2, int newArray[])
{
    int k=0; 
    int i=0;
    int j=0;
    
    //int size1 = sizeof(array1)/sizeof(array1[0]);
    //int size2 = sizeof(array2)/sizeof(array2[0]); 
    while( i<size1 && j<size2 )
    {
        if(array1[i]<array2[j])
        {
            newArray[k]=array1[i];
            k++;
            i++;
        }
        else if(array1[i]>array2[j])
        {
            newArray[k]=array2[j];
            k++;
            j++;
        }
    }
    if(i==size1)
    {
        for(int m=j; j<size2; j++)
        {
            newArray[k]=array2[j];
            k++;
        }
    }
    else if(j==size2)
    {
        for(int m=i; i<size1; i++)
        {
            newArray[k]=array1[i];
            k++;
        }
    }
}

void sortArray(int a[], int n)// a is the array to be sorted, n is the size of the array
{
    if(n>1)
    {
        int first_half_size = (n/2);
        int second_half_size = n-first_half_size;
        int subarray1[first_half_size];
        int subarray2[second_half_size];
        //copy array into sub arrays
        for(int i=0; i<first_half_size; i++)
        {
            subarray1[i] = a[i];
        }
        for(int i=0; i<second_half_size; i++)
        {
            subarray2[i] = a[i+first_half_size];
        }
        sortArray(subarray1, first_half_size);
        sortArray(subarray2, second_half_size);
        merge(subarray1, first_half_size, subarray2, second_half_size, a);
    }
}


int main()
{
    string fileName;
    ifstream readFile; // variable to read from file
    int arraySize = 0;
    cout<<"Enter your file name: "<<"\n";
    cin>>fileName;
    readFile.open(fileName);

    if(!readFile)
    {
        cout<<"There is some error opening in your file";
    }
    else
    {
        readFile>>arraySize;
        int array[arraySize];
        for(int i=0; i<arraySize; i++)
        {
            readFile>>array[i];
        }
        sortArray(array, arraySize);    
        printSortedArray(array, arraySize);
    }
}