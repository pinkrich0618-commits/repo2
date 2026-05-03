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
void dijkstra(int start) {
        vector<int> dist(V, INT_MAX);
        dist[start] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();

            // 效能優化：若當前彈出的距離已非最優，則跳過處理
            if (d > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        // ...其餘列印邏輯...
    }
```

## 測試結果
0 1 3

## 申論及開發報告

### 1. 演算法設計與貪婪策略

Dijkstra 演算法是處理單源最短路徑 (SSSP) 的標竿演算法，其核心思想基於貪婪策略 (Greedy Approach)：

最佳子結構：每次從優先隊列中取出距離起點最近的節點，並假設該路徑已是最短。

鬆弛操作 (Relaxation)： 透過新加入的節點嘗試更新其鄰居的距離。若經由目前節點 $u$ 到達 $v$ 的路徑比已知路徑短，則更新 $dist[v]$。

### 2. 優先隊列 (Priority Queue) 的關鍵角色

在實作中，使用 std::priority_queue 搭配 greater<> 實作了 Min-Priority Queue：

相較於傳統使用 $O(V)$ 遍歷尋找最小距離頂點的方法，優先隊列將選取最小節點的時間降低至 $O(\log V)$。

這使得演算法在處理如城市地圖、網路路由等具有大量邊的圖形時，能保持 $O(E \log V)$ 的高效能表現。
### 3. 限制條件與 Transitive Closure 的關聯
負權邊限制： Dijkstra 無法處理具有「負權邊」的圖。若圖中存在負權，應改用 Bellman-Ford 或 SPFA 演算法。

Transitive Closure (遞移閉包)： 本題標題提及遞移閉包。雖然 Dijkstra 處理權重路徑，但遞移閉包關注的是「節點間的可達性」。若要計算遞移閉包，通常使用 Floyd-Warshall 演算法（時間複雜度 $O(V^3)$），或對每個節點執行一次 BFS/DFS。在加權圖中，若兩點間存在最短路徑且距離不為 INT_MAX，則代表這兩點在遞移閉包中是連通的。
