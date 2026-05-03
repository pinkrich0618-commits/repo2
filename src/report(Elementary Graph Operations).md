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


### 1. 演算法設計原理與實作細節在本次作業中，我針對圖的兩大基本走訪演算法進行了實作：
  
  ##### 深度優先搜尋 (DFS)：
  核心機制： 採用「後進先出」(LIFO) 的特性，本程式使用 std::stack 來模擬遞迴行為。
  
  走訪策略： 演算法會盡可能沿著一條路徑深入，直到無法前進後才回溯。在實作中，將相鄰節點推入 Stack，確保了搜尋的「深度」優先權。
  ##### 廣度優先搜尋 (BFS)：
  核心機制： 採用「先進先出」(FIFO) 的特性，利用 std::queue 來管理待訪問節點。
  
  走訪策略： 以起點為中心，逐層向外擴散。這種「層級走訪」的特性，確保了在無權重圖中，第一次找到目標節點的路徑必定是最短路徑。

 ### 2.關鍵技術：走訪狀態管理
 為了避免圖中可能存在的「環」(Cycle) 導致程式陷入無窮迴圈，我使用了 vector<bool> visited 陣列來記錄每個頂點的狀態：
 
 這將空間複雜度控制在 $O(V)$，因為每個頂點僅會被標記一次。
 
 在 BFS 中，節點在入隊 (push) 時即標記為已訪問，能有效防止同一個節點被多次加入隊列，優化執行效率。

  ### 3.效能與空間權衡 (Trade-off)
  時間複雜度：兩種演算法皆需走訪所有頂點 $V$ 與邊 $E$，因此時間複雜度均為 $O(V + E)$。這在處理大規模稀疏圖時展現了極佳的線性效率。
  
  空間複雜度： 主要消耗在 visited 陣列與輔助容器 (Stack/Queue) 上，總體為 $O(V)$。
  
  實作觀察：非遞迴式的 DFS 避免了在圖過深時可能發生的「堆疊溢位」(Stack Overflow) 風險。使用 std::vector<vector<int>> 的鄰接表結構，使得獲取鄰居節點的時間與節點度數 (Degree) 成正比，比鄰接矩陣的 $O(V)$ 更有效率。
