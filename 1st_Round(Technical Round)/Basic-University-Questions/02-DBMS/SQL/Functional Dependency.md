#  Functional Dependency in DBMS

---

##  Definition

A **Functional Dependency** in a database is a relationship between **two sets of attributes** in a table such that the value of one attribute **determines the value of another attribute**.

> If you know `A`, you can uniquely determine `B`.

A → B

If you know the student id then you can get student name, student numbers.

---

##  Why Functional Dependency Exists

Functional dependencies are crucial for:

- **Ensuring data integrity**
- **Avoiding anomalies** like insertion, deletion, and update anomalies

Without functional dependencies, databases can have **duplicate or inconsistent data**, making maintenance difficult.

---

##  Mental Model

Think of FD as a **cause-and-effect relationship**:

- `StudentID → StudentName`  
    Knowing the `StudentID` guarantees you know the `StudentName`.
- `EmployeeID → Department`  
    EmployeeID uniquely identifies the department of the employee.

---

##  Types of Functional Dependency

1. **Trivial FD**:
    - Right-hand side (RHS) is a subset of left-hand side (LHS)
    - Example: `A, B → A`
2. **Non-Trivial FD**:
    - RHS is **not** a subset of LHS
    - Example: `StudentID → StudentName`
3. **Fully Functional Dependency**:
    - Attribute depends on the **whole set** of attributes, not just part of it
    - Example: `(CourseID, StudentID) → Grade`
4. **Partial Dependency**:
    - Attribute depends on **part** of a composite key
    - Example: `(StudentID, CourseID) → StudentName` (StudentName depends only on StudentID)
5. **Transitive Dependency**:
    - A → B and B → C ⇒ A → C
    - Example: `StudentID → DepartmentID` and `DepartmentID → DepartmentName` ⇒ `StudentID → DepartmentName`

---

###  Real-World Example: E-commerce

~~~javascript
const orders = [  
  { orderId: 1001, customerId: 200, shippingAddress: 'NY' },  
  { orderId: 1002, customerId: 201, shippingAddress: 'LA' },  
];  
  
// Functional dependency:  
// orderId → customerId, shippingAddress
~~~
- Each `orderId` uniquely determines the customer and address.

---
##  Comparison Table

| Concept               | Determines       | Notes                          |
| --------------------- | ---------------- | ------------------------------ |
| Functional Dependency | RHS by LHS       | Basis for normalization        |
| Primary Key           | Unique row       | Special FD where LHS is PK     |
| Foreign Key           | References table | Enforces referential integrity |

---

##  Key Points

- Functional dependency = "knowledge of A gives B"
- Basis for **1NF, 2NF, 3NF normalization**
- Types:
    - Trivial, Non-Trivial
    - Full, Partial, Transitive
- Helps **eliminate redundancy and anomalies**

---

##  Interview Tips

- Be ready to:
    - Define FD clearly
    - Identify FDs in a table
    - Explain how FDs relate to **normal forms**
- Common question:

> "Is `A → B` a full functional dependency?"

---

##  Interview Summary

- Functional Dependency is foundational for **database normalization**
- Ensures:
    - Data integrity
    - No redundancy
    - Predictable relationships
- Recognize:
    - Trivial / Non-Trivial
    - Full / Partial / Transitive
- Used in **design, query optimization, and front/backend mapping**