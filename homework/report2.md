# 作業二 — Binary Search Tree 實驗與刪除

> **學號：** 41243220 41243236  


---

## 一、解題說明
**(a) 隨機高度實驗**  
* 由空樹插入 `n` 個隨機鍵，量測高度 `h`，計算  
  \( ratio = h / \log_2 n \)。  
* 取樣 `n = 100, 500, …, 10\,000`，理論上 `ratio` 應趨近常數 \(c≈2\)。

**(b) `Delete(key)`**  
* 分三種情形實作：葉節點、單子節點、雙子節點（以右子樹最小值替換）。

---

## 二、程式實作
> 參見 `AllPrograms.cpp` 之 `BST` 類別。主要函式摘要：

```cpp
// (b) Delete — O(h)
Node* erase(Node* n,int k){
    if(!n) return nullptr;
    if(k<n->k) n->l = erase(n->l,k);
    else if(k>n->k) n->r = erase(n->r,k);
    else {
        if(!n->l || !n->r){            // 0 或 1 子
            Node* t = n->l? n->l:n->r;
            delete n; return t;
        }
        Node* succ = minNode(n->r);    // 2 子
        n->k = succ->k;
        n->r = erase(n->r,succ->k);
    }
    return n;
}
```

---

## 三、效能分析
| 操作 | 平均 | 最壞 | 說明 |
|------|-------|-------|------|
| Insert | \(O(\log n)\) | \(O(n)\) | 高度 = \(h\) |
| Delete | \(O(\log n)\) | \(O(n)\) | 同上 |
| Search | \(O(\log n)\) | \(O(n)\) | — |

> 在隨機鍵下 \(h ≈ 1.39 \log_2 n\)，故 `ratio` 理論值 ≈ 1.4–2。

---

## 四、測試與驗證
* **自動實驗**：程式輸出 `n,height,ratio` CSV，可用 Python 畫折線圖。  
* **結果**：`ratio` 分佈 1.6–2.2，符合理論常數。  
* **刪除測試**：插入 `{50,20,75,10,30,60,80}` → `Delete(50)`，新高度由 3→3；以 `isBST` 檢查結構仍合法。

---

## 五、申論及開發報告
* 若需保證最壞 \(O(\log n)\)，可改 AVL／Red‑Black 樹。  
* 程式以遞迴實作，代碼簡潔；若資料量極大可改非遞迴以避免堆疊溢位。

---

## 六、結論
深入理解 BST 刪除三情境 與中序後繼替換技巧。
親自量測證實高度 (~c\log n)\ 條件，強化理論與實務連結。
了解資料結構在平均與最壞情況的差異，並評估何時需要自平衡樹。




