# 41343106

作業二：Shortest Paths and Transitive Closure


## 解題說明

本題使用 Dijkstra 演算法計算單源最短路徑。
### 解題策略

1.使用 priority queue

2.每次選擇距離最小節點

3.更新鄰居距離

## 程式實作

```cpp
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
```

## 效能分析
1. 時間複雜度：$O(E \log V)$

2.空間複雜度：$O(V)$

## 測試與驗證

測試程式
```cpp
#include "Shortest Paths and Transitive Closure.h"

int main() {
    ShortestPath g(3);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);

    g.dijkstra(0);
}
```

## 測試結果
0 1 3

## 申論及開發報告

Dijkstra 適用於非負權重圖，廣泛應用於導航與網路路徑規劃。
