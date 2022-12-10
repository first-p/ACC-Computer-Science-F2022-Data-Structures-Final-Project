/**********************************************
Name: Fred Butoma
Final Project

Purpose: main.cpp is the test bed for the
undirected and unweighted graph class
**********************************************/

#include "main.h"
int main() {

    //random number generator using curring time
    srand(time(0));



    // CREATING A GRAPH BASED ON FOLLOWING IMAGE //
    cout << "creating a graph based on following image: " << endl;
    cout << endl;
    cout << "(1)---(2)---(3)---(4)" <<endl;
    cout << " |     |           | " << endl;
    cout << " |     |           | " << endl;
    cout << "(5)---(6)         (7)---(11)" <<endl;
    cout << "       |           | " << endl;
    cout << " (8)--(9)        (10)"  <<endl;

    cout <<endl;

        //parallell lists for vertex and its assciated edges
    vector<int> vertexList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    vector<vector<int>> edgeList = {{2,5}, {1,3,6}, {2, 4}, {3,7}, {1, 6}, {2, 5, 9}, {4, 10, 11}, {9}, {6,8}, {7}, {7}};

    cout << "Generating test data" << endl;

    cout << "Generating test data" << endl;
    cout << "=============================================================" << endl;
    cout << "                       TEST DATA" << endl;
    cout << "=============================================================" << endl;
    cout << " VERTEX: EDGES" << endl;
    int edgeCount=0;

    for (int i = 0 ; i < vertexList.size(); i++){
        cout << "      " << vertexList[i] << ": ";
        for (int j = 0; j < edgeList[i].size(); j++){
            cout << edgeList[i][j];
            if (edgeList[i][j+1]){
                cout << ", ";
                edgeCount++;
            }
        }
        cout << endl;
    }
    cout << "vertex count: " << vertexList.size() << endl;
    cout << "edge count: " << edgeCount << endl;
    cout << "=============================================================" << endl;
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

    // DEPTH-FIRST TRAVERSAL //
    cout << "Depth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseDepthFirst(vertexList[0]);

    // BREADTH-FIRST TRAVERSAL //
    cout << "Breadth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseBreadthFirst(vertexList[0]);


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

   // ADD EDGES TO GRAPH THAT HAS NO VERTICES//
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
        cout <<endl;
     }
    g1.displayAdjacencyList();


    // ADD VERTICES THEN EDGES TO EMPTY GRAPH //
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
        cout <<endl;
     }
    g1.displayAdjacencyList();

    cout<<endl;

    // TRAVERSALS //

    // DEPTH-FIRST TRAVERSAL //
    cout << "DEPTH-FIRST TRAVERSAL" << endl;
    cout << "Depth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseDepthFirst(vertexList[0]);
    cout<<endl;
    cout << "Depth-first Traversal Starting at " << vertexList[2] << endl;
    g1.traverseDepthFirst(vertexList[2]);
    cout<<endl;
    cout << "Depth-first Traversal Starting at " << vertexList[4] << endl;
    g1.traverseDepthFirst(vertexList[4]);
    cout<<endl;
    cout << "Depth-first Traversal Starting at " << vertexList[9] << endl;
    g1.traverseDepthFirst(vertexList[9]);

    g1.displayAdjacencyList();
    cout << endl;

    // BREADTH-FIRST TRAVERSAL //
    cout << "BREADTH-FIRST TRAVERSAL" << endl;
    cout << "Breadth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseBreadthFirst(vertexList[0]);
    cout<<endl;
    cout << "Breadth-first Traversal Starting at " << vertexList[2] << endl;
    g1.traverseBreadthFirst(vertexList[2]);
    cout<<endl;
    cout << "Breadth-first Traversal Starting at " << vertexList[4] << endl;
    g1.traverseBreadthFirst(vertexList[4]);
    cout<<endl;
    cout << "Breadth-first Traversal Starting at " << vertexList[9] << endl;
    g1.traverseBreadthFirst(vertexList[9]);





    //    REMOVE EDGES AND ADD THEM BACK  //

   cout << "removing all edges from " << edgeList.size() << " vertices" << endl;

   for (int i = 0 ; i < edgeList.size(); i++){
       cout << "->removing " << edgeList[i].size() << " edges from vertex " << vertexList[i] << endl;
       for (int j = 0; j < edgeList[i].size(); j++){
           if (g1.removeEdge(vertexList[i], edgeList[i][j])){
               cout << "removing " << edgeList[i][j] << ": ..success" << endl;
           }
           else {
               cout << "removing " << edgeList[i][j] << ": ..fail" << endl;
           }
       }
       cout <<endl;
       g1.displayAdjacencyList();
    }
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
        cout <<endl;
     }
    g1.displayAdjacencyList();

    // DEPTH-FIRST TRAVERSAL //
    cout << "Depth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseDepthFirst(vertexList[0]);

    // BREADTH-FIRST TRAVERSAL //
    cout << "Breadth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseBreadthFirst(vertexList[0]);


    // ADDING VERTICES THAT ALREADY EXIST //
    cout << "Adding vertices that already exist in graph.." << endl;
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

     // ADDING EDGES THAT ALREADY EXIST //
    cout << "adding edges that already exist in graph.." << endl;

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
       cout <<endl;
    }
   g1.displayAdjacencyList();
   cout<<endl;

   // ADDING INVALID VERTICES //
   cout << "adding invalid vertices to graph.." << endl;
   for (int i = 0; i > -5; i--){
       string data = std::to_string(i);

       if (g1.addVertex(i)){
           cout << "adding " << i << ": ..success" << endl;
       }
       else {
           cout << "adding " << i << ": ..fail" << endl;
       }
  }
   cout<<endl;


   // ADDING INVALID EDGES //
   cout << "adding invalid edges to graph.." << endl;
   for (int i = 0; i < vertexList.size(); i++){
       for (int j = 0; j > -2; j--){

               if (g1.addEdge(vertexList[i], j)){
                   cout << "adding " << j << " to " << "vertex: "<< vertexList[i] << ": ..success" << endl;
               }
               else {
                   cout << "adding " << j << " to " << "vertex: "<< vertexList[i] << ": ..fail" << endl;
               }
         }
    }
   g1.displayAdjacencyList();
   cout<<endl;








    cout << "*********************************" << endl;
    cout << "       RANDOM OPERATIONS" << endl;
    cout << "*********************************" << endl;
    cout << "randomly adding/removing vectors and edges " << endl;
    cout << "adding vertex/edges 3 times more" << endl;
    cout << endl;


    int randNum1 = rand() % 5 + 5;
    int randNum2 = rand() % 5 + 5;

    int choice = rand()  % 8 + 1;

    for (int i = 0 ; i < OPERATIONS; i++){
        switch(choice){
        case 1:
            cout << "adding vertex: " << randNum1 << endl;
            if (g1.addVertex(randNum1)){
                cout << "adding " << randNum1 << ": ..success" << endl;
            }
            else {
                cout << "adding " << randNum1 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        case 2:
            cout << "adding vertex: " << randNum1 << endl;
            if (g1.addVertex(randNum1)){
                cout << "adding " << randNum1 << ": ..success" << endl;
            }
            else {
                cout << "adding " << randNum1 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        case 3:
            cout << "adding vertex: " << randNum1 << endl;
            if (g1.addVertex(randNum1)){
                cout << "adding " << randNum1 << ": ..success" << endl;
            }
            else {
                cout << "adding " << randNum1 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        case 4:
            cout << "removing vertex: " << randNum1 << endl;
            if (g1.removeVertex(randNum1)){
                cout << "removing " << randNum1 << ": ..success" << endl;
            }
            else {
                cout << "removing " << randNum1 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        case 5:
            cout << "adding edge: " << randNum2 << " to vertex: " << randNum1 << endl;
            if (g1.addEdge(randNum1,randNum2)){
                cout << "adding " << randNum2 << ": ..success" << endl;
            }
            else {
                cout << "adding " << randNum2 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        case 6:
            cout << "adding edge: " << randNum2 << " to vertex: " << randNum1 << endl;
            if (g1.addEdge(randNum1,randNum2)){
                cout << "adding " << randNum2 << ": ..success" << endl;
            }
            else {
                cout << "adding " << randNum2 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        case 7:
            cout << "adding edge: " << randNum2 << " to vertex: " << randNum1 << endl;
            if (g1.addEdge(randNum1,randNum2)){
                cout << "adding " << randNum2 << ": ..success" << endl;
            }
            else {
                cout << "adding " << randNum2 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        case 8:
            cout << "removing edge: " << randNum2 << " from vertex: " << randNum1 << endl;
            if (g1.removeEdge(randNum1, randNum2)){
                cout << "removing " << randNum2 << ": ..success" << endl;
            }
            else {
                cout << "removing " << randNum2 << ": ..fail" << endl;
            }
            g1.displayAdjacencyList();
            cout << endl;
            break;
        }
        choice = rand() % 8 + 1;
        randNum1 = rand() % 5 + 5;
        randNum2 = rand() % 5 + 5;
    }

    g1.displayAdjacencyList();

    // DEPTH-FIRST TRAVERSAL //
    cout << "Depth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseDepthFirst(vertexList[0]);

    // BREADTH-FIRST TRAVERSAL //
    cout << "Breadth-first Traversal Starting at " << vertexList[0] << endl;
    g1.traverseBreadthFirst(vertexList[0]);
    cout <<endl;

    // CLEARING GRAPH //
    cout << "clearing graph..";
    if (g1.clearGraph()){
        cout <<"..sucess"<< endl;
    }
    else {
        cout << "..fail" << endl;
    }
    cout << endl;
    g1.displayAdjacencyList();

//    // CREATING A GRAPH BASED ON FOLLOWING IMAGE //
//    cout << "creating a graph based on following image: " << endl;
//    cout << endl;
//    cout << "(1)---(2)---(3)---(4)" <<endl;
//    cout << " |     |           | " << endl;
//    cout << " |     |           | " << endl;
//    cout << "(5)---(6)         (7)---(11)" <<endl;
//    cout << "       |           | " << endl;
//    cout << " (8)--(9)        (10)"  <<endl;

//    cout <<endl;
//    vector<int> vertexList = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

//    vector<vector<int>> edgeList = {{2,5}, {1,3,6}, {2, 4}, {3,7}, {1, 6}, {2, 5, 9}, {4, 10, 11}, {9}, {6,8}, {7}, {7}};

//    cout << "Generating test data" << endl;
//    cout << "=============================================================" << endl;
//    cout << "                       TEST DATA" << endl;
//    cout << "=============================================================" << endl;
//    cout << " VERTEX: EDGES" << endl;
//    edgeCount=0;

//    for (int i = 0 ; i < vertexList2.size(); i++){
//        cout << "      " << vertexList2[i] << ": ";
//        for (int j = 0; j < edgeList2[i].size(); j++){
//            cout << edgeList2[i][j];
//                cout << " ";
//                edgeCount++;
//            }
//        cout << endl;
//    }
//    cout << "vertex count: " << vertexList2.size() << endl;
//    cout << "edge count: " << edgeCount << endl;
//    cout << "=============================================================" << endl;
//    cout << endl;
//    cout << "printing empty graph"<<endl;
//    cout <<endl;

//    // ADD VERTICES THEN EDGES TO EMPTY GRAPH //
//    cout << "Adding vertices to graph.." << endl;
//    for (int i = 0 ; i < vertexList2.size(); i++){
//         string data = std::to_string(vertexList2[i]);
//         if (g1.addVertex(vertexList2[i])){
//             cout << "adding " << vertexList2[i] << ": ..success" << endl;
//         }
//         else {
//             cout << "adding " << vertexList2[i] << ": ..fail" << endl;
//         }
//     }
//    cout << endl;

//    cout << "Printing adjacency list.." << endl;
//    g1.displayAdjacencyList();
//    cout << endl;
//    cout << "adding edges to " << edgeList2.size() << " vertices" << endl;

//    for (int i = 0 ; i < edgeList2.size(); i++){
//        cout << "->adding " << edgeList2[i].size() << " edges to vertex " << vertexList[i] << endl;
//        for (int j = 0; j < edgeList2[i].size(); j++){
//            string data = std::to_string(edgeList2[i][j]);
//            if (g1.addEdge(vertexList2[i], edgeList2[i][j])){
//                cout << "adding " << edgeList2[i][j] << ": ..success" << endl;
//            }
//            else {
//                cout << "adding " << edgeList2[i][j] << ": ..fail" << endl;
//            }
//        }
//        cout <<endl;
//     }
//    g1.displayAdjacencyList();

//    // DEPTH-FIRST TRAVERSAL //
//    cout << "Depth-first Traversal Starting at " << vertexList2[0] << endl;
//    g1.traverseDepthFirst(vertexList2[0]);

//    // BREADTH-FIRST TRAVERSAL //
//    cout << "Breadth-first Traversal Starting at " << vertexList2[0] << endl;
//    g1.traverseBreadthFirst(vertexList2[0]);


    return 0;
}
