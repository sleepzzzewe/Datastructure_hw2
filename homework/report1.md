# 作業一 — Max／Min Heap（Priority Queue ADT）

> **學號／組別：** 41243220 41243236  
> **語言：** C++17  
> **程式檔案：** `src/AllPrograms.cpp`（Section 1 `max_min_heap.cpp`）  

---

## 一、解題說明
* 以 **Binary Heap** 實現 Max 與 Min 兩種優先佇列。  
* `vector` 儲存完全二元樹；父節點 `i` 左子 `2i+1`、右子 `2i+2`。  
* **`MaxPQ` / `MinPQ`** 為抽象介面，定義 `IsEmpty / Top / Push / Pop` 四個操作。  
* **`MaxHeap`** 與 **`MinHeap`** 皆繼承各自介面，唯差異在比較方向（`<` 或 `>`）。

---

## 二、程式實作
> 詳見 **`AllPrograms.cpp`** 第 1 區塊，亦可獨立編譯 `max_min_heap.cpp`。以下列出關鍵函式：

```cpp
void Push(const T& v) {            // O(log n)
    h.push_back(v);                 // 插入尾端
    siftUp(h.size()-1);             // 逐層上浮
}

void Pop() {                        // O(log n)
    if (h.empty()) return;
    h[0] = h.back();                // 尾端搬到根
    h.pop_back();
    if (!h.empty()) siftDown(0);    // 逐層下沉
}
```

---

## 三、效能分析
| 操作 | 時間複雜度 | 空間 |
|------|------------|------|
| `Push` | \(O(\log n)\) | 常數 |
| `Pop`  | \(O(\log n)\) | 常數 |
| `Top`  | \(O(1)\)      | 常數 |
| `IsEmpty` | \(O(1)\)  | 常數 |

> 理論推導：完全二元樹高度 \(h = \lfloor\log_2 n\rfloor\)。`siftUp / siftDown` 最多移動 \(h\) 層。

---

## 四、測試與驗證
* **單元測試資料：** `int arr[]={7,3,9,1,5,2,8}`  
* **預期結果：** MaxHeap 以遞減序列輸出；MinHeap 以遞增序列輸出。  
* **實際輸出：**
  ```text
  MaxHeap: 9 8 7 5 3 2 1
  MinHeap: 1 2 3 5 7 8 9
  ```
* 另外以 `std::priority_queue` 交叉驗證 1e6 筆隨機資料，結果完全一致。

---

## 五、申論及開發報告
* **介面設計** 與課本 ADT 對齊，便於日後替換不同底層實作（如配對堆、斜堆）。  
* **Exception Safety**：若呼叫 `Top()` 時堆為空會丟出 `std::runtime_error`。  
* **擴充性**：可在模板中加入自訂 comparator，以支援自訂排序準則。

---

## 六、結論
透過實作 `MinPQ` / `MinHeap`，更加熟悉了：
1. **Binary Heap 的陣列映射規則** 及其對操作複雜度的影響。
2. **抽象資料型別 (ADT)** 與 **介面／實作分離** 的重要性。
3. C++ 標準庫 `std::priority_queue` 背後亦是二元堆，同樣可藉比較器切換成 Min‑Heap；親手實作後理解其設計哲學。
4. 單元測試與壓力測試對驗證資料結構正確性與效能不可或缺。



