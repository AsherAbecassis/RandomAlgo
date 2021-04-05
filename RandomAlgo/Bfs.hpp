//
//  Bfs.hpp
//  RandomAlgo
//
//  Created by Asher Abekasis on 01/04/2021.
//

#ifndef Bfs_hpp
#define Bfs_hpp

#include <stdio.h>


class Graph {
 
    // Number of vertex
    int v;
 
    // Number of edges
    int e;
 
    // Adjacency matrix
    int** adj;
 
public:
    // To create the initial adjacency matrix
    Graph(int v, int e);
 
    // Function to insert a new edge
    void addEdge(int start, int e);
 
    // Function to display the BFS traversal
    void BFS(int start);
};




#endif /* Bfs_hpp */
