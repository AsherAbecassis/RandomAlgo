

//
//  main.cpp
//  randomeAlgo
//
//  Created by Asher Abekasis on 31/03/2021.
//

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <random>
#include <time.h>
#include <list>
#include <queue>
using namespace::std;


vector<vector<int>> build_random_graph(float p, int v)
{

    //allocate dynamic matrix with size v*v
    vector<vector<int>> mat(v);
    for (int i = 0; i < v; i++)
        mat[i].resize(v);


    int tempP = p * 100; //multiply the probability to get valid number between 1 to 100
    srand(time(0)); //to generate new random numbers with each run

    for (int i = 0; i < v; i++)
    {
        for (int j = i + 1; j < v; j++)
        {
            int num = rand() % 100 + 1; //generate numbers between 1 to 100
            if (num <= tempP)
            {
                mat[i][j] = 1; //1 mean that vertex are connected both ways
                mat[j][i] = 1;
            }
        }
    }
    //print the Graph
    for (int i = 0; i < v; i++)
    {
        cout << " " << i + 1 << " => [";
        for (int j = 0; j < v; j++)
        {


            if (mat[i][j] != 0)
            {
                cout << " " << j + 1 << " ";
            }
        }

        cout << "]\n";
    }



    cout << "\n";
    for (int i = 0; i < v; i++)
    {

        for (int j = 0; j < v; j++)
        {
            cout << mat[i][j] << " ";

        }
        cout << "\n";
    }




    return mat;
}

bool is_isolated(vector<vector<int>> graph)
{
    int sum = 0;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++)
        {
            sum += graph[i][j];
        }
        if (sum == 0)
        {
            return true;
        }
        sum = 0;
    }

    //cout<<n<<"\n";
    return false;

}
bool connectivity(vector<vector<int>> randomGraph)
{
    bool n = is_isolated(randomGraph);
    if (n)
    {
        cout << "graph is not connected " << endl;

        return false;
    }
    cout << "graph is conected  " << endl;
    return true;

}

int BFS(vector<vector<int>> graph,int v) {
    vector<int> distance(graph.size());
    queue<int> a;
    vector<bool> visited(graph.size());
    for (int k = 0; k < graph.size(); k++) {
        visited[k] = false;
    }
    a.push(v);
    distance[v] = 0;
    visited[v] = true;
    while (!a.empty()) {
        for (int i = 0; i < graph.size(); i++) {
            if (graph[v][i] == 1 && visited[i] == false) {
                a.push(i);
                distance[i] = distance[a.front()] + 1;
                visited[i] = true;
            }
        }
        a.pop();
        if (!a.empty()) {
            v = a.front();
        }
    }
    return distance[v];
}

int diameter(vector<vector<int>> graph) {
    if (connectivity(graph)) {
        int max = 0;
        int diam = 0;
        for (int i = 0; i < graph.size(); i++) {
            diam = BFS(graph, i);
            if (diam > max) {
                max = diam;
            }
        }
        return max;
    }
    return INT_MAX;
}

int main()
{
    vector<vector<int>> randomGraph = build_random_graph(0.5, 6);
    //bool n = connectivity(randomGraph);
    cout<<"diam is: "<<diameter(randomGraph)<<endl;
    return  0;
}

