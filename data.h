/**********************************************
Name: Fred Butoma
Final Project

Purpose: data.h is a header file that contains
the Node structure that linked lists are made of
**********************************************/

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
