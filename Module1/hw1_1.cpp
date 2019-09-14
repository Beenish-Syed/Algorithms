/* Title: hw1_1.cpp
* Abstract: This program reads text from user given file and displays the minmum number from it
* Author: Beenish Syed
 * ID: 1426
 * Date: 04/30/2019 
 */
 
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

using namespace std;

int minNumber(int array[], int size)
{
    int min=0;
    for(int i=0; i<size; i++)
    {
        if(min>array[i])
        {
            min = array[i];
        }
    }
    return min; 
}

void sort(int a[], int n) {
   int i, j, min, temp;
   for (i = 0; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (a[j] < a[min])
            min = j;
      temp = a[i];
      a[i] = a[min];
      a[min] = temp;
   }
}

void displayDistinct(int arr[], int length)
{
    cout<<"Number"<<'\t'<<"Count"<<'\n';
    int count =1; 
    for(int i=0; i<length; i++)
    {
        if (arr[i]==arr[i+1])
        {
            count++;
        }
        else if(arr[i]!=arr[i+1])
        {
            cout << arr[i]<<'\t'<<count<<'\n';
            count=1;
        }
    }
}
int main()
{
    int *store;
    string path; //address of the file to be read
    ifstream readFile; // variable to read from file
    cout << "Enter your file path:\n";
    getline(cin, path);
    cout << "\n";
    int line=0;
    readFile.open(path.c_str());
    if(!readFile)
    {
        cerr << "Unable to open your file";
    }
    else
    {
        int index = 0; 
        readFile >> line;
        int length = 0; 
        length = line;
        store = new int [line];
        int temp; 
        while (readFile>>line)
        {
            store[index]=line;
            index++;
        }
        int minimum = minNumber(store, length);
        cout << "Minimum number is: " << minimum<<'\n';
        sort(store, length);
        
        displayDistinct(store, length);
    }
    readFile.close();
    return 0;
}