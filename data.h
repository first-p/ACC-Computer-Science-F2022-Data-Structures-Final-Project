/************************************
Name: Fred Butoma
Final Project

Purpose: data.h is a struct used by the
linked list in the form of nodes, and uses 
linked lists as a part of a node in of
itself
************************************/

#include <vector>
#include <string>

using std::string;
using std::vector;

class LinkedList;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next;
    Node *prev;
    LinkedList *edgeList;
};
