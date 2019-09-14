/* Title: bfs.cpp
* Abstract: This program shows the result of a breadth first search
* Author: Beenish Syed
 * ID: 1426
 * Date: 05/26/2019 
 */
#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
#include <queue>   
using namespace std;

void print(int arr[], int size)
{
    cout<<"BFS order: ";
    for(int i=0; i<size; i++)
        {
            cout<<arr[i];
            if(i<size-1)
            {
                cout<<"->";
            }
        }
        cout<<"\n";
}
main()
{
    string fileName;
    int startVertex=0;
    
    cout<<"Enter the file name: "<<"\n";
    cin>>fileName;
    cout<<"Enter your starting vertex: ";
    cin>>startVertex;
    
    ifstream readFile;
    readFile.open(fileName);
    
     if(!readFile)
    {
        cout<<"There is some error opening in your file";
    }
    else
    {
        int numOfVertices;
        readFile>>numOfVertices;
        int arrayVertex[numOfVertices][numOfVertices];
        for(int i=0; i<numOfVertices; i++)
        {
            for(int j=0; j<numOfVertices; j++)
            {
               readFile>>arrayVertex[i][j];
            }
        }
        
        queue<int> myqueue;
        myqueue.push(startVertex);
        int visited[numOfVertices];
        int store[numOfVertices];
        store[0]=startVertex;
        visited[startVertex]=1;// mark the starting node as visited
        int count=1;
        int node=startVertex;
        while(!myqueue.empty())
        {
            for(int i=0; i<numOfVertices; i++)
            {
                if(arrayVertex[node][i]==1 && visited[i]!=1)//==0)
                {
                    myqueue.push(i);
                    visited[i]=1; //mark the vertex as visited
                    store[count]=i;
                    count++;
                }
            }
            myqueue.pop();
            node=myqueue.front();
           
        }
        print(store, numOfVertices);
    }
    
}