# 41343106

作業二：Activity Networks


## 解題說明

本題實作拓樸排序（Topological Sort）。
### 解題策略
1.計算 indegree

2.將 indegree = 0 節點加入 queue

3.依序移除並更新
---

## 程式實作

```cpp
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
```

## 效能分析
1. 時間複雜度：$O(V + E)$
 
2. 空間複雜度：$O(V)$

## 測試與驗證

測試程式
```cpp
#include "Activity Networks.h"

int main() {
    ActivityNetwork g(4);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(0,3);

    g.topologicalSort();
}

#endif
```

## 測試結果
0 1 3 2
## 申論及開發報告

### 1. AOV 網路與拓樸排序的關聯
在本實作中，我們將專案建模為 AOV 網路 (Activity On Vertex Network)。這是一種 DAG (有向無環圖)，頂點代表任務，有向邊則代表任務間的「先決條件」。拓樸排序的本質，就是將這些偏序關係 (Partial Order) 轉換為一條合法的線性執行鏈。

### 2. 在 PERT/CPM 中的實務應用
拓樸排序是專案管理兩大技術 —— PERT (計畫評核術) 與 CPM (關鍵路徑法) 的邏輯基石：

執行順序規劃： 透過排序找出哪些任務可以並行（如測試結果中的 1 與 3），哪些必須序列執行。

尋找關鍵路徑： 在產出拓樸序列後，我們可以進一步計算每個任務的「最早開始時間」與「最晚開始時間」。那些沒有緩衝時間（Slack Time）的任務路徑即為關鍵路徑，直接決定了整個專案的完工日期。

### 3. 開發挑戰：循環相依 (Circular Dependency)
在開發過程中，最需防範的是「循環相依」。例如：任務 A 依賴 B，B 依賴 C，而 C 又依賴 A。在這種情況下，沒有任何節點的入度會歸零，演算法會提早結束。
