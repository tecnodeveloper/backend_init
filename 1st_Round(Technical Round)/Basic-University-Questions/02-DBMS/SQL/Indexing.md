# Indexing in DBMS

---

##  Definition 

**Indexing** is a technique used in databases to **speed up data retrieval** by creating a separate data structure that allows the database to find rows quickly—without scanning the entire table.

Think of it like the **index of a book**: instead of reading every page to find a topic, you jump directly to the page number listed in the index.

---

##  Why Indexing Exists

Without indexing:

- The database performs a **full table scan** (checking every row)
- Slow performance, especially with large datasets

With indexing:

- The database can **locate data quickly**
- Improves **read/query performance**

---
##  JavaScript Example (Using a Database)

### Basic Query Without Index

```javascript
// Simulating a slow query (no index)
const users = await db.collection("users").find({ email: "test@example.com" });
```

 This may scan all records.

---

### Adding Index

```javascript
// Create index on email field
await db.collection("users").createIndex({ email: 1 });
```

---

### Query After Index

```javascript
const users = await db.collection("users").find({ email: "test@example.com" });
```

 Now the query is much faster.

---


##  Comparison: Indexed vs Non-Indexed

| Feature      | Indexed          | Non-Indexed    |
| ------------ | ---------------- | -------------- |
| Search Speed | Fast (O(log n))  | Slow (O(n))    |
| Insert Speed | Slower           | Faster         |
| Storage      | Extra space      | No extra space |
| Use Case     | Frequent queries | Rare queries   |

---
##  Advanced Insights

- Indexes can be **covering indexes** (contain all needed data)
- Query optimizer decides **whether to use index**

---

##  Key Points

- Indexing improves **read performance**
- Uses structures like **B-Trees**
- Costs extra **storage and write overhead**
- Must be used **strategically**
- Not all columns should be indexed

---

##  Interview Tips

- Always mention **trade-off (read vs write)**
- Explain **B-Tree concept simply**
- Give real-world analogy (book index)
- Know **composite index behavior**
- Mention **query optimization**

---

##  Interview Summary

- Index = **data structure for fast lookup**
- Improves **SELECT performance**
- Slows down **INSERT/UPDATE**
- Implemented using **B-Trees**

---

## Final Thoughts

Indexing is essential for building **scalable and high-performance systems**. Proper use of indexes can turn slow queries into fast operations, but misuse can degrade performance.