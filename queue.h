// ****************************************
// Fred Butoma
// Challenge 2 part 1

// purpose: Queue class header file
//  ****************************************

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include <iostream>

using std::cout;
using std::endl;
using std::string;

struct Data_{
    int id;
    string data;
};

struct Node_ {
    Data_ data;
    Node_ *next;
    Node_ *prev;
};

class Queue {

public:
  // constructor
  Queue();

  // destructor
  ~Queue();

  // getters
  Node_* getHead();
  bool getNode(int, Data_ *);
  void printList(bool = false);
  int getCount();
  bool exists(int);


  bool push(int, string *);
  bool pull();
  bool peek(Node_ *);
  bool isEmpty();

  // setters
  bool addNode(int, string *);
  bool deleteNode(int);
  bool clearList();

private:
  // attributes
  Node_ *head;
  Node_ *tail;

  // helper methods
  bool addHead(Node_*);
  bool delHead(Node_*);
  bool addTail(Node_*, Node_ *);
  bool delTail(Node_*);
  bool addMiddle(Node_*, Node_ *);
  bool delMiddle(Node_*);
  bool isLast(Node_*);
  bool delLast(Node_*);
  Node_ *createNode(int, string *);
};

#endif // LINKED_LIST_H

