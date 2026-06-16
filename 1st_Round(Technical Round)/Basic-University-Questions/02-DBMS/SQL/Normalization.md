# Normalization in DBMS

---

## Definition

**Normalization** is the process of **organizing data in a database to reduce redundancy and improve data integrity**.

> **Breaking large tables into smaller, related tables** so data is stored efficiently and consistently.

---

##  Why Normalization Exists

Without normalization:

- Data gets **duplicated**    
- Updates become inconsistent
- Storage is wasted
- Bugs increase
---

## 🧠 Mental Model

Think of a messy spreadsheet:

| OrderID | CustomerName | CustomerCity | Product |
| ------- | ------------ | ------------ | ------- |
| 1       | Ali          | Lahore       | Laptop  |
| 2       | Ali          | Lahore       | Phone   |

Problems:

- "Ali" and "Lahore" repeated multiple times

Normalized structure:

**Customers Table**

| id  | name | city   |
| --- | ---- | ------ |
| 1   | Ali  | Lahore |

**Orders Table**

|id|customer_id|product|
|---|---|---|
|1|1|Laptop|
|2|1|Phone|

---

##  Goals of Normalization

- Eliminate **data redundancy**
- Ensure **data consistency**
- Improve **data integrity**
- Simplify **updates and maintenance**

---

##  “Syntax” 

Normalization is not written as a command but applied as **design rules**:

1. Identify entities (tables)
2. Define primary keys
3. Remove repeating groups
4. Separate dependent data
5. Establish relationships (foreign keys)

---

## Normal Forms 

|Normal Form|Description|
|---|---|
|1NF|No repeating groups, atomic values|
|2NF|Remove partial dependency|
|3NF|Remove transitive dependency|
|BCNF|Stronger version of 3NF|


---
###  Unnormalized Table (Bad Design)

```javascript
// Orders stored with repeated customer data
const orders = [
  { orderId: 1, customerName: "Ali", city: "Lahore", product: "Laptop" },
  { orderId: 2, customerName: "Ali", city: "Lahore", product: "Phone" }
];
```

 Problems:

- Duplicate customer info
- Hard to update

---

### First Normal Form (1NF)

Rule:

- No repeating groups
- Atomic values

```javascript
const orders = [
  { orderId: 1, customerName: "Ali", city: "Lahore", product: "Laptop" },
  { orderId: 2, customerName: "Ali", city: "Lahore", product: "Phone" }
];
```

✔ Already atomic, but still redundant

---

###  Second Normal Form (2NF)

Rule:

- Remove **partial dependency**

Split tables:

```javascript
const customers = [
  { id: 1, name: "Ali", city: "Lahore" }
];

const orders = [
  { id: 1, customerId: 1, product: "Laptop" },
  { id: 2, customerId: 1, product: "Phone" }
];
```

✔ Customer data separated

---

###  Third Normal Form (3NF)

Rule:

- Remove **transitive dependency**

Example:

```javascript
// Before
const customers = [
  { id: 1, name: "Ali", city: "Lahore", zip: "54000" }
];
```

If ZIP determines city:

```javascript
const zipCodes = [
  { zip: "54000", city: "Lahore" }
];

const customers = [
  { id: 1, name: "Ali", zip: "54000" }
];
```

✔ Eliminates indirect dependency

---

##  Step-by-Step Normalization Example

### Step 1: Start with Unnormalized Table

```javascript
const orders = [
  {
    orderId: 1,
    customerName: "Ali",
    products: ["Laptop", "Mouse"]
  }
];
```

---

### Step 2: Apply 1NF

```javascript
const orders = [
  { orderId: 1, customerName: "Ali", product: "Laptop" },
  { orderId: 1, customerName: "Ali", product: "Mouse" }
];
```

---

### Step 3: Apply 2NF

```javascript
const customers = [
  { id: 1, name: "Ali" }
];

const orders = [
  { id: 1, customerId: 1 }
];

const orderItems = [
  { orderId: 1, product: "Laptop" },
  { orderId: 1, product: "Mouse" }
];
```

---

### Step 4: Apply 3NF

Remove derived data if needed

✔ Final clean structure

---

##  Edge Cases & Pitfalls

###  Over-Normalization

- Too many tables
- Complex joins
- Slower queries
---

###  Performance Trade-Off

- Normalization improves integrity
- But may reduce read performance


---

###  Incorrect

```javascript
const users = [
  {
    id: 1,
    name: "Ali",
    orders: ["Laptop", "Phone"]
  }
];
```

Problems:

- Nested structure
- Hard to query

---

### Correct

```javascript
const users = [{ id: 1, name: "Ali" }];

const orders = [
  { id: 1, userId: 1, product: "Laptop" },
  { id: 2, userId: 1, product: "Phone" }
];
```

---

##  Comparison: Normalization vs Denormalization

|Feature|Normalization|Denormalization|
|---|---|---|
|Data Redundancy|Minimal|Higher|
|Performance (Read)|Slower (joins required)|Faster|
|Performance (Write)|Faster updates|Complex updates|
|Complexity|Higher|Lower|
|Use Case|OLTP systems|OLAP / analytics|

---

##  Real-World Use Cases

---

### E-commerce Backend

```javascript
// Normalized structure
const users = [{ id: 1, name: "Ali" }];
const orders = [{ id: 1, userId: 1 }];
const orderItems = [{ orderId: 1, product: "Laptop" }];
```

✔ Avoids duplication across orders

---

###  Social Media Platform

```javascript
const users = [{ id: 1, username: "ali123" }];

const posts = [
  { id: 1, userId: 1, content: "Hello world" }
];

const comments = [
  { id: 1, postId: 1, userId: 1, text: "Nice!" }
];
```

✔ Scalable and maintainable

---

##  Advanced Insights

- Most systems normalize up to **3NF or BCNF**
- Query performance improved using **indexes**
- Real systems often use **partial denormalization**
- ORMs (like Sequelize, Prisma) encourage normalized design


---

##  Key Points

- Normalization reduces redundancy
- Improves consistency and integrity
- Based on **normal forms (1NF → 3NF)**
- Requires proper relationships
- Trade-off with performance

---

##  Common Mistakes

|Mistake|Fix|
|---|---|
|Storing arrays in columns|Use separate tables|
|Repeating data|Normalize into new table|
|Ignoring dependencies|Identify functional dependencies|
|Over-normalizing|Balance with performance|

---

##  Interview Tips

- Explain normalization with **simple example**
- Know **1NF, 2NF, 3NF clearly**
- Mention **trade-offs**
- Use terms: redundancy, dependency, integrity
- Give real-world schema example

---

##  Interview Summary

- Normalization = organizing data efficiently
- Removes redundancy
- Uses rules (1NF, 2NF, 3NF)
- Improves consistency
- May require joins → performance trade-off

---

##  Final Thoughts

Normalization is fundamental to **database design**. It ensures that systems remain **consistent, scalable, and maintainable**. While it introduces complexity, especially with joins, it forms the backbone of reliable data storage in modern applications.

---