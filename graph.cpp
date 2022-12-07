/************************************
Name: Fred Butoma
Final Project

Purpose: graph.cpp is the graph class
and contains all the methods and attributes
for a functional undirected and unweighted 
graph class
************************************/



/*************************
*************************
       GRAPH CLASS
*************************
**************************/

#include "graph.h"

Graph::Graph(){
    vertexList = new LinkedList;
}
Graph::~Graph() {
   vertexList->clearList();
}

void Graph::displayAdjacencyList(){
    Node* vertexCurrent = vertexList->getHead();
    if (vertexList->isEmpty()){
        cout << "Graph is empty." << endl;
        cout << "vertex count: " << vCount << endl;
        cout << "edge count: " << eCount << endl;
    }
    else{
        cout << " VERTEX: EDGES" << endl;
        while (vertexCurrent){
            cout << "      " << vertexCurrent->data.id << ": ";
            Node* currentEdge = nullptr;
            if (vertexCurrent->edgeList){
                currentEdge = vertexCurrent->edgeList->getHead();
            }
            while (currentEdge){
                cout << "(" << currentEdge->data.id << ")" << " ";
                currentEdge = currentEdge->next;
            }
            if (vertexCurrent->edgeList->getCount() == 0) {
                cout << "No edges.";
            }
            vertexCurrent = vertexCurrent->next;
            cout << endl;
        }
        cout << "vertex count: " << vCount << endl;
        cout << "edge count: " << eCount << endl;
    }
}
