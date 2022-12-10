#include "data.h"
#include <iostream>

using std::cout;
using std::endl;

class LinkedList {

public:
  // constructor
  LinkedList();

  // destructor
  ~LinkedList();

  // getters
  Node* getHead();
  bool getNode(int, Data *);
  int getCount();
  void printList(bool = false);
  bool exists(int);
  bool isEmpty();


  // setters
  bool addNode(int, string *);
  bool deleteNode(int);
  bool clearList();

private:
  // attributes
  Node *head;
  Node *tail;

  // helper methods
  bool addHead(Node*);
  bool delHead(Node*);
  bool addTail(Node*, Node *);
  bool delTail(Node*);
  bool addMiddle(Node*, Node *);
  bool delMiddle(Node*);
  bool isLast(Node*);
  bool delLast(Node*);
  Node *createNode(int, string *); //make sure you dont call this from graph

};
