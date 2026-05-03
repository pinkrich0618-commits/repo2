# 41343106

作業二：Minimum Cost Spanning Trees


## 解題說明

本題實作 Kruskal 演算法求最小生成樹。

### 解題策略

1.將所有邊依權重排序

2.逐條選擇最小邊

3.累加權重

## 程式實作

```cpp
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
```

## 效能分析
1. 時間複雜度：$O(E \log E)$ 或 $O(E \log V)$

主要的效能瓶頸在於對 $E$ 條邊進行排序。

Union-Find 的操作（路徑壓縮）接近常數時間 $\alpha(V)$。


2. 空間複雜度：$O(V + E)$

 需儲存所有邊以及 Union-Find 的 parent 陣列。

## 測試與驗證

測試程式
```cpp
##include "Minimum Cost Spanning Trees.h"
#include <iostream>

using namespace std;

int main() {
    // 建立一個包含 3 個頂點的圖
    MST g(3);
    
    // 加入三條邊，形成一個三角形迴路
    g.addEdge(0, 1, 1); // 邊 0-1, 權重 1
    g.addEdge(1, 2, 2); // 邊 1-2, 權重 2
    g.addEdge(0, 2, 3); // 邊 0-2, 權重 3 (此邊應被跳過)

    cout << "--- Running Kruskal's Algorithm ---" << endl;
    g.kruskal();

    return 0;
}
```

## 測試結果
Edges in MST:

0 - 1 : 1

1 - 2 : 2

Total MST cost: 3

## 申論及開發報告
### 1. 演算法核心策略：貪婪思維
Kruskal 演算法是貪婪演算法的經典應用。其核心邏輯在於「局部最優解導致全域最優解」：

我們始終優先選擇權重最小的邊。

關鍵機制： 排序後的邊確保了成本最低的優先權，但為了保證最後結果是一棵「樹」（無環且連通），必須引入 Union-Find 資料結構進行連通性檢查。

### 2. Union-Find 的優化技術

在開發報告中，特別值得提到 路徑壓縮 (Path Compression) 的應用：

在 find 函式中，我們讓節點直接指向根節點。

這使得後續的查詢操作近乎 $O(1)$，確保了當圖的規模擴大到數萬個頂點時，演算法依然能保持極高的效率。這在處理大型網路拓撲或電路設計佈線時至關重要。
### 3. Kruskal vs. Prim 的權衡 (Trade-off)

在實作過程中，我考量了與 Prim 演算法的差異：

Kruskal：適合「邊數較少」的 稀疏圖 (Sparse Graph)，因為其複雜度受邊數排序主導。

Prim： 則在 稠密圖 (Dense Graph) 或使用 Fibonacci Heap 時更具優勢。

鑑於大多數實務上的網路地圖（如道路網）皆屬稀疏圖，Kruskal 搭配 Adjacency List 是更具泛用性的選擇。

