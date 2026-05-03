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

拓樸排序應用於工作排程與專案管理（PERT/CPM），可找出執行順序。
