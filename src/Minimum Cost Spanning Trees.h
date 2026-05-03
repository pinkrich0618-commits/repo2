#ifndef MST_H
#define MST_H

#include "header.h"

class MST {
private:
    int V;
    vector<tuple<int,int,int>> edges;

public:
    MST(int v) { V = v; }

    void addEdge(int u, int v, int w) {
        edges.push_back({w,u,v});
    }

    void kruskal() {
        sort(edges.begin(), edges.end());
        int total = 0;

        for(auto [w,u,v] : edges){
            total += w;
        }

        cout << "MST cost: " << total << endl;
    }
};

#endif
