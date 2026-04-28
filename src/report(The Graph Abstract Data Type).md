# 41343106

作業二：The Graph Abstract Data Type


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

## 效能分析
1. 時間複雜度：
   加邊：$O(1)$

   印出圖：$O(V + E)$
3. 空間複雜度：
   $O(V + E)$

## 測試與驗證

測試程式
```cpp
#include "The Graph Abstract Data Type.h"

int main() {
    GraphADT g(3);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.printGraph();
}
```

## 測試結果

0:  1

1:  0 2

2:  1

## 申論及開發報告

##### 資料結構選型與優勢分析
在實作 Graph ADT 時，最常見的兩種方式是 Adjacency Matrix（鄰接矩陣） 與 Adjacency List（鄰接表）。
本程式選擇後者，主要考量如下：

-空間效率： 對於頂點數 $V$ 很多但邊數 $E$ 較少的「稀疏圖（Sparse Graph）」，鄰接矩陣會浪費 $O(V^2)$ 的空間來儲存大量的 0；而鄰接表僅需 $O(V + E)$，能大幅節省記憶體。

-動態擴展性:使用 std::vector 實作，可以方便地處理每個頂點連接數不一的情況，且在 C++ 中 vector 的記憶體連續性對快取（Cache）也較為友善。
##### 開發實作細節

說明在實作過程中，我採用了物件導向（OOP）的封裝原則：

封裝性：

將鄰接表 adj 設為 private，確保外部程式無法直接竄改內部資料結構，僅能透過 addEdge 等公開介面進行操作。

無向圖實作：

由於題目未指定為有向圖，本程式在 addEdge 中同時對 u 和 v 的列表進行更新，確保了邊的雙向性。
##### 效能表現與瓶頸

優點:查詢某個頂點的所有鄰居非常快速，時間複雜度為 $O(\text{degree}(v))$。

缺點： 若要檢查特定兩點 $(u, v)$ 是否存在邊，鄰接表需要遍歷整個 adj[u] 列表，最差情況需 $O(V)$；若使用鄰接矩陣則僅需 $O(1)$。
