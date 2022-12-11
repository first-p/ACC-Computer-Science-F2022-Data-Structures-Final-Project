/**********************************************
Name: Fred Butoma
Final Project

Purpose: graph.h has all the prototypes
for the graph class
**********************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.h"
#include "queue.h"

class Graph{
    public:
        //constructors
        Graph();

        //destructor
        ~Graph();

        //getters
        void traverseDepthFirst(int);
        int traverseBreadthFirst(int);


        bool isEmpty();
        void displayAdjacencyList();

        //setters
        bool addVertex(int);
        bool removeVertex(int);
        bool addEdge(int, int);
        bool removeEdge(int, int);
        bool clearGraph();

    private:
        //attributes
        int vCount;
        int eCount;
        int DFTCost;
        int BFTCost;
        LinkedList *vertexList;
        Queue *queue_;

        //helper methods
        bool bothVerticesExist(int, int);
        Node* findVertexNode(int);
        bool wasVisited(int, vector<int>); //
        int traverseDepthFirst(int, vector<int> &);
};


#endif // GRAPH_H

