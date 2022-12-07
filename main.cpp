/**********************************************
Name: Fred Butoma
Final Project

Purpose: main.cpp is the test bed for the 
undirected and unweighted graph class
**********************************************/

#include "main.h"
int main() {

    vector<vector<int>> edgeList1 = {{1,2}, {1,3}, {2,1}, {2,4}, {3,1}, {3,5}, {4,2}, {4,6}, {5,3}, {6, 4}};

    vector<vector<int>> edgeList2 = {{1,2}, {2,1}, {3,1}, {4,2}, {5,3}, {6, 4}};

    Graph g1;
    cout << "created empty graph" << endl;

    cout << "printing empty adjacency list" << endl;
     
     g1.displayAdjacencyList();
     













    return 0; 
}