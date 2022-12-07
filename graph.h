/**********************************************
Name: Fred Butoma
Final Project 

Purpose: graph.h has all the prototypes 
for the graph class 
**********************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.h"

class Graph{
    public:
        //constructors
        Graph();

        //destructor 
        ~Graph();

        //getters
        bool hasVector();
        bool hasPath(int, int);
        void traverseDepthFirst();
        void traverseBreadthFirst();
        void shortestPath(int);
        bool isEmpty();

        void displayAdjacencyList();

        //setters
        bool addVertex(int, string *);
        bool addEdge(int, int);

    private:
        //attributes
        int vCount;
        LinkedList *vertices;
        //helper methods 
        Node *createNode(int, string *);

};


#endif // GRAPH_H

