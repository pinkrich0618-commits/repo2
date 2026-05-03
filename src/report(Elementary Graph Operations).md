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
