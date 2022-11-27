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

#include "graph.h"

Graph::Graph(vector<vector<int>> edgeList) {
    Hashtable h1;
    for (int i = 0; i < edgeList.size(); i++){
        int vectorId = edgeList[i][0];
        string vectorData = std::to_string(vectorId);

        h1.insertEntry(vectorId, &vectorData);
    }
    h1.printTable();
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




