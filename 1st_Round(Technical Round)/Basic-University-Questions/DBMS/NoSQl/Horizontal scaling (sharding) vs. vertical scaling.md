# Horizontal Scaling (Sharding) vs Vertical Scaling

## Definition

**Scaling** is the process of increasing a system’s capacity to handle more load (users, requests, or data).

There are two primary approaches:

- **Vertical Scaling (Scale Up)** → Increase power of a single machine
    
- **Horizontal Scaling (Sharding / Scale Out)** → Add more machines and distribute data
    

In simple terms:

- Vertical scaling = make one server stronger
    
- Horizontal scaling = add more servers
    

---

# Why Scaling Concepts Exist

Modern applications face:

- Millions of users
    
- High read/write traffic
    
- Large datasets (TBs to PBs)
    
- Real-time processing needs
    

A single database server cannot handle unlimited load due to:

- CPU limits
    
- Memory limits
    
- Disk I/O bottlenecks
    
- Network throughput constraints
    

Scaling strategies solve these limitations.

---

# Mental Model

Imagine a restaurant:

## Vertical Scaling

```text
One chef → upgraded to super chef
Same kitchen, same workflow
```

## Horizontal Scaling

```text
One restaurant → multiple restaurants
Each handles customers independently
```

---

# Vertical Scaling (Scale Up)

## Definition

Vertical scaling means increasing the capacity of a single server by upgrading hardware.

---

## Example

Original database server:

```javascript
{
  cpu: "2 cores",
  ram: "4 GB",
  storage: "100 GB"
}
```

After scaling:

```javascript
{
  cpu: "16 cores",
  ram: "64 GB",
  storage: "2 TB"
}
```

---

## How It Works Internally

- Upgrade CPU, RAM, SSD
    
- Improve single-node performance
    
- Database continues running on one machine
    

---

## MongoDB Example (Single Node Scaling)

```javascript
db.orders.find({
  status: "completed"
});
```

Same query runs faster after hardware upgrade.

---

## Advantages

- Simple architecture
    
- No distributed complexity
    
- Easier to manage
    
- No data partitioning required
    

---

## Disadvantages

- Hardware limits exist
    
- Expensive at high-end tiers
    
- Single point of failure
    
- Limited scalability ceiling
    

---

## Real-World Use Case

Small SaaS application:

```javascript
db.users.insertOne({
  name: "Ali",
  email: "ali@example.com"
});
```

Initially handled by one powerful server.

---

# Horizontal Scaling (Sharding / Scale Out)

## Definition

Horizontal scaling means distributing data across multiple servers (nodes).

This is commonly implemented using **sharding** in NoSQL systems.

---

## Example Architecture

```text
        Client
           |
   -------------------
   |        |        |
 Node A   Node B   Node C
 (Shard1) (Shard2) (Shard3)
```

---

## Sharding Concept

Data is split into chunks:

```javascript
Users Collection:

Shard 1 → Users A–G
Shard 2 → Users H–P
Shard 3 → Users Q–Z
```

---

## MongoDB Sharding Example

```javascript
sh.shardCollection("app.users", {
  userId: 1
});
```

Shard key determines data distribution.

---

## Insert Operation in Sharded System

```javascript
db.users.insertOne({
  userId: 101,
  name: "Sara"
});
```

MongoDB decides shard automatically:

```text
userId 101 → Shard 2
```

---

## Read Operation

```javascript
db.users.find({
  userId: 101
});
```

Query routed directly to correct shard.

---

## Internal Behavior

1. Query analyzed by query router (mongos)
    
2. Shard key determines target node
    
3. Only relevant shard is queried
    
4. Result merged if needed
    

---

## Advantages

- Highly scalable
    
- Handles large datasets
    
- Supports high traffic
    
- Fault isolation across nodes
    

---

## Disadvantages

- Complex setup
    
- Data distribution challenges
    
- Cross-shard queries are expensive
    
- Operational overhead
    

---

## Real-World Use Case

E-commerce platform:

```javascript
db.orders.insertOne({
  orderId: 5001,
  userId: 101,
  amount: 2500
});
```

Sharded across regions:

```text
Asia Shard → Node A
Europe Shard → Node B
US Shard → Node C
```

---

# Step-by-Step Sharding Flow

## Step 1: Choose Shard Key

```javascript
userId
```

---

## Step 2: Enable Sharding

```javascript
sh.enableSharding("app");
```

---

## Step 3: Define Shard Collection

```javascript
sh.shardCollection("app.orders", {
  userId: 1
});
```

---

## Step 4: Insert Data

```javascript
db.orders.insertOne({
  userId: 200,
  amount: 1500
});
```

---

## Step 5: Data Distribution

```text
userId 200 → Shard 3
```

---

# Comparison Table

|Feature|Vertical Scaling|Horizontal Scaling|
|---|---|---|
|Approach|Upgrade single machine|Add multiple machines|
|Complexity|Low|High|
|Cost|Expensive at high-end|More cost-efficient long-term|
|Downtime Risk|High|Low|
|Scalability Limit|Hardware bound|Nearly unlimited|
|Failure Impact|Single point of failure|Distributed failure handling|
|Setup Difficulty|Easy|Complex|

---

# Key Differences Explained

## 1. Performance Scaling

- Vertical → increases single-node power
    
- Horizontal → distributes workload
    

---

## 2. Failure Handling

- Vertical → one server crash = system down
    
- Horizontal → other nodes continue working
    

---

## 3. Data Growth

- Vertical → limited disk size
    
- Horizontal → infinite logical scaling
    

---

# Common Mistakes

---

## Mistake 1: Assuming Vertical Scaling is Infinite

### Wrong

```text
Just keep upgrading one server forever
```

### Correct

```text
Hardware has physical and cost limits
```

---

## Mistake 2: Poor Shard Key Selection

### Wrong

```javascript
sh.shardCollection("orders", { status: 1 });
```

### Problem

```text
Uneven data distribution (hot shard)
```

### Correct

```javascript
sh.shardCollection("orders", { userId: 1 });
```

---

## Mistake 3: Ignoring Cross-Shard Queries

### Problem Query

```javascript
db.orders.find({
  amount: { $gt: 1000 }
});
```

### Issue

```text
Queries all shards → slow performance
```

---

# Edge Cases and Pitfalls

---

## 1. Hot Shard Problem

One shard receives most traffic:

```text
Shard 1 overloaded
Shard 2 idle
Shard 3 idle
```

---

## 2. Data Skew

Uneven distribution causes imbalance.

---

## 3. Cross-Shard Joins

Joins become expensive or unsupported.

---

## 4. Resharding Complexity

Changing shard key later is difficult.

---

# Internal Behavior

---

## Vertical Scaling

Database engine:

```text
Uses same storage engine
More CPU/RAM improves query execution
```

No architectural changes required.

---

## Horizontal Scaling

Database engine:

```text
Uses shard router + multiple nodes
Data partitioned using shard key
Queries distributed across cluster
```

---

# Real-World Use Case 1: Social Media Platform

```javascript
db.posts.insertOne({
  postId: 9001,
  userId: 501,
  content: "Hello world"
});
```

Sharding strategy:

```text
userId-based distribution
```

Reason:

- Millions of users
    
- High read/write traffic
    

---

# Real-World Use Case 2: E-Commerce System

```javascript
db.orders.insertOne({
  orderId: 7001,
  userId: 300,
  total: 4500
});
```

Scaling approach:

- Vertical scaling for small stage
    
- Horizontal scaling for production
    

---

# Real-World Use Case 3: Analytics Platform

```javascript
db.events.insertOne({
  eventId: 10001,
  type: "click",
  timestamp: Date.now()
});
```

Why horizontal scaling:

- Huge data ingestion
    
- High write throughput
    
- Distributed processing required
    

---

# When to Use Vertical Scaling

- Early-stage applications
    
- Small to medium traffic
    
- Simple architecture required
    
- Limited engineering resources
    

---

# When to Use Horizontal Scaling

- Large-scale applications
    
- Big data workloads
    
- Global user base
    
- High availability requirements
    

---

# Key Points

- Vertical scaling upgrades a single machine
    
- Horizontal scaling distributes data across machines
    
- Sharding is the main method of horizontal scaling in NoSQL
    
- Vertical scaling is simpler but limited
    
- Horizontal scaling is complex but highly scalable
    
- Shard key selection is critical
    
- Distributed systems introduce consistency and routing challenges
    
- Most modern systems combine both approaches
    

---

# Interview Summary

### What is vertical scaling?

Increasing the power of a single server by upgrading CPU, RAM, or storage.

---

### What is horizontal scaling?

Adding more servers and distributing data across them.

---

### What is sharding?

A horizontal scaling technique that splits data across multiple database nodes.

---

### Which is more scalable?

Horizontal scaling.

---

### What is a shard key?

A field used to determine how data is distributed across shards.

---

### Main disadvantage of horizontal scaling?

Complexity in setup, maintenance, and query routing.

---

# Conclusion

Vertical and horizontal scaling are foundational concepts in distributed database design. Vertical scaling provides simplicity and quick performance improvements but has physical limits. Horizontal scaling, implemented through sharding, enables massive scalability and high availability at the cost of complexity. Modern NoSQL systems rely heavily on horizontal scaling to support large-scale, globally distributed applications.