# Aggregation Framework Using Pipelines (`$match`, `$group`, `$sort`)

## Definition

The **MongoDB Aggregation Framework** is a powerful data processing system that allows you to transform, filter, group, analyze, and summarize documents stored in a collection.

It works by passing documents through a sequence of stages called a **pipeline**, where each stage performs a specific operation on the data.

The most commonly used stages are:

- `$match` → Filters documents
    
- `$group` → Groups documents and performs calculations
    
- `$sort` → Sorts documents
    

Think of it as a database version of a production assembly line where each stage modifies or processes data before passing it to the next stage.

---

# Why Aggregation Framework Exists

Traditional queries are useful for retrieving documents, but applications often need:

- Sales reports
    
- Analytics dashboards
    
- User statistics
    
- Revenue calculations
    
- Category summaries
    
- Ranking and leaderboards
    

Without aggregation:

- Large amounts of data must be fetched to the application
    
- Processing happens in backend code
    
- More memory and network bandwidth are consumed
    

Aggregation moves computation closer to the database, making operations faster and more efficient.

---

# Mental Model

Imagine a collection named `orders`.

```javascript
[
  { customer: "Ali", amount: 1000, status: "completed" },
  { customer: "Sara", amount: 2000, status: "completed" },
  { customer: "Ali", amount: 1500, status: "pending" }
]
```

Pipeline Flow:

```text
Documents
    |
    V
 $match
    |
    V
 $group
    |
    V
 $sort
    |
    V
 Result
```

Each stage receives the output of the previous stage.

---

# Basic Aggregation Syntax

```javascript
db.collection.aggregate([
  { stage1 },
  { stage2 },
  { stage3 }
]);
```

Example:

```javascript
db.orders.aggregate([
  { $match: { status: "completed" } },
  { $group: { _id: "$customer", total: { $sum: "$amount" } } },
  { $sort: { total: -1 } }
]);
```

---

# Sample Database Collection

Assume the following collection:

### orders

```javascript
[
  {
    _id: 1,
    customer: "Ali",
    product: "Laptop",
    category: "Electronics",
    amount: 1200,
    status: "completed"
  },
  {
    _id: 2,
    customer: "Sara",
    product: "Phone",
    category: "Electronics",
    amount: 800,
    status: "completed"
  },
  {
    _id: 3,
    customer: "Ali",
    product: "Mouse",
    category: "Accessories",
    amount: 50,
    status: "pending"
  },
  {
    _id: 4,
    customer: "Ahmed",
    product: "Keyboard",
    category: "Accessories",
    amount: 100,
    status: "completed"
  }
]
```

---

# Stage 1: `$match`

## Purpose

Filters documents based on specified criteria.

Similar to:

```javascript
db.orders.find()
```

but used inside an aggregation pipeline.

---

## Syntax

```javascript
{
  $match: {
    field: value
  }
}
```

---

## Example: Find Completed Orders

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed"
    }
  }
]);
```

### Output

```javascript
[
  {
    _id: 1,
    customer: "Ali",
    amount: 1200,
    status: "completed"
  },
  {
    _id: 2,
    customer: "Sara",
    amount: 800,
    status: "completed"
  },
  {
    _id: 4,
    customer: "Ahmed",
    amount: 100,
    status: "completed"
  }
]
```

---

## Using Conditions

```javascript
db.orders.aggregate([
  {
    $match: {
      amount: { $gt: 500 }
    }
  }
]);
```

### Meaning

```text
amount > 500
```

---

## Multiple Conditions

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed",
      amount: { $gt: 500 }
    }
  }
]);
```

---

## Key Points

- Reduces data early
    
- Improves performance
    
- Similar to SQL WHERE clause
    
- Usually placed at the beginning of the pipeline
    

---

# Stage 2: `$group`

## Purpose

Groups documents by a field and performs aggregate calculations.

Similar to SQL:

```sql
GROUP BY
```

---

## Syntax

```javascript
{
  $group: {
    _id: "$fieldName",
    resultField: {
      accumulator
    }
  }
}
```

---

## Common Accumulators

|Accumulator|Purpose|
|---|---|
|`$sum`|Total value|
|`$avg`|Average|
|`$max`|Maximum|
|`$min`|Minimum|
|`$push`|Store values in array|
|`$addToSet`|Store unique values|
|`$first`|First value|
|`$last`|Last value|

---

# Example: Total Sales Per Customer

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$customer",
      totalSales: {
        $sum: "$amount"
      }
    }
  }
]);
```

### Output

```javascript
[
  {
    _id: "Ali",
    totalSales: 1250
  },
  {
    _id: "Sara",
    totalSales: 800
  },
  {
    _id: "Ahmed",
    totalSales: 100
  }
]
```

---

# Example: Average Order Value

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$customer",
      averageAmount: {
        $avg: "$amount"
      }
    }
  }
]);
```

---

# Example: Count Documents

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$status",
      totalOrders: {
        $sum: 1
      }
    }
  }
]);
```

### Output

```javascript
[
  {
    _id: "completed",
    totalOrders: 3
  },
  {
    _id: "pending",
    totalOrders: 1
  }
]
```

---

# Grouping by Multiple Fields

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: {
        category: "$category",
        status: "$status"
      },
      totalAmount: {
        $sum: "$amount"
      }
    }
  }
]);
```

---

## Mental Model

Input:

```javascript
[
  { customer: "Ali", amount: 100 },
  { customer: "Ali", amount: 200 },
  { customer: "Sara", amount: 300 }
]
```

Grouping:

```text
Ali  -> [100, 200]
Sara -> [300]
```

Aggregation:

```text
Ali  -> 300
Sara -> 300
```

---

# Stage 3: `$sort`

## Purpose

Sorts documents in ascending or descending order.

Equivalent to SQL:

```sql
ORDER BY
```

---

## Syntax

```javascript
{
  $sort: {
    field: 1
  }
}
```

### Values

|Value|Meaning|
|---|---|
|1|Ascending|
|-1|Descending|

---

## Example: Sort Orders by Amount

```javascript
db.orders.aggregate([
  {
    $sort: {
      amount: -1
    }
  }
]);
```

### Output

```javascript
[
  { amount: 1200 },
  { amount: 800 },
  { amount: 100 },
  { amount: 50 }
]
```

---

## Multiple Sort Fields

```javascript
db.orders.aggregate([
  {
    $sort: {
      category: 1,
      amount: -1
    }
  }
]);
```

MongoDB first sorts by:

```text
category
```

Then within each category:

```text
amount
```

---

# Combining `$match`, `$group`, and `$sort`

This is the most common aggregation pattern.

---

## Scenario

Find total completed sales per customer and rank customers by sales.

---

## Pipeline

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed"
    }
  },
  {
    $group: {
      _id: "$customer",
      totalSales: {
        $sum: "$amount"
      }
    }
  },
  {
    $sort: {
      totalSales: -1
    }
  }
]);
```

---

## Step-by-Step Breakdown

### Step 1: `$match`

Input:

```javascript
[
  { customer: "Ali", amount: 1200, status: "completed" },
  { customer: "Sara", amount: 800, status: "completed" },
  { customer: "Ali", amount: 50, status: "pending" }
]
```

Output:

```javascript
[
  { customer: "Ali", amount: 1200, status: "completed" },
  { customer: "Sara", amount: 800, status: "completed" }
]
```

---

### Step 2: `$group`

Output:

```javascript
[
  {
    _id: "Ali",
    totalSales: 1200
  },
  {
    _id: "Sara",
    totalSales: 800
  }
]
```

---

### Step 3: `$sort`

Output:

```javascript
[
  {
    _id: "Ali",
    totalSales: 1200
  },
  {
    _id: "Sara",
    totalSales: 800
  }
]
```

---

# Real-World Use Case 1: E-Commerce Sales Dashboard

Requirement:

- Show top customers by revenue
    

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed"
    }
  },
  {
    $group: {
      _id: "$customer",
      revenue: {
        $sum: "$amount"
      }
    }
  },
  {
    $sort: {
      revenue: -1
    }
  }
]);
```

Backend API:

```javascript
const topCustomers = await db
  .collection("orders")
  .aggregate([
    {
      $match: {
        status: "completed"
      }
    },
    {
      $group: {
        _id: "$customer",
        revenue: {
          $sum: "$amount"
        }
      }
    },
    {
      $sort: {
        revenue: -1
      }
    }
  ])
  .toArray();
```

---

# Real-World Use Case 2: Product Category Analytics

Requirement:

Find revenue generated by each category.

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$category",
      totalRevenue: {
        $sum: "$amount"
      }
    }
  },
  {
    $sort: {
      totalRevenue: -1
    }
  }
]);
```

Frontend Dashboard Output:

```javascript
[
  {
    category: "Electronics",
    revenue: 50000
  },
  {
    category: "Accessories",
    revenue: 12000
  }
]
```

Used for:

- Admin dashboards
    
- Sales reports
    
- Business intelligence
    

---

# Internal Behavior

Understanding how MongoDB executes pipelines helps optimize performance.

---

## `$match`

MongoDB:

1. Reads documents
    
2. Uses indexes if available
    
3. Filters matching documents
    

Example index:

```javascript
db.orders.createIndex({
  status: 1
});
```

This allows `$match` to avoid scanning every document.

---

## `$group`

MongoDB:

1. Creates groups in memory
    
2. Maintains accumulator values
    
3. Produces grouped output
    

Example:

```javascript
{
  _id: "Ali",
  totalSales: 1250
}
```

is built incrementally as documents are processed.

---

## `$sort`

MongoDB:

1. Reads pipeline output
    
2. Sorts documents
    
3. Returns ordered results
    

Large sorts may spill to disk if memory limits are exceeded.

---

# Pipeline Optimization

## Good

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed"
    }
  },
  {
    $group: {
      _id: "$customer",
      total: {
        $sum: "$amount"
      }
    }
  }
]);
```

---

## Bad

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$customer",
      total: {
        $sum: "$amount"
      }
    }
  },
  {
    $match: {
      total: {
        $gt: 1000
      }
    }
  }
]);
```

Why bad?

```text
All documents are grouped first.
Filtering happens later.
More memory and CPU are used.
```

---

# Common Mistakes

## Mistake 1: Forgetting `$`

### Incorrect

```javascript
{
  $group: {
    _id: "customer"
  }
}
```

### Problem

```text
Groups everything into a single group named "customer"
```

### Correct

```javascript
{
  $group: {
    _id: "$customer"
  }
}
```

---

## Mistake 2: Wrong Sort Direction

### Incorrect

```javascript
{
  $sort: {
    amount: "DESC"
  }
}
```

### Correct

```javascript
{
  $sort: {
    amount: -1
  }
}
```

---

## Mistake 3: Grouping Too Early

### Incorrect

```javascript
db.orders.aggregate([
  {
    $group: {
      _id: "$customer"
    }
  },
  {
    $match: {
      status: "completed"
    }
  }
]);
```

### Correct

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "completed"
    }
  },
  {
    $group: {
      _id: "$customer"
    }
  }
]);
```

---

# Edge Cases and Pitfalls

## Null Values

Data:

```javascript
[
  { customer: "Ali" },
  { customer: null },
  {}
]
```

Grouping:

```javascript
{
  $group: {
    _id: "$customer"
  }
}
```

Output:

```javascript
[
  { _id: "Ali" },
  { _id: null }
]
```

Missing fields become `null`.

---

## Empty Result Set

```javascript
db.orders.aggregate([
  {
    $match: {
      status: "cancelled"
    }
  }
]);
```

Output:

```javascript
[]
```

No error occurs.

---

## Large Group Operations

```javascript
{
  $group: {
    _id: "$customer"
  }
}
```

If millions of unique customers exist:

- Memory consumption increases
    
- Execution time increases
    
- Disk usage may occur
    

---

# Comparison with Related Concepts

|Feature|find()|Aggregation|
|---|---|---|
|Filter Documents|Yes|Yes|
|Group Data|No|Yes|
|Calculate Totals|No|Yes|
|Average Values|No|Yes|
|Sort Data|Yes|Yes|
|Analytics|Limited|Powerful|
|Multi-Stage Processing|No|Yes|

---

# Key Points

- Aggregation Framework processes data through pipeline stages.
    
- `$match` filters documents.
    
- `$group` groups documents and performs calculations.
    
- `$sort` orders results.
    
- Place `$match` as early as possible.
    
- `$group` is equivalent to SQL `GROUP BY`.
    
- `$sort` uses `1` for ascending and `-1` for descending.
    
- Aggregation reduces application-side processing.
    
- Indexes improve `$match` performance.
    
- Proper stage ordering significantly impacts performance.
    

---

# Interview Summary

### What is the Aggregation Framework?

A MongoDB feature that processes documents through a sequence of pipeline stages to transform, analyze, and summarize data.

---

### What does `$match` do?

Filters documents, similar to SQL `WHERE`.

---

### What does `$group` do?

Groups documents and performs aggregate calculations such as sum, average, count, minimum, and maximum.

---

### What does `$sort` do?

Orders documents in ascending (`1`) or descending (`-1`) order.

---

### Why place `$match` first?

It reduces the number of documents processed by later stages, improving performance.

---

### What is `_id` in `$group`?

The grouping key that determines how documents are grouped together.

Example:

```javascript
{
  $group: {
    _id: "$customer"
  }
}
```

Groups all documents by customer name.

---

### Difference Between SQL and MongoDB Aggregation

|SQL|MongoDB|
|---|---|
|WHERE|`$match`|
|GROUP BY|`$group`|
|ORDER BY|`$sort`|
|Aggregate Functions|Accumulators (`$sum`, `$avg`, etc.)|
|Query Execution|Pipeline Execution|

---

# Conclusion

The MongoDB Aggregation Framework provides a structured pipeline-based approach to processing data. The combination of `$match`, `$group`, and `$sort` forms the foundation of most reporting, analytics, dashboard, and business intelligence workloads. Understanding how these stages interact, how MongoDB executes them internally, and how to optimize their order is essential for designing efficient and scalable NoSQL database solutions.