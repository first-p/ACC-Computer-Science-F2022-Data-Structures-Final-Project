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

        void shortestPath(int, int);

        void traverseDepthFirst(int);
        int traverseBreadthFirst(int);


        bool isEmpty();
        void displayAdjacencyList();
        int vertexCount();
        int edgeCount();

        //setters
        bool addVertex(int);
        bool removeVertex(int);

        bool addEdge(int, int);
        bool removeEdge(int, int);

    private:
        //attributes
        int vCount;
        int eCount;
        int DFTCost;
        int BFTCost;
        LinkedList *vertexList;

        //helper methods
        Node *createNode(int, string *);
        bool bothVerticesExist(int, int);
        bool hasVertex();
        bool hasEdge();
        Node* findVertexNode(int);
        bool wasVisited(int, vector<int>);

        int traverseDepthFirst(int, vector<int> &);
//        void traverseDepthFirstRecursion(Node *, vector<int> &);
        bool removeVertexFromEdgeLists(int);


};


#endif // GRAPH_H

