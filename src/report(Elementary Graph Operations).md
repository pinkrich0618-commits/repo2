# 41343106

作業二：Elementary Graph Operations


## 解題說明

本題實作 DFS 與 BFS 圖搜尋演算法。

### 解題策略

1. DFS 使用 stack（或遞迴）
2. BFS 使用 queue
3. 記錄 visited 避免重複走訪
---

## 程式實作

```cpp
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
```

## 效能分析
1. 時間複雜度：$O(V + E)$
 
2. 空間複雜度：$O(V)$

## 測試與驗證

測試程式
```cpp
#include "Elementary Graph Operations.h"

int main() {
    GraphTraversal g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,3);

    g.DFS(0);
    cout << endl;
    g.BFS(0);
}
```

## 測試結果

DFS: 0 2 1 3


BFS: 0 1 2 3

## 申論及開發報告


DFS 適合探索整個圖結構，BFS 適合最短路徑問題（無權重）。
