// ****************************************
// Fred Butoma
// Challenge 2 part 1

// purpose: Queue class
//  ****************************************

#include "queue.h"


// constructor
Queue::Queue() {
  head = nullptr;
  tail = nullptr;
}

// destructor
Queue::~Queue() {
  clearList();
}

//PUSH//
bool Queue::push(int id, string *data){
   bool pushed = false;
    pushed = addNode(id, data);
    return pushed;
}

//ADD NODE//
bool Queue::addNode(int id, string *data) {
  bool added = false;
  Node_ *newNode = createNode(id, data);

  Data_ empty;
  bool duplicate = getNode(id, &empty);

  if (newNode && !duplicate){
    if (id > 0 && *data != "") {
        //creates first head node in list
        if (head == NULL){
        tail = newNode;
        head = newNode;
        added = true;
        }
        else {

            Node_ *current = tail;
            // add node after the last existing node (new tail)
                addTail(newNode, current);
                added = true;
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


bool Queue::addTail(Node_ *newNode, Node_ *current) {
  newNode->prev = current;
  current->next = newNode;
  tail = newNode;
  return true;
}

Node_* Queue::createNode(int id, string *data) {
  Node_ *newNode = new Node_;
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

bool Queue::pull(){
    bool pulled = false;
    if (!isEmpty()){


        Node_ *current = head;
        int id = current->data.id;

        pulled = deleteNode(current->data.id);
        if (pulled){
            cout << id << endl;
        }
    }
    return pulled;
}

bool Queue::peek(Node_ *node){
    bool peeked = false;
    if (!isEmpty()){

        Data_ empty;
        Node_ *current = head;
        int id = current->data.id;

        peeked = getNode(id, &empty);
        if (peeked){
            node->data.id = id;
        }
    }
    return peeked;
}

bool Queue::getNode(int id, Data_ *emptyObj) {
  bool got = false;
  Node_ *current = head;
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
bool Queue::deleteNode(int id) {
  bool deleted = false;
  Node_ *current = head;

    if (current){
        if (isLast(current)){
            delLast(current);
        }
        else {
            delHead(current);
        }
        deleted = true;
    }

    return deleted;
}

bool Queue::delHead(Node_ *current){
    current->next->prev = NULL;
    head = current->next;
    delete current;
    current= NULL;
    return true;
}

bool Queue::isLast(Node_ *current){
    bool isLast = false;
    if (current->next == NULL && current->prev == NULL){
        isLast = true;
    }
    return isLast;
}
bool Queue::delLast(Node_ *current){
    delete current;
    current = NULL;
    head = NULL;
    return true;
}
bool Queue::clearList() {
    bool cleared = false;
    Node_ *current;
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


void Queue::printList(bool backward) {
  Node_ *current = new Node_;
  current = head;
  int count = 0;
  if (!backward) {
    //this is the print function used in the hashtable print list for each linked list
    while (current) {
      cout << current->data.id << " <- ";
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
int Queue::getCount() {
  Node_ *current = head;
  int count = 0;
    while (current) {
      count++;
      current = current->next;
    }
  return count;
}

bool Queue::isEmpty(){
  bool empty = false;
  Node_ *current = head;
  if (current == NULL){
    empty = true;
    tail = nullptr;
  }
  return empty;
}

Node_* Queue::getHead(){
    return head;
}
