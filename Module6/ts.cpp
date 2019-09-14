/* Title: ts.cpp
* Abstract: This program implements the topological 
sorting algorithm based on the source-removal algorithm.
* Author: Beenish Syed
 * ID: 1426
 * Date: 06/01/2019 
 */
 #include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
using namespace std;
int Matrix[50][50];

int findSource(int vertices)//Checks if a column is all 0's then that vertex is a source
{
    bool node;
    for(int i=0; i<vertices; i++)
    {
        if(Matrix[i][i]!=2)//check if the vertex has already been used in topological sort
        {
            for(int j=0; j<vertices; j++)
            {
                if (Matrix[j][i]==0)
                {
                    node=true;
                }
                else if(Matrix[j][i]!=0)
                {
                    node=false;
                    break;
                }
            }
            if(node==true)
            {
                Matrix[i][i]=2; //mark the vertex as already used as source
                return i;
            }
        }
    }
}
void removeSource(int source, int vertices)// removes the vertex that is used as a source by marking the entire row of that vertex as 0's
//except the Matrix[vertex][vertex] as that is used as marking the vertex as used.
{
    for(int i=0; i<vertices; i++)
    {
        if(i!=source)
        {
            Matrix[source][i]=0;
        }
    }
}
int main()
{
    int vertices;
    string fileName;
    ifstream fileObj;
    
    cout<<"Enter file name: ";
    cin>>fileName;
    fileObj.open(fileName);
    if(!fileObj)
    {
        cout<<"There was an error opening your file";
    }
    else
    {
        fileObj>>vertices;
        for(int i=0; i<vertices; i++)
        {
            for(int j=0; j<vertices; j++)
            {
                fileObj>>Matrix[i][j];
            }
        }
    }
    int source;
    cout<<"Topological Sort:\n";
    for(int i=0; i<vertices; i++)
    {
        source = findSource(vertices);
        removeSource(source, vertices);
        cout<<source;
        if(i<vertices-1)
        {
            cout<<" -> ";
        }
    }
    cout<<"\n";
}