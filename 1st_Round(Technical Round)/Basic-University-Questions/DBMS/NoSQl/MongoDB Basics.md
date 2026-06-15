# MongoDB Basics

## Definition

**MongoDB** is a NoSQL, document-oriented database that stores data in flexible, JSON-like documents instead of rows and columns.

Unlike traditional relational databases that use tables, MongoDB organizes data into:

- Databases
    
- Collections
    
- Documents
    

MongoDB is designed for:

- High performance
    
- Horizontal scalability
    
- Flexible schemas
    
- Rapid application development
    

---

# Why MongoDB Exists

Traditional relational databases are excellent for structured data, but modern applications often require:

- Rapid development
    
- Frequent schema changes
    
- Large volumes of data
    
- Distributed architectures
    
- High availability
    

MongoDB addresses these challenges by allowing documents to have different structures while maintaining efficient querying and scalability.

---

# Mental Model

Think of MongoDB as a digital filing cabinet.

```text
MongoDB Server
    |
    ├── Database
    |      |
    |      ├── Collection
    |      |      |
    |      |      ├── Document
    |      |      ├── Document
    |      |      └── Document
```

Comparison with a relational database:

|Relational Database|MongoDB|
|---|---|
|Database|Database|
|Table|Collection|
|Row|Document|
|Column|Field|

---

# Core MongoDB Components

---

## Database

A database contains collections.

Example:

```javascript
companyDB
```

---

## Collection

A collection stores documents.

Example:

```javascript
employees
```

---

## Document

A document is a single record stored as BSON (Binary JSON).

Example:

```javascript
{
  _id: 1,
  name: "Ali",
  department: "IT",
  salary: 75000
}
```

---

# MongoDB Data Structure

## Example Database

### Database

```javascript
companyDB
```

### Collection

```javascript
employees
```

### Documents

```javascript
[
  {
    _id: 1,
    name: "Ali",
    department: "IT",
    salary: 75000
  },
  {
    _id: 2,
    name: "Sara",
    department: "HR",
    salary: 65000
  }
]
```

---

# BSON (Binary JSON)

MongoDB internally stores documents as BSON.

Example Document:

```javascript
{
  _id: ObjectId("507f1f77bcf86cd799439011"),
  name: "Ahmed",
  age: 28,
  active: true,
  joinedDate: new Date()
}
```

BSON supports:

- Strings
    
- Numbers
    
- Arrays
    
- Dates
    
- Boolean values
    
- Nested objects
    
- ObjectIds
    

---

# Creating and Selecting Databases

## Create or Switch Database

```javascript
use companyDB
```

MongoDB creates the database automatically when data is inserted.

---

## View Current Database

```javascript
db
```

Output:

```javascript
companyDB
```

---

## List Databases

```javascript
show dbs
```

---

# Creating Collections

## Explicit Collection Creation

```javascript
db.createCollection("employees")
```

---

## Implicit Collection Creation

MongoDB automatically creates collections when data is inserted.

```javascript
db.employees.insertOne({
  name: "Ali"
})
```

---

# CRUD Operations Overview

CRUD stands for:

|Operation|Meaning|
|---|---|
|Create|Insert Data|
|Read|Retrieve Data|
|Update|Modify Data|
|Delete|Remove Data|

---

# Create Documents

## Syntax

```javascript
db.collection.insertOne(document)
```

---

## Example

```javascript
db.employees.insertOne({
  employeeId: 101,
  name: "Ali",
  department: "IT",
  salary: 75000
})
```

---

## Output

```javascript
{
  acknowledged: true,
  insertedId: ObjectId("...")
}
```

---

# Read Documents

## Retrieve All Documents

```javascript
db.employees.find()
```

---

## Find Specific Employee

```javascript
db.employees.find({
  department: "IT"
})
```

---

## Output

```javascript
[
  {
    employeeId: 101,
    name: "Ali",
    department: "IT"
  }
]
```

---

# Update Documents

## Syntax

```javascript
db.collection.updateOne(
  filter,
  update
)
```

---

## Example

Increase salary.

```javascript
db.employees.updateOne(
  {
    employeeId: 101
  },
  {
    $set: {
      salary: 80000
    }
  }
)
```

---

## Output

```javascript
{
  matchedCount: 1,
  modifiedCount: 1
}
```

---

# Delete Documents

## Syntax

```javascript
db.collection.deleteOne(filter)
```

---

## Example

```javascript
db.employees.deleteOne({
  employeeId: 101
})
```

---

## Output

```javascript
{
  deletedCount: 1
}
```

---

# Query Operators

MongoDB provides operators for filtering documents.

---

## Equal

```javascript
db.employees.find({
  department: "IT"
})
```

---

## Greater Than

```javascript
db.employees.find({
  salary: {
    $gt: 70000
  }
})
```

---

## Less Than

```javascript
db.employees.find({
  salary: {
    $lt: 90000
  }
})
```

---

## Multiple Conditions

```javascript
db.employees.find({
  department: "IT",
  salary: {
    $gt: 70000
  }
})
```

---

# Working with Nested Documents

## Example Document

```javascript
{
  employeeId: 101,
  name: "Ali",
  address: {
    city: "Lahore",
    country: "Pakistan"
  }
}
```

---

## Query Nested Field

```javascript
db.employees.find({
  "address.city": "Lahore"
})
```

---

# Working with Arrays

## Example Document

```javascript
{
  employeeId: 101,
  name: "Ali",
  skills: [
    "JavaScript",
    "MongoDB",
    "Node.js"
  ]
}
```

---

## Find by Array Value

```javascript
db.employees.find({
  skills: "MongoDB"
})
```

---

# MongoDB Indexes

## Why Indexes Matter

Without indexes:

```javascript
db.employees.find({
  employeeId: 101
})
```

MongoDB scans every document.

---

## Create Index

```javascript
db.employees.createIndex({
  employeeId: 1
})
```

---

## Internal Behavior

Without Index:

```text
Collection Scan
Document 1
Document 2
Document 3
...
```

With Index:

```text
Index Lookup
     |
     V
Matching Document
```

---

# Schema Flexibility

One of MongoDB's key advantages is flexible schemas.

---

## Document 1

```javascript
{
  employeeId: 101,
  name: "Ali"
}
```

---

## Document 2

```javascript
{
  employeeId: 102,
  name: "Sara",
  department: "HR",
  salary: 60000
}
```

Both can exist in the same collection.

---

# Step-by-Step Example

## Employee Management Database

---

### Step 1: Create Employee

```javascript
db.employees.insertOne({
  employeeId: 201,
  name: "Ahmed",
  department: "Finance",
  salary: 90000
})
```

---

### Step 2: Read Employee

```javascript
db.employees.find({
  employeeId: 201
})
```

Output:

```javascript
[
  {
    employeeId: 201,
    name: "Ahmed",
    department: "Finance"
  }
]
```

---

### Step 3: Update Salary

```javascript
db.employees.updateOne(
  {
    employeeId: 201
  },
  {
    $set: {
      salary: 95000
    }
  }
)
```

---

### Step 4: Delete Employee

```javascript
db.employees.deleteOne({
  employeeId: 201
})
```

---

# Real-World Use Case 1: E-Commerce Product Catalog

## Product Document

```javascript
{
  productId: 5001,
  name: "Laptop",
  category: "Electronics",
  price: 1200,
  specifications: {
    ram: "16GB",
    storage: "512GB SSD"
  }
}
```

---

## Query Products

```javascript
db.products.find({
  category: "Electronics"
})
```

---

## Why MongoDB?

Products often have different attributes.

---

# Real-World Use Case 2: User Profile System

## User Document

```javascript
{
  userId: 101,
  username: "ali123",
  email: "ali@example.com",
  preferences: {
    theme: "dark",
    language: "en"
  }
}
```

---

## Backend Example

```javascript
const user = await db
  .collection("users")
  .findOne({
    userId: 101
  });
```

Used in:

- Web applications
    
- Mobile applications
    
- REST APIs
    

---

# MongoDB vs SQL Databases

|Feature|MongoDB|SQL Database|
|---|---|---|
|Data Model|Document|Table|
|Schema|Flexible|Fixed|
|Scaling|Horizontal|Mostly Vertical|
|Joins|Limited|Strong|
|Data Format|BSON|Rows|
|Development Speed|Fast|Moderate|

---

# Common Mistakes

## Mistake 1: Forgetting Update Operators

### Incorrect

```javascript
db.employees.updateOne(
  {
    employeeId: 101
  },
  {
    salary: 90000
  }
)
```

### Problem

Entire document may be replaced.

### Correct

```javascript
db.employees.updateOne(
  {
    employeeId: 101
  },
  {
    $set: {
      salary: 90000
    }
  }
)
```

---

## Mistake 2: Missing Indexes

### Problem

```javascript
db.employees.find({
  email: "ali@example.com"
})
```

can become slow on millions of documents.

### Fix

```javascript
db.employees.createIndex({
  email: 1
})
```

---

## Mistake 3: Using MongoDB Like SQL

### Incorrect Design

```javascript
{
  customerId: 101
}
```

Store everything in separate collections and perform excessive joins.

### Better Design

```javascript
{
  customerId: 101,
  customerName: "Ali",
  city: "Lahore"
}
```

Embed related data when appropriate.

---

# Edge Cases and Pitfalls

## Empty Collection

```javascript
db.employees.find()
```

Output:

```javascript
[]
```

No error occurs.

---

## Duplicate Data

Without unique indexes:

```javascript
db.employees.insertOne({
  email: "ali@example.com"
})
```

Duplicate emails may occur.

---

## Missing Fields

```javascript
{
  employeeId: 101
}
```

Query:

```javascript
db.employees.find({
  department: "IT"
})
```

Document will not match.

---

# Internal Architecture Overview

MongoDB consists of:

```text
MongoDB Server
      |
      ├── Databases
      |
      ├── Collections
      |
      ├── Documents
      |
      └── Indexes
```

Data is stored using:

```text
BSON Storage Engine
```

Queries are processed through:

```text
Query Parser
      |
Query Optimizer
      |
Execution Engine
```

---

# Key Points

- MongoDB is a document-oriented NoSQL database.
    
- Data is stored as BSON documents.
    
- Collections store documents.
    
- Databases store collections.
    
- MongoDB supports flexible schemas.
    
- CRUD operations are the foundation of MongoDB usage.
    
- Indexes improve query performance.
    
- Nested documents and arrays are first-class features.
    
- Horizontal scaling is supported through sharding.
    
- Replication provides high availability.
    

---

# Interview Summary

### What is MongoDB?

A document-oriented NoSQL database that stores data in BSON documents.

---

### What is a collection?

A group of related documents.

---

### What is a document?

A JSON-like record stored inside a collection.

---

### What is BSON?

Binary JSON format used internally by MongoDB.

---

### Difference Between Collection and Table?

|SQL|MongoDB|
|---|---|
|Table|Collection|
|Row|Document|
|Column|Field|

---

### How does MongoDB scale?

Using horizontal scaling through sharding.

---

### Why are indexes important?

They allow fast document retrieval without scanning the entire collection.

---

### What are MongoDB's main advantages?

- Flexible schema
    
- High scalability
    
- Fast development
    
- JSON-like document model
    

---

# Conclusion

MongoDB is a leading NoSQL database designed for flexibility, scalability, and high-performance application development. By organizing data into databases, collections, and BSON documents, MongoDB enables developers to build modern applications that can handle changing requirements, large datasets, and distributed architectures. Understanding collections, documents, CRUD operations, indexes, and schema design forms the foundation for mastering MongoDB and advanced NoSQL concepts.