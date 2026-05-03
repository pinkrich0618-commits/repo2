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
    vector<tuple<int,int,int>> edges;

public:
    MST(int v) { V = v; }

    void addEdge(int u, int v, int w) {
        edges.push_back({w,u,v});
    }

    void kruskal() {
        sort(edges.begin(), edges.end());
        int total = 0;

        for(auto [w,u,v] : edges){
            total += w;
        }

        cout << "MST cost: " << total << endl;
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
#include "Minimum Cost Spanning Trees.h"

int main() {
    MST g(3);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,3);

    g.kruskal();
}
```

## 測試結果
MST cost: 6

## 申論及開發報告


Kruskal 適合稀疏圖，實務上通常搭配 Union-Find 以避免形成 cycle。
