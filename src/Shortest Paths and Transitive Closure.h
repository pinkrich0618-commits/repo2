#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include "header.h"

class ShortestPath {
private:
    int V;
    vector<vector<pair<int,int>>> adj;

public:
    ShortestPath(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v,w});
    }

    void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
        pq.push({0,start});

        while(!pq.empty()){
            auto [d,u] = pq.top(); pq.pop();

            for(auto [v,w] : adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        for(int i=0;i<V;i++)
            cout << dist[i] << " ";
    }
};

#endif
