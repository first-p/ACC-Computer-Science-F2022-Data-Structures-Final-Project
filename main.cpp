/**********************************************
Name: Fred Butoma
Final Project

Purpose: main.cpp is the test bed for the
undirected and unweighted graph class
**********************************************/

#include "main.h"
int main() {
    //parallell lists for vertex and its assciated edges
    vector<int> vertexList = {1, 2, 3, 4, 5, 6};
    //{{1,2}, {1,3}, {2,1}, {2,4}, {3,1}, {3,5}, {4,2}, {4,6}, {5,3}, {6, 4}};

    vector<vector<int>> edgeList = {{2,3}, {1,4}, {1,5}, {2,6}, {3}, {4}};
    //{{1,2}, {2,1}, {3,1}, {4,2}, {5,3}, {6, 4}};

    cout << "Generating test data" << endl;
    cout << "=============================================================" << endl;
    cout << "                       TEST DATA" << endl;
    cout << "=============================================================" << endl;
    cout << " VERTEX: EDGES" << endl;
    for (int i = 0 ; i < vertexList.size(); i++){
        cout << "      " << vertexList[i] << ": ";
        for (int j = 0; j < edgeList[i].size(); j++){
            cout << edgeList[i][j];
            if (edgeList[i][j+1]){
                cout << ", ";
            }
        }
        cout << endl;
    }
    cout << endl;


    cout << "Creating empty graph.."<< endl;
    Graph g1;


    cout << "Printing empty adjacency list.." << endl;
    g1.displayAdjacencyList();
    cout << endl;

    cout << "Adding vertices to graph.." << endl;
    for (int i = 0 ; i < vertexList.size(); i++){
         string data = std::to_string(vertexList[i]);
         if (g1.addVertex(vertexList[i])){
             cout << "adding " << vertexList[i] << ": ..success" << endl;
         }
         else {
             cout << "adding " << vertexList[i] << ": ..fail" << endl;
         }
     }
    cout << endl;

    cout << "Printing adjacency list.." << endl;
    g1.displayAdjacencyList();
    cout << endl;

    //    REMOVE VERTICES  //

   cout << "Removing vertices from graph.." << endl;
   for (int i = 0 ; i < vertexList.size(); i++){
        if (g1.removeVertex(vertexList[i])){
            cout << "removing " << vertexList[i] << ": ..success" << endl;
        }
        else {
            cout << "removing " << vertexList[i] << ": ..fail" << endl;
        }
   }
   cout << endl;

   cout << "Printing adjacency list.." << endl;
   g1.displayAdjacencyList();
   cout << endl;

    cout << "adding edges to " << edgeList.size() << " vertices" << endl;

    for (int i = 0 ; i < edgeList.size(); i++){
        cout << "->adding " << edgeList[i].size() << " edges to vertex " << vertexList[i] << endl;
        for (int j = 0; j < edgeList[i].size(); j++){
            string data = std::to_string(edgeList[i][j]);
            if (g1.addEdge(vertexList[i], edgeList[i][j])){
                cout << "adding " << edgeList[i][j] << ": ..success" << endl;
            }
            else {
                cout << "adding " << edgeList[i][j] << ": ..fail" << endl;
            }
        }
     }
    g1.displayAdjacencyList();

    //    REMOVE EDGES  //

   cout << "removing all edges from " << edgeList.size() << " vertices" << endl;

   for (int i = 0 ; i < edgeList.size(); i++){
       cout << "->removing " << edgeList[i].size() << " edges from vertex " << vertexList[i] << endl;
       for (int j = 0; j < edgeList[i].size(); j++){
           cout << "removing " << edgeList[i][j] << endl;
           if (g1.removeEdge(vertexList[i], edgeList[i][j])){
               cout << "removing " << edgeList[i][j] << ": ..success" << endl;
           }
           else {
               cout << "removing " << edgeList[i][j] << ": ..FAIL" << endl;
           }
       }g1.displayAdjacencyList();
    }
     













    return 0; 
}