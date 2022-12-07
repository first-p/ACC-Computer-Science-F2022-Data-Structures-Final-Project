/************************************
Name: Fred Butoma
Final Project

Purpose: graph.cpp is the graph class
and contains all the methods and attributes
for a functional undirected and unweighted 
graph class
************************************/

/*





//construcor 
Graph::Graph(int <vector>[][]){
    creates a linked list adjacent list from a 2D array 
    use every first element of every array to set the keys on linked list 
        if there is not a second element in every array- set the key->next to null 
        else  create a new linked list for every array that has more than one element (for the neighbor nodes) and add the neighbor nodes as nodes to that linked list 
        set key->next to the first node(head) of the linked list of neighbor nodes
        set last key node->next to null 

        
}


//destructor 


//depth fist traverse 
traverseDF(linkedList graph, int source){

    traverseDF(linkedList graph, source, source);
}
traverseDF(graph, source, prevSource){
    print source vector, then do a for loop for all neighbors of the current vector
        if the neighbor vector is not equal to the current vector then call recurison and pass this.neighbor vector as source, pass source for prevSource)
}

//breadth first traverse 
traverseBF(linkedList graph, )


//contains

//has path (graph, source, destination)





*/
/*************************
*************************
       GRAPH CLASS
*************************
**************************/

#include "graph.h"


Graph::Graph(){
    vertices = new LinkedList;
}

bool Graph::addVertex(int vertexID, string *vData){
    bool added = false; 
    added = vertices->addNode(vertexID, vData);
    if (added){
        vCount++;
    }
    return added;
}
bool Graph::addEdge(int vertexID, int edge){
    bool vertexExists = false; 
    bool edgeExists = false; 
    bool added = false; 
    //check if the vertex exists
    Node *current = vertices->getHead();
    while (current){
        if (vertexID == current->data.id){
            vertexExists = true;
        }
        else{
            current = current->next;
        }
    }
    //checks if the edge exists as a vertex
    current = vertices->getHead();
    while (current){
        if (edge == current->data.id){
            edgeExists = true;
        }
        else{
            current = current->next;
        }
    }
    //add edge
    if (vertexExists && edgeExists){
        current = vertices->getHead();
        while (current){
            if (vertexID == current->data.id){
                string data = std::to_string(vertexID);
                current->edges->addNode(vertexID, &data);
            }
        }
    }
    return added; 
}
void Graph::displayAdjacencyList(){
    Node* current = vertices->getHead();
    cout << "VERTEX  :   EDGES" << endl;
    while (current){
        cout << current->data.id << ": ";
        Node* currentEdge = current->edges->getHead();
        while (currentEdge){
            cout << currentEdge->data.id << "  ";
            currentEdge = currentEdge->next;
        }
        current = current->next;
        cout << endl;
    }
}

void Graph::traverseDepthFirst(){
    
}
void Graph::traverseBreadthFirst(){

}


// Graph::~Graph() {
    
// }

// bool Graph::hasVector(){
//     return false;
// }

// bool Graph::hasPath(Hashtable *graph, int src, int dst, vector<int> visitedList){
//     // bool arrived = false; 
//     // bool visited = false; 
//     // if (src == dst){
//     //     arrived = true; 
//     // }
//     // else{
//     //     for (int i = 0 ; i < visitedList.size(); i++){
//     //         if (visitedList[i] == src){
//     //             visited = true;
//     //         }
//     //     }
//     //     if (!visited){
//     //         visitedList.push_back(src);
//     //     }
         

//     // }
//     // return arrived;
//     return false;

    
// }

// void Graph::traverseDepthFirst(int sourceVectorId){

// }

// void Graph::traverseBreadthFirst(int sourceVectorId){

// }

// bool Graph::isEmpty(){
// return false; 
// }



/////////////////////
//LINKED LIST CLASS//
////////////////////

/*********************
Name: Fred Butoma
Assignment 6
Purpose: linkedlist.cpp is the linked list class and
has all the operations required to manipulate a
classic doubly linked list
*********************/

/*while (true){ //Minimized Linked List below:
/ constructor
LinkedList::LinkedList() {
  
}

// destructor
LinkedList::~LinkedList() {
  clearList();
}
////////////////////////
////// setters/////////
//////////////////////

bool LinkedList::addNode(int id, string *data) {
  bool added = false;
  Node *newNode = createNode(id, data);

  Data empty;
  bool duplicate = getNode(id, &empty);
  // bool duplicate = getNode(id, empty);

  // if (duplicate){
  //     delete newNode;
  //     newNode = NULL;
  //     return added;
  //     cout << "caught the duplicate" << endl;
  // }

  if (newNode && !duplicate){
    if (id > 0 && *data != "") {
    //creates first head node in list
    if (head == NULL){
      head = newNode;
      added = true;
    }
    else {
      //adds a node at front of the list (becomes new head)
        if (id < head->data.id){
          addHead(newNode);
          added= true;
        }
        // if !first node and !head node, finds the place in ordered list to link  a new node
        else{
          Node *current = head;
          while (!duplicate && id > current->data.id && current->next != NULL) {

            if (id == current->data.id){
               duplicate = true;
               cout << "found duplicate" << endl;
            }
            else {
              current = current-> next;
            }
          }
          // while (id != current->data.id && id > current->data.id && current->next != NULL) {
          //   current = current-> next;
          // }
        // add new node in between two existing nodes
          if (current->next != NULL){
            addMiddle(newNode, current);
            added = true;
            // cout << "used addMiddle()" << endl;

          }
        // add node after the last existing node (new tail)
          else if(current->next == NULL){
              addTail(newNode, current);
              added = true;
          }

        }
    }
  }
  }
  //if the id is a duplicate
  if (duplicate){
      delete newNode;
      newNode = NULL;

    }
    return added;
  }


bool LinkedList::addHead(Node *newNode) {
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
  return true;
}

bool LinkedList::addMiddle(Node *newNode, Node *current) {
  newNode->prev = current->prev;
  newNode->next = current;
  current->prev->next = newNode;
  current->prev = newNode;
  return true;
}

bool LinkedList::addTail(Node *newNode, Node *current) {
  newNode->prev = current;
  current->next = newNode;
  return true;
}

Node* LinkedList::createNode(int id, string *data) {
  Node *newNode = new Node;
  if (newNode){
    newNode->data.id = id;
    newNode->data.data = *data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
  }
  else {
    return NULL;
  }
}

bool LinkedList::deleteNode(int id) {
  bool deleted = false;
  Node *current = head;
  while (!deleted && current){
       if(id == current->data.id && isLast(current)){
                delLast(current);
                deleted = true;
            }
        else if (id == current->data.id && current->prev == NULL){
            delHead(current);
            current = NULL;
            deleted = true;

        }

        else if (id == current->data.id && current->next == NULL){
            delTail(current);
            current = NULL;
            deleted = true;
        }
        else if (id == current->data.id && current->next != NULL && current->prev != NULL ){
            delMiddle(current);
            current = NULL;
            deleted = true;
        }

        else {
            current = current -> next;
        }
    }
    return deleted;
}

bool LinkedList::delHead(Node *current){
    current->next->prev = NULL;
    head = current->next;
    delete current;
    current= NULL;
    return true;
}
bool LinkedList::delMiddle(Node *current){
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
    current = NULL;
    return true;
}
bool LinkedList::delTail(Node *current){
    current->prev->next = NULL;
    delete current;
    current = NULL;
    return true;
}
bool LinkedList::isLast(Node *current){
    bool isLast = false;
    if (current->next == NULL && current->prev == NULL){
        isLast = true;
    }
    return isLast;
}
bool LinkedList::delLast(Node *current){
    delete current;
    current = NULL;
    head = NULL;
    return true;
}
bool LinkedList::clearList() {
    bool cleared = false;
    Node *current;
    while(head){
        current = head;
        if (!isLast(current)){
            current->next->prev = NULL;
            head = current->next;
            delete current;
            current = NULL;
        }
        else {
            delLast(current);
            cleared = true;
        }
    }
    return cleared;
}
////////////////////////
////// getters/////////
//////////////////////
Node* LinkedList::getHead(){
    return head;
}
bool LinkedList::getNode(int id, Data *emptyObj) {
  bool got = false;
  Node *current = head;
  while (current){
    if (id == current->data.id){
        emptyObj->id = current->data.id;
        emptyObj->data = current->data.data;
        got = true;
        current = NULL;
    }
    else{
        current = current -> next;
    }
  }
  if (!got){
     emptyObj->id = -1;
     emptyObj->data = "";
  }
  return got;
}

void LinkedList::printList(bool backward) {
  Node *current = new Node;
  current = head;
  int count = 0;
  if (!backward) {
    //this is the print function used in the hashtable print list for each linked list
    while (current) {
      cout << current->data.id << " -> ";
      current = current->next;
    }
  } else if (backward) {
    current = head;
    bool tailFound = false;
    int count = 0;
    while (current && !tailFound) {
      if (current->next) {
        current = current->next;
        count++;
      } else {
        tailFound = true;
      }
    }
    while (current) {
      cout << count << ": " << current->data.id << " : " << current->data.data << endl;
      current = current->prev;
      count --;
    }
  }
}
int LinkedList::getCount() {
  Node *current = head;
  int count = 0;
    while (current) {
      count++;
      current = current->next;
    }
  return count;
}

bool LinkedList::isEmpty(){
  bool empty = false;
  Node *current = head;
  if (current == NULL){
    empty = true;
  }
  return empty;
}

bool LinkedList::exists(int id) {
  bool exists = false;
  Node *current = head;
  while (current){
    if (current->data.id == id){
        exists = true;
        current = NULL;
    }
    else {
        current = current->next;
    }
  }
  return exists;
}
}

*/