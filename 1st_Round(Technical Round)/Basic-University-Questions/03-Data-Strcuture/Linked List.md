# Linked List (Data Structure in C++ OOP Perspective)

---

## 1. Definition

A **Linked List** is a linear data structure where elements (called **nodes**) are stored in separate memory locations and connected using pointers (references).

Each node contains:

- **Data**
- **Pointer to next node** (and optionally previous node)

---

## 2. Why Linked List Exists

Arrays have limitations:

- Fixed size (in static arrays)    
- Expensive insertions/deletions (O(n))    
- Memory wastage or overflow    

A **Linked List solves these problems** by:

- Dynamic memory allocation    
- Efficient insertion/deletion (O(1) if position is known)    
- Flexible size    

---

## 3. Mental Model

Think of a **train system**:

- Each compartment is a node    
- Each compartment knows only the next one    
- You can add/remove compartments without rearranging the whole train    

---

## 4. Types of Linked Lists

- **Singly Linked List** → forward direction only    
- **Doubly Linked List** → forward + backward    
- **Circular Linked List** → last node connects back to first    

---

## 5. Node Structure (Core Concept)

### JavaScript Representation

```javascript
class Node {
  constructor(data) {
    this.data = data;
    this.next = null;
  }
}

Real world (Browser History)

class BrowserHistory {
  constructor() {
    this.list = new LinkedList();
  }

  visit(page) {
    this.list.insertAtHead(page);
  }

  show() {
    this.list.print();
  }
}

Real world (Music player playlist)

class Playlist {
  constructor() {
    this.songs = new LinkedList();
  }

  addSong(song) {
    this.songs.insert(song);
  }

  play() {
    this.songs.print();
  }
}
```


---

## 6. Memory Visualization

```text
Array:
[10][20][30] → contiguous memory

Linked List:
[10|*] → [20|*] → [30|null]
(scattered memory)
```

---

## 7. Comparison with Array

|Feature|Array|Linked List|
|---|---|---|
|Memory|Contiguous|Non-contiguous|
|Size|Fixed/Dynamic (costly)|Fully dynamic|
|Insertion|O(n)|O(1) (if position known)|
|Deletion|O(n)|O(1) (if node known)|
|Access|O(1)|O(n)|

---

## 8. Edge Cases

- Empty list operations    
- Single node list deletion    
- Deleting head node    
- Searching non-existent element    

---

## 9. Key Points

- Nodes are dynamically allocated    
- Each node points to next node    
- Efficient insert/delete (when pointer known)    
- Sequential access only    

---

## 10. Mental Model

Think of a **treasure hunt trail**:

- Each clue leads to the next    
- You cannot jump directly    
- You must follow the chain    

---

## 11. Interview Tips

### What interviewers expect:

- Understanding pointer-based structure    
- Ability to manipulate nodes safely    
- Handling edge cases    
- Recursive + iterative solutions    

### Common Questions:

- Reverse a linked list    
- Detect cycle (Floyd’s algorithm)    
- Find middle element    
- Merge two sorted linked lists    

---

## 12. Interview Summary

- Linked List = dynamic chain of nodes    
- Better than arrays for insert/delete-heavy operations    
- Weakness: slow random access    
- Core DS for stacks, queues, graphs (adjacency list)    

---

## 13. Final Mental Model

A linked list is not a container like an array.

It is a **chain of objects connected by references**, where navigation is sequential, not indexed.