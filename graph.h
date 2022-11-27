/**********************************************
Name: Fred Butoma
Final Project 

Purpose: graph.h has all the prototypes 
for the graph class 
**********************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "hashtable.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Graph{
    public:
    //constructors
    Graph(vector<vector<int>>);

    //destructor 
    ~Graph();

    //getters
    bool hasVector();
    bool hasPath(Hashtable*, int, int, vector<int>);
    void traverseDepthFirst(int);
    void traverseBreadthFirst(int);
    bool isEmpty();

    //setters
    


    private:

    //attributes
    int count;

    //helper methods 
};

#endif // GRAPH_H