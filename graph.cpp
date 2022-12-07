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
bool Graph::addVertex(int vertexID){
    bool added = false;
    string vData = std::to_string(vertexID);
    added = vertexList->addNode(vertexID, &vData);
    if (added){

        vCount++;
    }
    return added;
}
bool Graph::removeVertex(int vertexID){
    bool removed = false;
    bool edgeListCleared = false;
    Node* vertex = nullptr;
    vertex = vertexList->getHead();
    while (vertex){
        if (vertex->data.id == vertexID && vertex->edgeList->getCount() > 0){
            edgeListCleared = vertex->edgeList->clearList();
//            cout << "edgeListCleared set to " << edgeListCleared << ")  " << endl;
//            cout << "vertex is " << vertex << ")  " << endl;
//            cout << "vertex ID is " << vertex->data.id << ")  " << endl;
//            cout << "vertex edgeList->count is " << vertex->edgeList->getCount() << ")  " << endl;
        }
            vertex = vertex->next;
    }
//    if (edgeListCleared){
        removed = vertexList->deleteNode(vertexID);
//        cout << "removed set to " << removed << ")  " << endl;
//    }
    if (removed) {
        vCount--;
    }
    return removed;
}
bool Graph::addEdge(int vertexID, int edgeID){
    bool added = false;
    Node *vertexCurrent = nullptr;

    if (vertexList->getCount() > 0){
        vertexCurrent = vertexList->getHead();
//        cout << "inside addEdge and vertexCurrent is " << vertexCurrent << endl;
    }

   if (bothVerticesExist(vertexID, edgeID)){
       //add edge
       while (vertexCurrent){
           if (vertexID == vertexCurrent->data.id){
               string data = std::to_string(edgeID);
               added = vertexCurrent->edgeList->addNode(edgeID, &data);
           }
               vertexCurrent = vertexCurrent->next;
        }
    }
   if (added){
       eCount++;
   }
   return added;
}
bool Graph::bothVerticesExist(int vertexID, int edgeID){
//    cout << "inside bothExists()" << endl;
    bool vertexExists = false;
    bool edgeExists = false;
    bool bothExist = false;
    Node *vCurrent = nullptr;
//    cout << "initializing vCurrent" << endl;
    if (vertexList->getCount() > 0){
        vCurrent = vertexList->getHead();
    }
//     cout << "vCurrent is " << vCurrent << endl;
//    cout << "checking vertexExists" << endl;
//     cout << "vertexList->getCOunt() is " << vertexList->getCount() << endl;
    for (int i = 0 ; i < vertexList->getCount(); i++){
//        (vCurrent && !vertexExists){
       if (vCurrent && vertexID == vCurrent->data.id){
            vertexExists = true;
       }
           vCurrent = vCurrent->next; 
    }
//    cout << "vertexExists() is " << vertexExists << endl;
//     cout << "checking edgeExists" << endl;
    vCurrent = vertexList->getHead();
    for (int i = 0 ; i < vertexList->getCount(); i++){
//        (vCurrent && !edgeExists){
       if (edgeID == vCurrent->data.id){
           edgeExists = true;
       }
           vCurrent = vCurrent->next;
    }
//    cout << "edgeExists() is " << edgeExists << endl;
//     cout << "setting bothExists" << endl;
    if (vertexExists && edgeExists){
        bothExist = true;
     }
//     cout << "returning bothExists()" << endl;
//     cout << "bothExists() is " << bothExist << endl;
     return bothExist;
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
