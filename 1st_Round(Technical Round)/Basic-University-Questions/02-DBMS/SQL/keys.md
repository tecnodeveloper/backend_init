##   Definition

**Keys in DBMS are attributes (or sets of attributes) used to uniquely identify records (rows)** in a table and **establish relationships** between tables.

---

##  Why Do Keys Exist?

Imagine a table of users:

|name|email|
|---|---|
|Ali|ali@gmail.com|
|Ali|ali123@gmail.com|

If we want to uniquely identify a user, using `name` is not enough. We need something **unique and reliable**.

---
##  Mental Model

Think of a key like:

- A **CNIC number** (unique per person)
- A **roll number** (unique per student)
- A **product barcode**

Without keys:

> A database is just messy data with no reliable way to find or relate records.

---

##  Types of Keys in DBMS

### 1. Primary Key
### 2. Candidate Key
### 3. Super Key
### 4. Alternate Key

### 5. Foreign Key
### 6. Composite Key

---

##  1. Primary Key

### Definition

A **Primary Key** uniquely identifies each record in a table.

### Rules:

- Must be **unique**
- Cannot be **NULL**
- Only **one primary key per table**

### Example

// SQL representation 
const query = `  
CREATE TABLE Users (  
  id INT PRIMARY KEY,  
  name VARCHAR(50),  
  email VARCHAR(100)  
);  
`;

### Mental Model

> Primary Key = "Main identity card of a row"

---

##  2. Candidate Key

### Definition

All possible attributes that can uniquely identify records.

### Example

|id|email|phone|
|---|---|---|
|1|a@gmail.com|123|

- `id`, `email`, and `phone` can all uniquely identify a row.

 These are **candidate key**
if you pick id as primary key then all others are alternative key

---

##  3. Super Key

### Definition

A **super key** is any combination of attributes that uniquely identifies a row.
### Example

// Super keys:  
{id}  
{id, name}  
{id, email}  
{id, name, email}

 All are super keys, but not all are minimal.

---

##  5. Foreign Key

### Definition

A **foreign key** is used to link one table to another.
### Example

const query = `  
CREATE TABLE Orders (  
  order_id INT PRIMARY KEY,  
  user_id INT,  
  FOREIGN KEY (user_id) REFERENCES Users(id)  
);  
`;

 `user_id` refers to `Users.id`
### Mental Model

> Foreign Key = "Reference to another table's identity"

---
##  6. Composite Key

### Definition

A key made of **multiple columns**

### Example

const query = `  
CREATE TABLE Enrollments (  
  student_id INT,  
  course_id INT,  
  PRIMARY KEY (student_id, course_id)  
);  
`;

 A student can enroll in multiple courses, but combination must be unique.

---

##  Syntax Summary

// Primary Key  
PRIMARY KEY (column_name)  
  
// Foreign Key  
FOREIGN KEY (column_name) REFERENCES table(column)  
  
// Composite Key  
PRIMARY KEY (col1, col2)  
  
// Unique (Candidate/Alternate)  
UNIQUE (column_name)

---

##  Examples

---

###  Basic Example

const usersTable = `  
CREATE TABLE Users (  
  id INT PRIMARY KEY,  
  name VARCHAR(50)  
);  
`;

---

###  Intermediate Example

const ordersTable = `  
CREATE TABLE Orders (  
  order_id INT PRIMARY KEY,  
  user_id INT,  
  FOREIGN KEY (user_id) REFERENCES Users(id)  
);  
`;

---

###  Real-World Example: E-commerce

const schema = `  
CREATE TABLE Products (  
  product_id INT PRIMARY KEY,  
  name VARCHAR(100)  
);  
  
CREATE TABLE Orders (  
  order_id INT PRIMARY KEY,  
  product_id INT,  
  FOREIGN KEY (product_id) REFERENCES Products(product_id)  
);  
`;

### Step-by-Step:

1. `Products` table stores items
2. `Orders` table references products
3. `product_id` connects both tables
4. Ensures valid product is always used

---

##  Edge Cases & Pitfalls

### 1. Duplicate Primary Key

 Wrong:

INSERT INTO Users VALUES (1, 'Ali');  
INSERT INTO Users VALUES (1, 'Ahmed'); //  duplicate

Fix:

INSERT INTO Users VALUES (2, 'Ahmed');

---

### 2. NULL in Primary Key

 Wrong:

INSERT INTO Users (id, name) VALUES (NULL, 'Ali');

 Not allowed

---

### 3. Foreign Key Constraint Failure

 Wrong:

INSERT INTO Orders VALUES (1, 999); // user doesn't exist

Fix:

// First ensure user exists  
INSERT INTO Users VALUES (999, 'Test');

---

##  Comparison Table

| Key Type      | Unique | NULL Allowed | Purpose           |
| ------------- | ------ | ------------ | ----------------- |
| Primary Key   |  Yes   | No           | Main identifier   |
| Candidate Key | Yes    | No           | Possible PKs      |
| Super Key     | Yes    | No           | Any unique combo  |
| Alternate Key | Yes    | No           | Backup unique key |
| Foreign Key   | No     | Yes          | Link tables       |
| Composite Key | Yes    | No           | Multi-column PK   |

---

##  Real-World Usage

### 1. Backend (Node.js + Database)

// Example: fetching user orders  
const userId = 1;  
  
const query = `  
SELECT * FROM Orders  
WHERE user_id = ${userId}  
`;

 Uses **foreign key relationship**

---
##  Key Points

- Keys ensure **uniqueness and integrity**
- Primary key is the **main identifier**
- Foreign key connects **tables together**
- Composite key uses **multiple columns**
- Candidate keys are **all possible unique identifiers**

---

##  Common Mistakes

### Mistake 1: Using non-unique column as primary key

PRIMARY KEY (name)
 Fix:   PRIMARY KEY (id)

---

### Mistake 2: Forgetting Foreign Key Constraints

 Leads to:
- Orphan records
- Broken relationships

 Always define:
-  FOREIGN KEY (...) REFERENCES ...

---

### Mistake 3: Overusing Composite Keys

- Makes queries complex
- Single primary key + unique constraints

---

##  Interview Tips

- Always mention:
    - **Primary Key = unique + not null**
    - **Foreign Key = relationship**
- Be ready to explain:
    - Difference between **candidate vs primary key**
    - Why **indexes matter**
- Common question:
    
    > "Can a table have multiple primary keys?"  
    >  No, only one (can be composite)
    

---

##  Interview Summary

- Keys are fundamental to **database design**
- They enforce:
    - Uniqueness
    - Relationships
    - Data consistency
- Types:
    - Primary, Foreign, Candidate, Super, Alternate, Composite
- Used in:
    - Backend systems
    - APIs
    - Real-world data modeling

---
