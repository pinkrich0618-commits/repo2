#ifndef GRAPH_ADT_H
#define GRAPH_ADT_H

#include "header.h"

class GraphADT {
private:
    int V;
    vector<vector<int>> adj;

public:
    GraphADT(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printGraph() {
        for(int i=0;i<V;i++){
            cout << i << ": ";
            for(int j : adj[i])
                cout << j << " ";
            cout << endl;
        }
    }
};

#endif
