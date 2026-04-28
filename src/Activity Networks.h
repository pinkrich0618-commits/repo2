#ifndef ACTIVITY_NETWORK_H
#define ACTIVITY_NETWORK_H

#include "header.h"

class ActivityNetwork {
private:
    int V;
    vector<vector<int>> adj;

public:
    ActivityNetwork(int v) {
        V = v;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topologicalSort() {
        vector<int> indegree(V,0);

        for(int i=0;i<V;i++)
            for(int v : adj[i])
                indegree[v]++;

        queue<int> q;

        for(int i=0;i<V;i++)
            if(indegree[i]==0)
                q.push(i);

        while(!q.empty()){
            int u = q.front(); q.pop();
            cout << u << " ";

            for(int v : adj[u]){
                if(--indegree[v] == 0)
                    q.push(v);
            }
        }
    }
};

#endif

