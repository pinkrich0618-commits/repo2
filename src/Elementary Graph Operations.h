#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H

#include "header.h"

class GraphTraversal {
private:
    int V;
    vector<vector<int>> adj;

public:
    GraphTraversal(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void DFS(int start) {
        vector<bool> visited(V,false);
        stack<int> s;
        s.push(start);

        while(!s.empty()){
            int v = s.top(); s.pop();
            if(!visited[v]){
                visited[v] = true;
                cout << v << " ";
                for(int u : adj[v])
                    s.push(u);
            }
        }
    }

    void BFS(int start) {
        vector<bool> visited(V,false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int v = q.front(); q.pop();
            cout << v << " ";

            for(int u : adj[v]){
                if(!visited[u]){
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

#endif
