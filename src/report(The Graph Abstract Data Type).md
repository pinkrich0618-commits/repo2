# 41343106

作業二：Graph Algorithms


## 解題說明

本題實作圖的抽象資料型態（Graph ADT），並使用 adjacency list 表示圖的結構。

### 解題策略

1. 使用 vector 建立 adjacency list  
2. 每個節點儲存其相鄰節點  
3. 提供 addEdge() 與 printGraph() 操作  

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

##效能分析
1.時間複雜度：
加邊：$O(1)$
印出圖：$O(V + E)$
2.空間複雜度：
$O(V + E)$

## 測試與驗證

##測試程式
```cpp
#include "graph_adt.h"

int main() {
    GraphADT g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.printGraph();
}
```

##測試結果

0: 1
1: 0 2
2: 1

##申論及開發報告

使用 adjacency list 可有效節省空間，特別適用於稀疏圖，相較於 adjacency matrix 更具彈性。
