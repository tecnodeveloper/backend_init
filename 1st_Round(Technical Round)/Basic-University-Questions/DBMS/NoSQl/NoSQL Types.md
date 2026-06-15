# NoSQL Types

## Definition

**NoSQL databases** are non-relational database systems designed to store, manage, and retrieve data in flexible formats without requiring a fixed schema like traditional SQL databases.

They are optimized for:

- Scalability
    
- High performance
    
- Flexible data models
    
- Distributed systems
    

The four main types of NoSQL databases are:

1. Document Databases
    
2. Key-Value Databases
    
3. Column-Family Databases
    
4. Graph Databases
    

Each type solves a different class of data problem.

---

# Why NoSQL Types Exist

Traditional relational databases struggle with:

- Massive scale applications (millions of users)
    
- Rapid schema changes
    
- Unstructured or semi-structured data
    
- Distributed system requirements
    

NoSQL systems emerged to support:

- Horizontal scaling (sharding)
    
- High availability
    
- Flexible schema evolution
    
- Real-time applications
    

Different data problems require different storage models, which is why NoSQL is divided into multiple types.

---

# Mental Model

Think of NoSQL types as different storage tools:

|Type|Mental Model|
|---|---|
|Document|JSON files in folders|
|Key-Value|Dictionary / HashMap|
|Column-Family|Spreadsheet optimized for big data|
|Graph|Social network connections|

---

# Overview of NoSQL Types

|Type|Structure|Best For|Example Databases|
|---|---|---|---|
|Document|JSON/BSON documents|APIs, apps|MongoDB|
|Key-Value|Key → Value pairs|caching, sessions|Redis|
|Column-Family|Columns grouped into families|analytics|Cassandra|
|Graph|Nodes + edges|relationships|Neo4j|

---

# 1. Document Databases

## Definition

Stores data in document format (JSON-like structures).

Each document is self-contained and can have a different schema.

---

## Example Database Structure

### users Collection

```javascript
{
  userId: 101,
  name: "Ali",
  email: "ali@example.com",
  address: {
    city: "Lahore",
    country: "Pakistan"
  }
}
```

---

## Basic Example

```javascript
db.users.insertOne({
  name: "Sara",
  age: 25
});
```

---

## Intermediate Example

```javascript
db.users.find({
  "address.city": "Lahore"
});
```

---

## Real-World Example

E-commerce product catalog:

```javascript
{
  productId: 501,
  name: "Laptop",
  price: 1200,
  specs: {
    ram: "16GB",
    cpu: "Intel i7"
  }
}
```

---

## Internal Behavior

- Stored as BSON
    
- Indexed by `_id`
    
- Supports nested structures
    
- Query engine scans or uses indexes
    

---

## Advantages

- Flexible schema
    
- Easy integration with apps
    
- Natural JSON mapping
    

---

## Disadvantages

- Data duplication
    
- Complex joins are limited
    

---

# 2. Key-Value Databases

## Definition

Stores data as simple key → value pairs.

---

## Example Structure

```javascript
{
  "session_101": {
    userId: 101,
    token: "abc123"
  }
}
```

---

## Basic Example

```javascript
db.sessions.set("session_101", {
  userId: 101
});
```

---

## Intermediate Example

```javascript
db.cache.set("product_501", {
  name: "Laptop",
  price: 1200
});
```

---

## Real-World Example

Authentication session storage:

```javascript
{
  "auth_token_abc": {
    userId: 101,
    role: "admin"
  }
}
```

---

## Internal Behavior

Step-by-step lookup:

```text
Key → Hash Function → Memory Location → Value Retrieved
```

---

## Advantages

- Extremely fast
    
- Simple design
    
- Highly scalable
    

---

## Disadvantages

- No complex querying
    
- Limited filtering
    

---

# 3. Column-Family Databases

## Definition

Stores data in columns grouped into families instead of rows.

Optimized for large-scale analytical workloads.

---

## Example Structure

```javascript
{
  userId: 101,
  loginDate: "2025-06-10",
  device: "Mobile",
  country: "Pakistan"
}
```

---

## Basic Example

```javascript
db.activity.insert({
  userId: 101,
  event: "login"
});
```

---

## Intermediate Example

```javascript
db.activity.find({
  userId: 101
});
```

---

## Real-World Example

Clickstream analytics:

```javascript
{
  eventId: 9001,
  userId: 101,
  eventType: "purchase",
  timestamp: Date.now()
}
```

---

## Internal Behavior

Column-based storage:

```text
Column A: userId → [101, 102, 103]
Column B: event → [login, click, purchase]
Column C: timestamp → [...]
```

---

## Advantages

- Very fast writes
    
- Scales to huge datasets
    
- Efficient analytics
    

---

## Disadvantages

- Complex modeling
    
- Harder to understand
    

---

# 4. Graph Databases

## Definition

Stores data as:

- Nodes (entities)
    
- Edges (relationships)
    

---

## Example Structure

```javascript
{
  userId: 101,
  name: "Ali"
}
```

Relationship:

```javascript
{
  from: 101,
  to: 102,
  type: "FRIEND"
}
```

---

## Basic Example

```javascript
db.users.insertOne({
  userId: 101,
  name: "Ali"
});
```

---

## Intermediate Example

```javascript
db.relationships.insertOne({
  from: 101,
  to: 102,
  type: "FOLLOWS"
});
```

---

## Real-World Example

Social network:

```javascript
{
  userId: 101,
  follows: 102
}
```

---

## Internal Behavior

Graph traversal:

```text
Node → Edge → Node → Edge → Node
```

---

## Advantages

- Excellent relationship handling
    
- Fast traversal
    
- Natural for networks
    

---

## Disadvantages

- Not ideal for simple CRUD apps
    
- Can be complex at scale
    

---

# Step-by-Step Database Selection Example

## Scenario: Social Media Platform

---

### User Profiles

```javascript
db.users.insertOne({
  userId: 101,
  name: "Ali"
});
```

Use:

```text
Document Database
```

---

### Session Storage

```javascript
db.sessions.set("token_abc", {
  userId: 101
});
```

Use:

```text
Key-Value Database
```

---

### Activity Logs

```javascript
db.events.insertOne({
  userId: 101,
  event: "like"
});
```

Use:

```text
Column-Family Database
```

---

### Friend Recommendations

```javascript
{
  userId: 101,
  friend: 102
}
```

Use:

```text
Graph Database
```

---

# Comparison Table

|Feature|Document|Key-Value|Column-Family|Graph|
|---|---|---|---|---|
|Structure|JSON|Key/Value|Columns|Nodes/Edges|
|Query Power|Medium|Low|Medium|High|
|Scalability|High|Very High|Very High|Medium|
|Relationships|Limited|None|Limited|Excellent|
|Use Case|Apps|Cache|Big Data|Networks|

---

# Common Mistakes

---

## Mistake 1: Using Key-Value for Complex Queries

### Wrong

```javascript
db.cache.find({ userId: 101 });
```

### Fix

Use Document Database.

---

## Mistake 2: Using Graph DB for Simple CRUD

### Wrong

```javascript
{
  name: "Ali"
}
```

### Fix

Use Document Database.

---

## Mistake 3: Ignoring Access Pattern

### Wrong Thinking

```text
Which database is best overall?
```

### Correct Thinking

```text
What is my data access pattern?
```

---

# Edge Cases and Pitfalls

---

## Data Duplication (Document DB)

Same data repeated across documents.

---

## Hot Key Problem (Key-Value DB)

Single key gets overloaded.

---

## Wide Column Issues (Column-Family DB)

Too many columns reduce performance.

---

## Deep Traversal Cost (Graph DB)

Large networks increase traversal time.

---

# Real-World Use Case 1: E-Commerce System

### Product Storage

```javascript
db.products.insertOne({
  productId: 500,
  name: "Laptop",
  price: 1200
});
```

Type:

```text
Document Database
```

---

### Cart Cache

```javascript
db.cart.set("user_101", {
  items: 3
});
```

Type:

```text
Key-Value Database
```

---

# Real-World Use Case 2: Social Media Platform

### User Posts

```javascript
db.posts.insertOne({
  postId: 900,
  userId: 101,
  content: "Hello"
});
```

Type:

```text
Document Database
```

---

### Friend Network

```javascript
{
  userId: 101,
  follows: 102
}
```

Type:

```text
Graph Database
```

---

# Key Points

- NoSQL has 4 main types: Document, Key-Value, Column-Family, Graph
    
- Each type solves a different data problem
    
- No single database fits all use cases
    
- Selection depends on access patterns
    
- Document DB = flexible applications
    
- Key-Value DB = fast lookups
    
- Column-Family DB = big data analytics
    
- Graph DB = relationship-heavy systems
    

---

# Interview Summary

### What are the main NoSQL types?

1. Document
    
2. Key-Value
    
3. Column-Family
    
4. Graph
    

---

### Which NoSQL type is fastest?

Key-Value databases.

---

### Which NoSQL type is best for relationships?

Graph databases.

---

### Which NoSQL type is used by MongoDB?

Document database.

---

### Which NoSQL type is best for caching?

Key-Value database.

---

### Which NoSQL type is best for analytics?

Column-Family database.

---

# Conclusion

NoSQL databases are designed to handle modern-scale applications by offering multiple data models tailored to specific workloads. Understanding Document, Key-Value, Column-Family, and Graph databases allows engineers to choose the right tool for the right problem, ensuring scalability, performance, and efficient data modeling in distributed systems.