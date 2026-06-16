# CRUD Operations in MongoDB (`insertOne`, `find`, `updateMany`, `deleteOne`)

## Definition

**CRUD** stands for:

- **C** → Create
    
- **R** → Read
    
- **U** → Update
    
- **D** → Delete
    

CRUD operations are the fundamental database operations used to manage data inside a collection.

In MongoDB, CRUD operations allow applications to:

- Store new documents
    
- Retrieve existing documents
    
- Modify existing documents
    
- Remove documents that are no longer needed
    

Every database-driven application—from e-commerce platforms to social media systems—uses CRUD operations extensively.

---

# Why CRUD Operations Exist

Applications continuously interact with data.

Examples:

|Application|CRUD Activity|
|---|---|
|E-Commerce|Create orders, read products, update inventory, delete expired carts|
|Banking|Create transactions, read balances, update accounts|
|Social Media|Create posts, read feeds, update profiles, delete comments|
|School Management|Create students, read records, update grades|

Without CRUD operations, applications would not be able to manage persistent data.

---

# Mental Model

Imagine a collection named `users`.

```javascript
[
  {
    _id: 1,
    name: "Ali",
    email: "ali@example.com"
  },
  {
    _id: 2,
    name: "Sara",
    email: "sara@example.com"
  }
]
```

CRUD operations work like this:

```text
Create → Add New User

Read → View Users

Update → Modify User Information

Delete → Remove User
```

---

# Sample Database Collection

Throughout this guide, assume the following collection.

## users Collection

```javascript
[
  {
    _id: 1,
    name: "Ali",
    age: 25,
    city: "Lahore",
    status: "Active"
  },
  {
    _id: 2,
    name: "Sara",
    age: 30,
    city: "Karachi",
    status: "Active"
  },
  {
    _id: 3,
    name: "Ahmed",
    age: 28,
    city: "Lahore",
    status: "Inactive"
  }
]
```

---

# CREATE Operation (`insertOne`)

## Purpose

Adds a new document to a collection.

---

## Syntax

```javascript
db.collection.insertOne(document);
```

---

## Basic Example

```javascript
db.users.insertOne({
  name: "Usman",
  age: 27,
  city: "Islamabad",
  status: "Active"
});
```

---

## Result

```javascript
{
  acknowledged: true,
  insertedId: ObjectId("...")
}
```

---

## Collection After Insert

```javascript
[
  {
    _id: 1,
    name: "Ali"
  },
  {
    _id: 2,
    name: "Sara"
  },
  {
    _id: 3,
    name: "Ahmed"
  },
  {
    _id: 4,
    name: "Usman"
  }
]
```

---

## Real-World Example: User Registration

```javascript
db.users.insertOne({
  username: "john123",
  email: "john@example.com",
  passwordHash: "encryptedPassword",
  createdAt: new Date()
});
```

---

## Internal Behavior

MongoDB:

1. Receives document
    
2. Generates `_id` if missing
    
3. Validates structure
    
4. Writes document to storage engine
    
5. Returns insertion result
    

---

## Common Mistake

### Incorrect

```javascript
db.users.insertOne();
```

### Problem

No document provided.

### Correct

```javascript
db.users.insertOne({
  name: "Ali"
});
```

---

# READ Operation (`find`)

## Purpose

Retrieves documents from a collection.

---

## Syntax

```javascript
db.collection.find(query);
```

---

## Retrieve All Documents

```javascript
db.users.find();
```

---

## Output

```javascript
[
  {
    _id: 1,
    name: "Ali"
  },
  {
    _id: 2,
    name: "Sara"
  }
]
```

---

## Find Specific User

```javascript
db.users.find({
  name: "Ali"
});
```

---

## Output

```javascript
[
  {
    _id: 1,
    name: "Ali",
    age: 25
  }
]
```

---

## Multiple Conditions

```javascript
db.users.find({
  city: "Lahore",
  status: "Active"
});
```

---

## Comparison Operators

### Users Older Than 25

```javascript
db.users.find({
  age: {
    $gt: 25
  }
});
```

---

## Projection

Retrieve only specific fields.

```javascript
db.users.find(
  {},
  {
    name: 1,
    city: 1,
    _id: 0
  }
);
```

---

## Output

```javascript
[
  {
    name: "Ali",
    city: "Lahore"
  }
]
```

---

## Internal Behavior

MongoDB:

1. Searches collection
    
2. Uses indexes if available
    
3. Filters matching documents
    
4. Returns cursor
    

---

## Key Points

- `find()` returns multiple documents
    
- Supports filtering
    
- Supports projections
    
- Can use indexes for fast lookups
    

---

# UPDATE Operation (`updateMany`)

## Purpose

Updates multiple matching documents.

---

## Syntax

```javascript
db.collection.updateMany(
  filter,
  update
);
```

---

## Basic Example

Update all users in Lahore.

```javascript
db.users.updateMany(
  {
    city: "Lahore"
  },
  {
    $set: {
      city: "Islamabad"
    }
  }
);
```

---

## Before Update

```javascript
[
  {
    name: "Ali",
    city: "Lahore"
  },
  {
    name: "Ahmed",
    city: "Lahore"
  }
]
```

---

## After Update

```javascript
[
  {
    name: "Ali",
    city: "Islamabad"
  },
  {
    name: "Ahmed",
    city: "Islamabad"
  }
]
```

---

## Increment Values

Increase age by 1.

```javascript
db.users.updateMany(
  {},
  {
    $inc: {
      age: 1
    }
  }
);
```

---

## Add New Field

```javascript
db.users.updateMany(
  {},
  {
    $set: {
      country: "Pakistan"
    }
  }
);
```

---

## Result

```javascript
{
  acknowledged: true,
  matchedCount: 3,
  modifiedCount: 3
}
```

---

## Internal Behavior

MongoDB:

1. Finds matching documents
    
2. Locks document level
    
3. Applies update operator
    
4. Writes changes
    
5. Updates indexes if necessary
    

---

## Common Mistake

### Incorrect

```javascript
db.users.updateMany(
  {
    city: "Lahore"
  },
  {
    city: "Islamabad"
  }
);
```

### Problem

Entire document replacement may occur.

### Correct

```javascript
db.users.updateMany(
  {
    city: "Lahore"
  },
  {
    $set: {
      city: "Islamabad"
    }
  }
);
```

---

# DELETE Operation (`deleteOne`)

## Purpose

Removes a single document.

---

## Syntax

```javascript
db.collection.deleteOne(filter);
```

---

## Basic Example

Delete a user.

```javascript
db.users.deleteOne({
  name: "Ahmed"
});
```

---

## Result

```javascript
{
  acknowledged: true,
  deletedCount: 1
}
```

---

## Collection After Delete

```javascript
[
  {
    name: "Ali"
  },
  {
    name: "Sara"
  }
]
```

---

## Real-World Example

Delete inactive users.

```javascript
db.users.deleteOne({
  status: "Inactive"
});
```

---

## Internal Behavior

MongoDB:

1. Searches matching document
    
2. Removes document
    
3. Updates indexes
    
4. Frees storage space
    

---

## Common Mistake

### Dangerous Query

```javascript
db.users.deleteOne({});
```

### Problem

Deletes the first document found.

### Safer Version

```javascript
db.users.deleteOne({
  _id: 3
});
```

---

# Step-by-Step CRUD Workflow

## Scenario: User Lifecycle

---

### Step 1: Create User

```javascript
db.users.insertOne({
  name: "Fatima",
  age: 24,
  city: "Karachi"
});
```

---

### Step 2: Read User

```javascript
db.users.find({
  name: "Fatima"
});
```

Output:

```javascript
[
  {
    name: "Fatima",
    age: 24
  }
]
```

---

### Step 3: Update User

```javascript
db.users.updateMany(
  {
    name: "Fatima"
  },
  {
    $set: {
      city: "Lahore"
    }
  }
);
```

---

### Step 4: Delete User

```javascript
db.users.deleteOne({
  name: "Fatima"
});
```

---

# Real-World Use Case 1: E-Commerce System

## Create Product

```javascript
db.products.insertOne({
  name: "Laptop",
  price: 1200,
  stock: 50
});
```

---

## Read Product

```javascript
db.products.find({
  name: "Laptop"
});
```

---

## Update Inventory

```javascript
db.products.updateMany(
  {
    name: "Laptop"
  },
  {
    $inc: {
      stock: -1
    }
  }
);
```

---

## Delete Product

```javascript
db.products.deleteOne({
  name: "Laptop"
});
```

---

# Real-World Use Case 2: Backend API

## Express.js Example

### Create User

```javascript
app.post("/users", async (req, res) => {
  const result = await db
    .collection("users")
    .insertOne(req.body);

  res.json(result);
});
```

---

### Read Users

```javascript
app.get("/users", async (req, res) => {
  const users = await db
    .collection("users")
    .find({})
    .toArray();

  res.json(users);
});
```

---

### Update Users

```javascript
app.put("/users/city", async (req, res) => {
  const result = await db
    .collection("users")
    .updateMany(
      { city: "Lahore" },
      {
        $set: {
          city: "Islamabad"
        }
      }
    );

  res.json(result);
});
```

---

### Delete User

```javascript
app.delete("/users/:id", async (req, res) => {
  const result = await db
    .collection("users")
    .deleteOne({
      _id: req.params.id
    });

  res.json(result);
});
```

---

# Edge Cases and Pitfalls

## Empty Collection

```javascript
db.users.find();
```

Output:

```javascript
[]
```

No error occurs.

---

## No Matching Documents

```javascript
db.users.deleteOne({
  name: "Unknown"
});
```

Output:

```javascript
{
  deletedCount: 0
}
```

---

## Updating Non-Existing Records

```javascript
db.users.updateMany(
  {
    city: "Unknown"
  },
  {
    $set: {
      city: "Lahore"
    }
  }
);
```

Output:

```javascript
{
  matchedCount: 0,
  modifiedCount: 0
}
```

---

## Duplicate Data

```javascript
db.users.insertOne({
  email: "ali@example.com"
});
```

Without a unique index, duplicates may occur.

---

# CRUD Operation Comparison

|Operation|Method|Purpose|Returns|
|---|---|---|---|
|Create|`insertOne()`|Add document|Insert result|
|Read|`find()`|Retrieve documents|Cursor|
|Update|`updateMany()`|Modify documents|Update result|
|Delete|`deleteOne()`|Remove document|Delete result|

---

# CRUD vs SQL

|SQL|MongoDB|
|---|---|
|INSERT|`insertOne()`|
|SELECT|`find()`|
|UPDATE|`updateMany()`|
|DELETE|`deleteOne()`|

---

# Common Mistakes

|Mistake|Problem|Fix|
|---|---|---|
|Missing `$set`|Replaces document|Use `$set`|
|Empty delete filter|Deletes unintended data|Use specific filters|
|No indexes|Slow queries|Create indexes|
|Assuming `find()` returns array|Returns cursor|Use `.toArray()` in applications|
|Ignoring update result|Hard to verify changes|Check `modifiedCount`|

---

# Performance Considerations

## Create Index for Frequent Searches

```javascript
db.users.createIndex({
  email: 1
});
```

---

## Good Query

```javascript
db.users.find({
  email: "ali@example.com"
});
```

Uses index efficiently.

---

## Poor Query

```javascript
db.users.find({
  age: {
    $gt: 20
  }
});
```

Without an index, a collection scan may occur.

---

# Key Points

- CRUD stands for Create, Read, Update, and Delete.
    
- `insertOne()` adds a document.
    
- `find()` retrieves documents.
    
- `updateMany()` modifies multiple documents.
    
- `deleteOne()` removes a single document.
    
- Filters determine which documents are affected.
    
- Update operators such as `$set` and `$inc` are commonly used.
    
- Indexes improve read performance.
    
- Always verify update and delete results.
    

---

# Interview Summary

### What does CRUD stand for?

Create, Read, Update, Delete.

---

### Which MongoDB method inserts a document?

```javascript
insertOne()
```

---

### Which method retrieves documents?

```javascript
find()
```

---

### Which method updates multiple documents?

```javascript
updateMany()
```

---

### Which method deletes one document?

```javascript
deleteOne()
```

---

### Why use `$set` in updates?

To modify specific fields without replacing the entire document.

---

### What does `find()` return?

A cursor containing matching documents.

---

### How can query performance be improved?

By creating indexes on frequently searched fields.

---

# Conclusion

CRUD operations form the foundation of MongoDB data management. `insertOne()` creates documents, `find()` retrieves data, `updateMany()` modifies existing records, and `deleteOne()` removes unwanted documents. Mastering these operations, understanding their internal behavior, and applying proper filtering and indexing strategies are essential skills for building efficient, scalable NoSQL applications.