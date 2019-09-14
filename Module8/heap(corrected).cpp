/* Title: heap.cpp
* Abstract: This program implements the heap and its operations
* Author: Beenish Syed
 * ID: 1426
 * Date: 06/14/2019 
 */
 #include <iostream>
#include <string>
#include <sstream> 

using namespace std;

void print(int array[], int size)
{
    for(int i=1; i<=size; i++)
    {
        cout<<array[i]<<" ";
    }
}
void makeHeap(int heap[], int size)
{
    bool test;
    int child; //for child nodes
    for(int i=size/2; i>=1; i--) //loop through parent nodes starting from the last parent node
    {
        int k=i; 
        int parent= heap[k]; //element in the parent node
        test = false;
        while(!test && 2*k<=size)//making sure there is atleast one child node for this parent node
        {
            child = 2*k;
            if(child < size)//there are two child nodes for this parent node
            {
                if(heap[child]<heap[child+1]) // if first child is smaller than the second child
                {
                    child= child+1;//move to the bigger child
                }
            }
            
            if(parent>=heap[child])//if parent node is greater than child node
            {
                test=true;
            }
            else if (parent<heap[child])
            {
                heap[k] = heap[child];
                k=child; //assign k the value of child index
                heap[k] = parent; //assign the parent node value to the child node
            }
        }
    }
}

bool checkHeap(int heap[], int size)
{
    bool check; 
    int child = size;
    //while(child>=(size/2)+1)
    while(child>1)
    {
        if(heap[child]>heap[child/2])
        {
            check = false;
            return check;
        }
        else
        {
            child= child-1;
            check = true;
        }
    }
    return check;
}


void deleteMax(int heap[], int size)
{
    
    int temp = heap[1];
    heap[1]=heap[size];
    heap[size]=temp;
    
    size=size-1;
    bool check = checkHeap(heap, size);
    if(check==false)
    {
        makeHeap(heap, size);
    }
}


void insertInHeap(int heap[], int size)
{ 
    int value;
    bool check;
    cout<<"Enter the number you want to insert in the heap: ";
    cin>>value;
    heap[size]=value;
    check = checkHeap(heap, size);
    if(check==false)
    {
        makeHeap(heap, size);
    }
   
}
void heapSort(int heap[], int size)
{ 
    
    int n=size;
    for(int i=1; i<=n; i++)
    {
        deleteMax(heap, size);
        size=size-1;
    }
}
main()
{
    bool check;
    int size;
    int *heapArray;
    int selection=0;
    cout<<"Input size:";
    cin>>size;
    heapArray = new int[size+1];
    cout<<"Enter numbers:";
    for(int i=1; i<=size; i++)
    {
        cin>>heapArray[i];
    }
    check=checkHeap(heapArray, size);
    if(check==true)
    {
        cout<<"It is a heap!\n";
    }
    else if(check==false)
    {
        cout<<"It is NOT a heap.\n";
        makeHeap(heapArray, size);
        check = checkHeap(heapArray, size);
        if(check == true)
        {
            cout<<"Heap constructed: ";
            print(heapArray, size);
            cout<<"\n";
        }
    }
    bool operation=true;
    while(operation)
    {
        cout<<"Select an operation: \n1. Insert a number. \n2. Delete the max.\n3. Heapsort and Quit.\n";
        cin>>selection;
        switch(selection)
        {
            case 1:
                size=size+1;
                insertInHeap(heapArray, size);
                print(heapArray, size);
                break;
            case 2:
                deleteMax(heapArray, size);
                size=size-1;
                print(heapArray, size);
                break;
            case 3:
                heapSort(heapArray, size);
                print(heapArray, size);
                cout<<"Bye!";
                operation=false;
                break;
        }
        cout<<"\n";
    }
}