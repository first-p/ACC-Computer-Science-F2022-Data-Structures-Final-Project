/************************************
Name: Fred Butoma
Final Project

Purpose: data.h is an abstract 
data type used for to define vectors 
in the graph class 
************************************/
 #ifndef DATA_H
 #define DATA_H

#include "string"
 using std::string;

 struct Data {
     int id;
     string data;
     bool visited;
 };

 struct Node {
     Data data;
     Node *next;
     Node *prev;
 };

 #endif /* DATA_H */