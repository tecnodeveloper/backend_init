# Stack, Queue, Heap(SQH)

---

# 1. Stack

---

## 1.1 Definition

A **Stack** is a linear data structure that follows:
> **LIFO (Last In, First Out)**

The last element added is the first one removed.

---

## 1.2 Why Stack Exists

- Needed for **reversing operations**    
- Used in **function calls (call stack)**    
- Helps in **undo/redo systems**    

---

## 1.3 Mental Model

Think of a **stack of books**:

- Add on top    
- Remove from top 

---
## 1.5 Basic Example

```javascript
const s = new Stack();

s.push(10);
s.push(20);
s.push(30);

console.log(s.pop()); // 30
```

---

## 1.6 Step-by-Step

```text
Push 10 → [10]
Push 20 → [10,20]
Push 30 → [10,20,30]

Pop → 30 removed
```

---

## 1.7 Real-World Use Case

- Browser back button    
- Undo feature    

---

## 1.9 Key Points

- LIFO    
- Fast operations (O(1))    
- Only top accessible    

---

# 2. Queue

---

## 2.1 Definition

A **Queue** follows:
> **FIFO (First In, First Out)**

First inserted element is removed first.

---

## 2.2 Why Queue Exists

- Fair processing    
- Task schedulin    
- Request handling    

---

## 2.3 Mental Model

Think of a **line at a shop**:

- First person served first    

---

## 2.4 Syntax

```javascript
class Queue {
  constructor() {
    this.items = [];
  }

  enqueue(x) {
    this.items.push(x);
  }

  dequeue() {
    return this.items.shift();
  }
}
```

---

## 2.6 Step-by-Step

```text
[A]
[A,B]

Dequeue → removes A
```

---

## 2.7 Real-World Use

- API request queue    
- CPU scheduling    

---

## 2.9 Key Points

- FIFO    
- Used in scheduling    
- Order matters    

---

# 3. Heap

---

## 3.1 Definition

A **Heap** is a special tree structure where:

- **Min Heap** → smallest at root    
- **Max Heap** → largest at root    

---

## 3.2 Why Heap Exists

- Efficient priority access    
- Used in algorithms like shortest path    

---

## 3.3 Mental Model

Think of a **priority system**:

- Highest priority comes first    

---

## 3.4 Syntax

```javascript
class MinHeap {
  constructor() {
    this.heap = [];
  }

  insert(val) {
    this.heap.push(val);
    this.heap.sort((a, b) => a - b);
  }

  extractMin() {
    return this.heap.shift();
  }
}
```

---

## 3.5 Example

```javascript
const h = new MinHeap();

h.insert(5);
h.insert(2);
h.insert(8);

console.log(h.extractMin()); // 2
```

---

## 3.6 Step-by-Step

```text
Insert 5 → [5]
Insert 2 → [2,5]
Insert 8 → [2,5,8]

Extract → 2
```

---

## 3.7 Real-World Use

- Task priority systems    
- Dijkstra algorithm   

---

## 3.9 Key Points

- Complete binary tree    
- Fast min/max access    
- Not fully sorted    

---


|Feature|Stack|Queue|Heap|Tree|
|---|---|---|---|---|
|Type|Linear|Linear|Non-linear|Non-linear|
|Order|LIFO|FIFO|Priority|Hierarchical|
|Access|Top|Front|Root|Structured|
|Use Case|Undo|Scheduling|Priority|Hierarchy|

---

# 6. Common Mistakes (All)

- Confusing LIFO vs FIFO    
- Assuming heap is sorted    
- Ignoring null in trees    
- Using wrong operations    

---

# 7. Interview Tips

---

### What Interviewers Expect:

- Clear differences    
- Real-world usage    
- Implementation basics    
- Time complexity    

---

### Common Questions:

- Stack vs Queue difference    
- Heap vs BST    
- Tree traversal types    
- Use cases    

---

# 8. Interview Summary

- Stack → LIFO    
- Queue → FIFO    
- Heap → Priority-based tree    
- Tree → Hierarchical structure    

---

# 9. Final Mental Model

- Stack → pile    
- Queue → line    
- Heap → priority system    
- Tree → hierarchy
