/* Title: adj_matrix.cpp
* Abstract: This program converts a directed graph stored in an input file into an adjacency matrix format
* Author: Beenish Syed
 * ID: 1426
 * Date: 05/05/2019 
 */
 
#include <iostream>
#include <fstream>
#include <sstream> 
#include <string>

using namespace std;

int main()
{
    string fileName; //address of the file to be read
    ifstream readFile; // variable to read from file
    
    cout << "Enter your file name:\n";
    getline(cin, fileName);
    cout << "\n";
    int vertices = 0;
    int edges = 0;
    int firstInput;
    int secondInput;
    readFile.open(fileName.c_str());
    if(!readFile)
    {
        cerr << "Unable to open your file";
    }
    else
    {
        readFile >> vertices;
        int arrayOfVertices[vertices][vertices];
        
        //initialize array to 0's
        for(int i=0; i<vertices; i++)
        {
            for(int j=0; j<vertices; j++)
            {
                arrayOfVertices[i][j]=0;
            }
        }
        
        readFile>>edges;
        for(int i=0; i<edges; i++)
        {
            readFile>>firstInput;
            readFile>>secondInput;
            arrayOfVertices[firstInput][secondInput]=1; 
        }
        
        //display the matrix
        for(int i=0; i<vertices; i++)
        {
            for(int j=0; j<vertices; j++)
            {
                cout<<arrayOfVertices[i][j];
                cout<<" ";
            }
            cout<<"\n";
        }

    }
}