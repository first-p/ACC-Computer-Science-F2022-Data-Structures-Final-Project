/************************************
Name: Fred Butoma
Final Project

Purpose: graph.cpp is the graph class
and contains all the methods and attributes
for a functional undirected and unweighted 
graph class
************************************/

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
    bool removedVertex = false;
    bool removedAsEdge = false;
    bool edgeListCleared = false; //for loop through entire list and delete the edge from all vertices edge lists first
    Node* currentVertex = nullptr;
    Node* currentEdge = nullptr;
    vector <int> delList;
    if (vertexList->getCount() > 0){
        currentVertex = vertexList->getHead();
    }
    //clear its edgelist
    while (currentVertex){
        if (currentVertex->data.id == vertexID && currentVertex->edgeList->getCount() > 0){
            eCount -= currentVertex->edgeList->getCount();
            currentVertex->edgeList->clearList();
            currentEdge = currentVertex->edgeList->getHead();
        }
        //search through all edge lists and remove vertex as an edge from other vertices
        else if (currentVertex->edgeList->getCount() > 0){
            currentEdge = currentVertex->edgeList->getHead();
            for (int i = 0 ; i < currentVertex->edgeList->getCount(); i++){
                if (currentEdge && currentEdge->data.id == vertexID){
                    currentVertex->edgeList->deleteNode(vertexID);
                    eCount--;
                }
                currentEdge = currentEdge->next;
            }
        }
        currentVertex = currentVertex->next;
    }
    //remove vertex
    removedVertex = vertexList->deleteNode(vertexID);
    if (removedVertex) {
        vCount--;
    }
    return removedVertex;
}

bool Graph::addEdge(int vertexID, int edgeID){
    bool added = false;
    Node *vertexCurrent = nullptr;

    if (vertexList->getCount() > 0){
        vertexCurrent = vertexList->getHead();
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
bool Graph::removeEdge(int vertexID, int edgeID){
    bool removed = false;
    Node *vertexCurrent= nullptr;
    if (vertexList->getCount() > 0){
        vertexCurrent = vertexList->getHead();
    }

   if (bothVerticesExist(vertexID, edgeID)){
       for (int i = 0; i < vertexList->getCount(); i++){
            if (vertexCurrent->data.id != vertexID){
                vertexCurrent = vertexCurrent->next;
            }

       }
       for (int i = 0; i < vertexCurrent->edgeList->getCount(); i ++){
            if (vertexCurrent->edgeList && vertexID == vertexCurrent->data.id){
                removed = vertexCurrent->edgeList->deleteNode(edgeID);
                cout << endl;
            }
            if (vertexCurrent->next){
                vertexCurrent = vertexCurrent->next;
            }
       }
    }
   if (removed){
       eCount--;
   }
   return removed;
}

bool Graph::bothVerticesExist(int vertexID, int edgeID){
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

void Graph::traverseDepthFirst(int startPoint){ //public
    //reset DFTCost
    DFTCost = 0;
    int edgeCost = -1;
    vector<int> visitedList;
    edgeCost = traverseDepthFirst(startPoint, visitedList);
    cout << "Depth-First Traveral" << endl;
    for (int i = 0 ; i < visitedList.size(); i++){
        cout << visitedList[i] << endl;
    }
    cout << "Cost: " << DFTCost << " edges." << endl;
}
int Graph::traverseDepthFirst(int startPoint, vector<int> &visitedList){ //private
    int edgeCost = -1;
    Node *thisVertex = nullptr;
    if (findVertexNode(startPoint)){
        thisVertex = findVertexNode(startPoint);
    }
    if (thisVertex){
        visitedList.push_back(thisVertex->data.id);
        DFTCost++;
    }
    Node *eCurrent = nullptr;
    if (thisVertex->edgeList->getCount() > 0){
        eCurrent = thisVertex->edgeList->getHead();
    }

    while (eCurrent){
        if (wasVisited(eCurrent->data.id, visitedList)){
            eCurrent = eCurrent->next;
        }
        else if (eCurrent){
            traverseDepthFirst(eCurrent->data.id, visitedList);
            eCurrent = eCurrent->next;
        }
    }
    if (edgeCost > -1){
        edgeCost += 1;
    }

    return edgeCost;
}
int Graph::traverseBreadthFirst(int startPoint){ //public
    //reset cost
    BFTCost = 0;int edgeCost = -1;
    vector<int> visitedList;
    vector<int> queue;
    queue.push_back(startPoint);

    while (queue.size() > 0){
        int current = -1; //1
        if (queue[0]){ //2-to avoid undefined behavior
            current = queue[0];
        }
        cout << current << endl;//1
        queue.erase(queue.begin()); //2-pull from queue
        visitedList.push_back(current);//push to queue
        BFTCost++;

        Node *thisEdge = findVertexNode(current)->edgeList->getHead();
        while(thisEdge){
            if (wasVisited(thisEdge->data.id, visitedList)){
                thisEdge = thisEdge->next;
            }
            else if (thisEdge){
                queue.push_back(thisEdge->data.id);
                thisEdge = thisEdge->next;
            }
        }
    }
    cout << "Cost: " << BFTCost << " edges." << endl;
    return BFTCost;
}

bool Graph::wasVisited(int vertexID, vector<int> visitedList){
    bool visited = false;
    for (int i = 0 ; i < visitedList.size(); i++){
        if (vertexID == visitedList[i]){
            visited = true;
        }
    }
    return visited;
}

Node* Graph::findVertexNode(int vertexID){
    Node * returnNode = nullptr;
    Node *current = nullptr;
    if (vertexList->getCount() > 0){
        current = vertexList->getHead();
    }
    for (int i = 0 ; i < vertexList->getCount(); i++){
        if (vertexID == current->data.id){
            returnNode = current;
        }
            current = current->next;
    }
    return returnNode;
}
 bool Graph::isEmpty(){
 bool isEmpty = true;
 if (vertexList){
     isEmpty = false;
 }
 return isEmpty;
}