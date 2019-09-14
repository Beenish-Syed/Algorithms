/* Title: prim.cpp
* Abstract: This program implements the prim algorithm on a given set of 
  vertices, edges and their weights
* Author: Beenish Syed
 * ID: 1426
 * Date: 06/15/2019 
 */
 #include <iostream>
#include <string>
#include <sstream> 
#include <fstream>
using namespace std;


void mst()
{
    int graph[20][20]={0};
    ifstream file;
    string fileName;
    cout<<"Enter your file name: ";
    cin>>fileName;
    file.open(fileName);
    if(!file)
    {
        cout<<"There was an error loading your file.";
    }
    else
    {
        int vertices;
        int edges; 
        int visited = 0;
        int startingNode=0;
        int startNode=0;
        int endNode=0;
        int cost=0;
        int count=0;
        int minCost=0;
        file>>vertices;
        int store[vertices*3];
        int visitedNodes[vertices];//holds the visited nodes
        file>>edges;
        for(int i=1; i<=edges; i++)
        {
            file>>startNode;
            file>>endNode;
            file>>cost;
            graph[startNode][endNode]=cost;
            graph[endNode][startNode]=cost;
        }
        cout<<"Enter the starting vertex: ";
        cin>>startingNode;
        visitedNodes[visited]=startingNode; 
        store[count]=startingNode;
        visited=visited+1;//first node is visited
        graph[startingNode][startingNode]=-1;//mark that node as visited.
        while(visited<vertices)
        {
            minCost=0;//initilize the minimum cost
            for(int i=0; i<visited; i++)
            {
                for(int j=1; j<=vertices; j++)
                {
                    if(graph[j][j]==-1 || graph[visitedNodes[i]][j]==0)//the node/edge is already visited or does not have a cost assigned
                    {
                        //do nothing 
                    }
                    else
                    {
                        if(minCost==0)
                        {
                            minCost=graph[visitedNodes[i]][j];
                            startNode=visitedNodes[i];
                            endNode = j;
                        }
                        else
                        {
                            int check=graph[visitedNodes[i]][j];
                            if(minCost>graph[visitedNodes[i]][j])
                            {
                                minCost=graph[visitedNodes[i]][j];
                                startNode=visitedNodes[i];
                                endNode = j;
                            }
                        }
                    }
                }
            }
            visitedNodes[visited]=endNode;
            graph[endNode][endNode]=-1;//mark the node visited in graph
            visited+=1;
            store[count]=startNode;
            store[count+1]=endNode;
            store[count+2]=minCost;
            count+=3;
        }
        for(int i=0; i<count; i+=3)
        {
            cout<<"New edge: "<<store[i]<<","<<store[i+1]<<" - cost "<<store[i+2]<<"\n";
        }
    }
}

int main()
{
    mst();
}
