# HTTP Methods ( GET, POST, PUT, DELETE )

---

## 1. Definition

HTTP methods define the type of action a client wants to perform on a server resource.

They are part of the HTTP protocol used in APIs and web applications.

The most common CRUD-related methods are:

|Method|Purpose|
|---|---|
|GET|Retrieve data|
|POST|Create new data|
|PUT|Update existing data|
|DELETE|Remove data|

> Mental Model:  
> GET = “Give me data”  
> POST = “Create something”  
> PUT = “Replace/update something”  
> DELETE = “Remove something”

---

## 2. Why HTTP Methods Exist

Web applications need standardized ways to communicate with servers.

HTTP methods help APIs:

- Organize operations clearly
    
- Separate reading from modifying data
    
- Improve security and maintainability
    
- Follow REST architecture principles
    

Without HTTP methods:

- Every request would behave unpredictably
    
- APIs would become difficult to understand
    
- Security and caching would be harder to manage
    

---

## 3. Common HTTP Methods

---

### 3.1 GET

Used to retrieve data from the server.

Characteristics:

- Read-only
    
- Should not modify data
    
- Parameters usually sent in URL
    
- Can be cached
    

Example:

```http
GET /users/1
```

Use Cases:

- Fetch user profile
    
- Load products
    
- Retrieve blog posts
    

---

### 3.2 POST

Used to create new resources on the server.

Characteristics:

- Sends data in request body
    
- Changes server state
    
- Not idempotent
    

Example:

```http
POST /users
```

Use Cases:

- Register user
    
- Create product
    
- Submit form
    

---

### 3.3 PUT

Used to update or replace an existing resource.

Characteristics:

- Updates entire resource
    
- Idempotent
    
- Sends updated data in body
    

Example:

```http
PUT /users/1
```

Use Cases:

- Update profile
    
- Replace product details
    
- Modify records
    

---

### 3.4 DELETE

Used to remove a resource.

Characteristics:

- Deletes existing resource
    
- Usually idempotent
    

Example:

```http
DELETE /users/1
```

Use Cases:

- Delete account
    
- Remove product
    
- Delete comment
    

---

## 4. CRUD Mapping

|CRUD Operation|HTTP Method|
|---|---|
|Create|POST|
|Read|GET|
|Update|PUT|
|Delete|DELETE|

---

## 5. GET vs POST vs PUT vs DELETE

|Feature|GET|POST|PUT|DELETE|
|---|---|---|---|---|
|Purpose|Retrieve data|Create data|Update data|Delete data|
|Request Body|Usually No|Yes|Yes|Optional|
|Changes Server Data|No|Yes|Yes|Yes|
|Idempotent|Yes|No|Yes|Yes|
|Cacheable|Yes|Rarely|Rarely|Rarely|
|Visible in URL|Often|No|No|No|

---

## 6. Syntax and Basic Examples

---

### 6.1 GET Request Example

```javascript
fetch("/users/1")
  .then(res => res.json())
  .then(data => console.log(data));
```

Explanation:

1. Client sends GET request
    
2. Server retrieves data
    
3. Response returned as JSON
    

---

### 6.2 POST Request Example

```javascript
fetch("/users", {
  method: "POST",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify({
    name: "Alice",
    email: "alice@example.com"
  })
});
```

Explanation:

1. Client sends new user data
    
2. Server creates resource
    
3. Server returns created object
    

---

### 6.3 PUT Request Example

```javascript
fetch("/users/1", {
  method: "PUT",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify({
    name: "Alice Updated",
    email: "alice@example.com"
  })
});
```

Explanation:

1. Client sends updated data
    
2. Server replaces existing resource
    
3. Updated resource stored
    

---

### 6.4 DELETE Request Example

```javascript
fetch("/users/1", {
  method: "DELETE"
});
```

Explanation:

1. Client requests deletion
    
2. Server removes resource
    
3. Success response returned
    

---

## 7. Internal Behavior

### GET

- Browser/API sends request
    
- Server reads database
    
- Data returned to client
    

### POST

- Client sends data in body
    
- Server validates input
    
- New resource created
    

### PUT

- Client sends updated resource
    
- Server replaces old data
    
- Updated version saved
    

### DELETE

- Server locates resource
    
- Resource removed from database
    
- Confirmation returned
    

---

## 8. Real-World Usage

---

### 8.1 Backend API Example (Express.js)

```javascript
import express from "express";

const app = express();

app.use(express.json());

// GET
app.get("/users", (req, res) => {
  res.send("Fetching users");
});

// POST
app.post("/users", (req, res) => {
  res.send("Creating user");
});

// PUT
app.put("/users/:id", (req, res) => {
  res.send("Updating user");
});

// DELETE
app.delete("/users/:id", (req, res) => {
  res.send("Deleting user");
});
```

---

### 8.2 Frontend API Calls

```javascript
// GET
fetch("/products");

// POST
fetch("/products", {
  method: "POST",
  body: JSON.stringify({ name: "Phone" })
});

// PUT
fetch("/products/1", {
  method: "PUT",
  body: JSON.stringify({ name: "Updated Phone" })
});

// DELETE
fetch("/products/1", {
  method: "DELETE"
});
```

---

## 9. Idempotency

An operation is **idempotent** if performing it multiple times produces the same result.

|Method|Idempotent|
|---|---|
|GET|Yes|
|POST|No|
|PUT|Yes|
|DELETE|Yes|

Example:

- Calling GET 10 times → same data retrieval
    
- Calling DELETE repeatedly → resource already deleted
    
- Calling POST repeatedly → creates multiple resources
    

---

## 10. Edge Cases and Pitfalls

- **Using GET for sensitive data**  
    → Query parameters visible in URL
    
- **Sending large data in GET**  
    → URL length limitations
    
- **Using POST instead of PUT for updates**  
    → Poor REST design consistency
    
- **DELETE without authorization**  
    → Dangerous security issue
    
- **Not validating request body**  
    → Invalid or malicious data stored
    

---

## 11. Security Considerations

|Issue|Risk|Fix|
|---|---|---|
|Sensitive data in URL|Data exposure|Use POST body|
|Missing authentication|Unauthorized access|Protect endpoints|
|No validation|Injection attacks|Validate/sanitize input|
|No HTTPS|Data interception|Use HTTPS|
|Unsafe DELETE routes|Data loss|Add authorization checks|

---

## 12. HTTP Status Codes

Common responses returned by APIs:

|Status Code|Meaning|
|---|---|
|200|Success|
|201|Resource created|
|400|Bad request|
|401|Unauthorized|
|403|Forbidden|
|404|Resource not found|
|500|Server error|

Example:

```javascript
res.status(201).json({
  message: "User created"
});
```

---

## 13. Common Mistakes (With Fixes)

|Mistake|Problem|Fix|
|---|---|---|
|Using GET to modify data|Breaks REST rules|Use POST/PUT/DELETE|
|No request validation|Invalid data stored|Validate inputs|
|Sending passwords in URL|Security risk|Send in POST body|
|Forgetting status codes|Poor API communication|Return proper HTTP codes|
|No authentication|Unauthorized actions|Secure endpoints|

---

## 14. Interview Tips / Summary

- **Difference between GET and POST?**  
    → GET retrieves data, POST creates data
    
- **What is PUT used for?**  
    → Updating/replacing existing resources
    
- **What does DELETE do?**  
    → Removes resources from server
    
- **Which methods are idempotent?**  
    → GET, PUT, DELETE
    
- **Why avoid sensitive data in GET?**  
    → URLs can be logged and exposed
    

---

## 15. Final Summary

- HTTP methods define actions between client and server
    
- GET retrieves data
    
- POST creates resources
    
- PUT updates resources
    
- DELETE removes resources
    
- Proper usage improves API clarity, scalability, and security
    
- Always validate input and secure endpoints with authentication and HTTPS