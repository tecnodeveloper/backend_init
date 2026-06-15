# CAP Theorem (Consistency, Availability, and Partition Tolerance)

## Definition

The **CAP Theorem** is a fundamental principle in distributed database systems that states:

> A distributed system can guarantee at most **two out of the following three properties simultaneously**:
> 
> - **Consistency (C)**
>     
> - **Availability (A)**
>     
> - **Partition Tolerance (P)**
>     

In practical distributed systems, when a network partition occurs, a database must choose between **Consistency** and **Availability**.

The theorem helps architects understand the trade-offs involved when designing distributed databases and NoSQL systems.

---

# Why CAP Theorem Exists

Modern applications rarely store data on a single server.

Distributed databases use:

- Multiple servers
    
- Multiple data centers
    
- Geographic replication
    
- High availability architectures
    

However, networks are not perfect.

Problems such as:

- Server failures
    
- Network outages
    
- Data center failures
    
- Communication delays
    

can cause different database nodes to become isolated from each other.

CAP Theorem explains what happens during these failures and what trade-offs a database must make.

---

# Historical Background

The theorem was proposed by:

Eric Brewer

in 2000 and later formally proven by:

- Seth Gilbert
    
- Nancy Lynch
    

Because of this, CAP Theorem is sometimes called:

```text
Brewer's Theorem
```

---

# Mental Model

Imagine a database cluster:

```text
          Client
             |
             V

    +-------------+
    |   Node A    |
    +-------------+
           |
           |
    Network Link
           |
           |
    +-------------+
    |   Node B    |
    +-------------+
```

Normally both nodes communicate.

Now imagine the network cable is cut:

```text
          Client

    +-------------+
    |   Node A    |
    +-------------+

   X Network Failure X

    +-------------+
    |   Node B    |
    +-------------+
```

Both nodes are alive but cannot talk to each other.

The system must decide:

- Reject requests (Consistency)
    
- Accept requests (Availability)
    

It cannot fully guarantee both.

---

# The Three Components

---

## 1. Consistency (C)

### Definition

Every read receives the most recent write.

After data is updated:

```javascript
db.accounts.updateOne(
  { accountId: 1001 },
  {
    $set: {
      balance: 5000
    }
  }
);
```

All nodes must return:

```javascript
{
  accountId: 1001,
  balance: 5000
}
```

No node should return older data.

---

### Example

Node A:

```javascript
{
  accountId: 1001,
  balance: 5000
}
```

Node B:

```javascript
{
  accountId: 1001,
  balance: 5000
}
```

Data remains identical.

---

### Goal

Prevent:

- Dirty reads
    
- Stale data
    
- Conflicting versions
    

---

## 2. Availability (A)

### Definition

Every request receives a response.

Even if some nodes fail:

```javascript
db.products.findOne({
  productId: 500
});
```

must return a result.

The database should not reject requests simply because another node is unavailable.

---

### Example

Node B is down.

Node A still serves requests:

```javascript
{
  productId: 500,
  stock: 25
}
```

The system remains operational.

---

### Goal

Keep applications online.

---

## 3. Partition Tolerance (P)

### Definition

The system continues operating despite network communication failures between nodes.

---

### Example

Cluster:

```text
Node A <----X----> Node B
```

Network partition occurs.

Both nodes continue running.

The system tolerates the partition.

---

### Goal

Survive network failures.

---

# Understanding the Trade-Off

CAP is often misunderstood.

Many believe:

```text
Choose any two:
C + A
A + P
C + P
```

This is not entirely accurate.

In distributed systems:

```text
Partition Tolerance is mandatory.
```

Networks fail.

Therefore the real decision becomes:

```text
When a partition occurs:

Choose Consistency
or
Choose Availability
```

---

# CAP Models

---

# CP Systems (Consistency + Partition Tolerance)

## Characteristics

Prioritize:

- Correct data
    
- Data integrity
    
- Strong consistency
    

May reject requests during partitions.

---

## Example

Banking database:

```javascript
{
  accountId: 1001,
  balance: 10000
}
```

User withdraws:

```javascript
{
  amount: 2000
}
```

During network failure:

```text
Reject operation
```

rather than risk incorrect balances.

---

## Benefits

- Strong consistency
    
- Accurate data
    
- No stale reads
    

---

## Drawbacks

- Reduced availability
    
- Requests may fail
    

---

## Typical Databases

|Database|CAP Style|
|---|---|
|MongoDB (strong consistency settings)|CP|
|HBase|CP|
|ZooKeeper|CP|
|Redis Sentinel (certain modes)|CP|

---

# AP Systems (Availability + Partition Tolerance)

## Characteristics

Prioritize:

- High uptime
    
- Continuous operation
    

Accept temporary inconsistencies.

---

## Example

E-commerce inventory:

Node A:

```javascript
{
  productId: 200,
  stock: 15
}
```

Node B:

```javascript
{
  productId: 200,
  stock: 14
}
```

During partition:

Both nodes continue serving requests.

Later:

```text
Data synchronization occurs
```

---

## Benefits

- Always available
    
- High uptime
    
- Better user experience
    

---

## Drawbacks

- Stale reads possible
    
- Eventual consistency
    

---

## Typical Databases

|Database|CAP Style|
|---|---|
|Cassandra|AP|
|DynamoDB|AP|
|CouchDB|AP|
|Riak|AP|

---

# CA Systems (Consistency + Availability)

## Characteristics

Provide:

- Consistency
    
- Availability
    

But only when partitions do not occur.

---

## Example

Single database server:

```javascript
db.users.find()
```

No distributed network exists.

No partition is possible.

---

## Examples

|Database Type|CAP Style|
|---|---|
|Traditional single-node RDBMS|CA|
|Standalone MySQL|CA|
|Standalone PostgreSQL|CA|

---

## Important Note

True distributed systems cannot realistically guarantee CA when partitions occur.

---

# Database-Oriented Examples

---

# Example 1: Banking System (CP)

Collection:

```javascript
{
  accountId: 1001,
  balance: 10000
}
```

Transfer request:

```javascript
{
  fromAccount: 1001,
  toAccount: 1002,
  amount: 500
}
```

During partition:

```text
Reject transfer
```

Reason:

```text
Incorrect balances are unacceptable.
```

Consistency is more important.

---

# Example 2: Social Media Likes (AP)

Collection:

```javascript
{
  postId: 501,
  likes: 1200
}
```

Node A:

```javascript
likes: 1205
```

Node B:

```javascript
likes: 1203
```

Temporary mismatch is acceptable.

Users can continue using the application.

Availability is prioritized.

---

# Example 3: Product Catalog (AP)

Collection:

```javascript
{
  productId: 700,
  price: 49.99
}
```

One region sees:

```javascript
49.99
```

Another sees:

```javascript
50.99
```

for a short period.

System remains online.

Eventually data converges.

---

# Step-by-Step CAP Scenario

Consider a MongoDB cluster.

Initial state:

```javascript
{
  orderId: 1001,
  status: "Pending"
}
```

---

## Step 1

Update occurs on Node A.

```javascript
db.orders.updateOne(
  { orderId: 1001 },
  {
    $set: {
      status: "Shipped"
    }
  }
);
```

---

## Step 2

Network partition happens.

```text
Node A   X   Node B
```

---

## Step 3

Client reads from Node B.

Two choices:

### CP

```text
Reject request
```

Guarantees consistency.

---

### AP

```javascript
{
  orderId: 1001,
  status: "Pending"
}
```

Returns stale data.

Guarantees availability.

---

# Eventual Consistency

Most AP databases rely on:

```text
Eventual Consistency
```

Meaning:

```text
Data may be temporarily inconsistent
but eventually becomes consistent.
```

Example:

Node A:

```javascript
stock: 20
```

Node B:

```javascript
stock: 18
```

After synchronization:

```javascript
stock: 20
```

on all nodes.

---

# Internal Behavior During Partitions

When a partition occurs:

```text
Node A cannot reach Node B
```

Databases use different strategies.

---

## CP Databases

```text
Pause writes
Reject requests
Wait for synchronization
```

---

## AP Databases

```text
Accept writes
Store versions
Resolve conflicts later
```

---

# Common Mistakes

---

## Mistake 1: CAP Means Choose Any Two

### Incorrect

```text
Choose any two of C, A, P
```

### Correct

```text
Partition tolerance is usually mandatory.
The real choice is between
Consistency and Availability during partitions.
```

---

## Mistake 2: AP Means No Consistency

### Incorrect

```text
AP databases never become consistent.
```

### Correct

```text
AP databases often provide eventual consistency.
```

---

## Mistake 3: CA Distributed Databases Exist Everywhere

### Incorrect

```text
Distributed systems can always be CA.
```

### Correct

```text
Network partitions make true CA impossible in distributed environments.
```

---

# Incorrect Design Example

Suppose an inventory service chooses availability without considering conflicts.

```javascript
{
  productId: 200,
  stock: 1
}
```

Two isolated nodes sell the same item.

Node A:

```javascript
stock: 0
```

Node B:

```javascript
stock: 0
```

Result:

```text
Overselling occurs.
```

---

# Better Design

Use strong consistency:

```javascript
db.inventory.updateOne(
  {
    productId: 200,
    stock: { $gt: 0 }
  },
  {
    $inc: {
      stock: -1
    }
  }
);
```

This reduces inventory conflicts.

---

# Comparison: ACID vs CAP

|Feature|ACID|CAP|
|---|---|---|
|Focus|Transactions|Distributed Systems|
|Concern|Data Integrity|Network Failures|
|Applies To|Database Operations|Cluster Architecture|
|Consistency Meaning|Transaction Consistency|Same Data Across Nodes|
|Availability Concern|No|Yes|
|Partition Concern|No|Yes|

---

# Comparison: SQL vs NoSQL Under CAP

|Feature|Traditional SQL|NoSQL|
|---|---|---|
|Priority|Consistency|Availability or Consistency|
|Scaling|Vertical|Horizontal|
|Distribution|Limited|Native|
|CAP Awareness|Lower|High|
|Eventual Consistency|Rare|Common|

---

# Real-World Use Case 1: Banking Platform

Backend Service:

```javascript
db.transactions.insertOne({
  accountId: 1001,
  amount: -500,
  type: "withdrawal"
});
```

Requirement:

```text
Never lose money.
Never show incorrect balances.
```

Choice:

```text
CP
```

---

# Real-World Use Case 2: E-Commerce Platform

Backend Service:

```javascript
db.products.find({
  category: "Electronics"
});
```

Requirement:

```text
Website must remain online globally.
```

Temporary inconsistencies are acceptable.

Choice:

```text
AP
```

---

# Real-World Use Case 3: Social Media Platform

Frontend Request:

```javascript
fetch("/api/posts/501/likes");
```

If likes differ by a few seconds across regions:

```text
Users rarely notice.
```

Choice:

```text
AP
```

---

# Key Points

- CAP Theorem applies to distributed systems.
    
- CAP stands for Consistency, Availability, and Partition Tolerance.
    
- During a partition, a system chooses between Consistency and Availability.
    
- CP systems prioritize correctness.
    
- AP systems prioritize uptime.
    
- True distributed CA systems are not practical during partitions.
    
- Most NoSQL databases are designed around CAP trade-offs.
    
- Eventual consistency is common in AP databases.
    
- CAP helps architects choose the right database for business requirements.
    

---

# Interview Summary

### What is CAP Theorem?

A distributed systems theorem stating that during a network partition, a system can guarantee either Consistency or Availability, but not both simultaneously.

---

### What does Consistency mean?

Every read receives the most recent write.

---

### What does Availability mean?

Every request receives a response, even during failures.

---

### What does Partition Tolerance mean?

The system continues functioning despite network communication failures between nodes.

---

### Why is Partition Tolerance important?

Network failures are unavoidable in distributed systems.

---

### What is the difference between CP and AP?

|CP|AP|
|---|---|
|Prioritizes correctness|Prioritizes uptime|
|May reject requests|Continues serving requests|
|Strong consistency|Eventual consistency|

---

### Give Examples of CP Databases

- MongoDB (strong consistency configurations)
    
- HBase
    
- ZooKeeper
    

---

### Give Examples of AP Databases

- Cassandra
    
- DynamoDB
    
- CouchDB
    
- Riak
    

---

# Conclusion

CAP Theorem is one of the most important concepts in distributed databases and NoSQL systems. It explains the unavoidable trade-offs between Consistency, Availability, and Partition Tolerance when network failures occur. Understanding CAP helps database architects choose the appropriate database technology and system design based on business requirements such as correctness, uptime, scalability, and fault tolerance.