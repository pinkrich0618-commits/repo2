#ifndef MST_H
#define MST_H

#include "header.h"

class MST {
private:
    int V;
    vector<tuple<int, int, int>> edges;
    vector<int> parent;

    // Union-Find: 尋找根節點（含路徑壓縮優化）
    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    // Union-Find: 合併集合
    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) parent[root_i] = root_j;
    }

public:
    MST(int v) : V(v) {
        parent.resize(V);
        for (int i = 0; i < V; i++) parent[i] = i;
    }

    void addEdge(int u, int v, int w) {
        edges.push_back({w, u, v});
    }

    void kruskal() {
        // 1. 將所有邊依權重排序 - O(E log E)
        sort(edges.begin(), edges.end());
        
        int total = 0;
        int edgesCount = 0;

        cout << "Edges in MST:" << endl;
        for (auto [w, u, v] : edges) {
            // 2. 透過 Union-Find 檢查是否形成環
            if (find(u) != find(v)) {
                unite(u, v);
                total += w;
                edgesCount++;
                cout << u << " - " << v << " : " << w << endl;
            }
            if (edgesCount == V - 1) break; // 已找足夠的邊
        }

        cout << "Total MST cost: " << total << endl;
    }
};

#endif
