
# Authorization Techniques

---

## 1. Definition

**Authorization** is the process of determining what an authenticated user is allowed to do.  
It controls **access to resources** and operations based on roles, attributes, or permissions.

> Mental Model:  
> Authentication = “Who are you?”  
> Authorization = “What can you do?”

---

## 2. Why Authorization Exists

Without proper authorization:

- Users could access sensitive resources they shouldn’t  
- Systems can suffer data leaks or misuse  
- Compliance and audit requirements may fail  

Authorization ensures:

- Controlled access to resources  
- Separation of duties  
- Security and compliance enforcement  

---

## 3. Common Techniques

### 3.1 Role-Based Access Control (RBAC)

- Users are assigned **roles** (e.g., Admin, Editor, Viewer)  
- Each role has **permissions** associated with actions  
- Simple to manage for medium to large systems

```javascript
// Example: RBAC in JavaScript
const roles = {
  admin: ["create", "read", "update", "delete"],
  editor: ["read", "update"],
  viewer: ["read"]
};

function canPerform(userRole, action) {
  return roles[userRole]?.includes(action);
}

console.log(canPerform("editor", "delete")); // false
console.log(canPerform("admin", "delete"));  // true
````

---

### 3.2 Attribute-Based Access Control (ABAC)

- Access decisions based on **user attributes**, **resource attributes**, and **environmental conditions**
    
- More flexible than RBAC
    
- Example: Allow users to edit documents only if they belong to the same department
    

```javascript
// Example: ABAC in JavaScript
const user = { id: 1, department: "sales" };
const document = { id: 101, ownerDept: "sales" };

function canEdit(user, doc) {
  return user.department === doc.ownerDept;
}

console.log(canEdit(user, document)); // true
```

---

### 3.3 Permission Management and Access Levels

- Fine-grained control over specific operations
    
- Example: "Read-only", "Write", "Delete" permissions
    
- Often combined with RBAC or ABAC
    

```javascript
// Example: Permission check
const permissions = {
  alice: ["read", "write"],
  bob: ["read"]
};

function hasPermission(user, action) {
  return permissions[user]?.includes(action);
}

console.log(hasPermission("bob", "write")); // false
console.log(hasPermission("alice", "write")); // true
```

---

## 4. Internal Behavior

- **RBAC**: System checks role → maps to allowed actions → grant/deny
    
- **ABAC**: System evaluates attributes and rules dynamically
    
- **Permissions**: Explicit checks on resource and user level
    
- Most systems implement **middleware or guards** to enforce authorization
    

---

## 5. Real-World Usage

### 5.1 Backend: Protecting API Endpoints

```javascript
function authorize(action) {
  return (req, res, next) => {
    if (!canPerform(req.user.role, action)) {
      return res.status(403).send("Forbidden");
    }
    next();
  };
}

// Usage
app.delete("/user/:id", authorize("delete"), (req, res) => {
  // delete user logic
});
```

### 5.2 Frontend: Conditional Rendering

```javascript
// Show/hide UI elements based on role
const userRole = "viewer";
if (canPerform(userRole, "update")) {
  console.log("Show edit button");
} else {
  console.log("Hide edit button");
}
```

---

## 6. Edge Cases and Pitfalls

1. **Role Explosion in RBAC**
    
    - Problem: Too many roles → hard to manage
        
    - Fix: Combine RBAC with permissions or ABAC
        
2. **Attribute Conflicts in ABAC**
    
    - Problem: Conflicting rules → inconsistent access
        
    - Fix: Define clear rule precedence
        
3. **Direct access bypassing UI**
    
    - Problem: Users manipulate API requests
        
    - Fix: Always enforce authorization on the backend
        

---

## 7. Key Points

- Authorization = access control based on roles, attributes, or permissions
    
- RBAC: Simple role-based management
    
- ABAC: Dynamic, attribute-driven rules
    
- Permissions: Fine-grained, explicit access control
    
- Always enforce on server-side, not only UI
    

---

## 8. Common Mistakes (With Fixes)

|Mistake|Problem|Fix|
|---|---|---|
|Only enforcing on frontend|Users can bypass with API calls|Enforce authorization on backend|
|Too many roles (RBAC)|Hard to maintain|Combine with permissions or ABAC|
|Conflicting attribute rules (ABAC)|Inconsistent access|Define precedence and clear policies|
|Missing permission checks|Unauthorized actions possible|Check permissions for every critical action|

---

## 9. Interview Tips / Summary

- **Difference between RBAC and ABAC**  
    → RBAC: role-based, static  
    → ABAC: attribute-based, dynamic
    
- **When to use RBAC vs ABAC**  
    → RBAC: simple, small-medium applications  
    → ABAC: complex rules, dynamic conditions
    
- **Best practices**  
    → Always enforce backend checks, combine techniques if needed, avoid direct user manipulation
    

---

## 10. Final Summary

- Authorization ensures authenticated users access only what they are allowed
    
- RBAC = role-based, simple management
    
- ABAC = flexible, dynamic attribute-based rules
    
- Permissions = fine-grained access
    
- Always enforce consistently on backend and combine methods for complex systems

---
# Security Best Practices

---

## 1. Definition

**Security Best Practices** for authentication and authorization are measures and techniques used to protect user data, prevent unauthorized access, and ensure system integrity.

> Mental Model: Security best practices are like the locks, alarms, and safes in a building—protecting assets and controlling access.

---

## 2. Why Security Best Practices Exist

Without proper security:

- User credentials can be stolen
- Unauthorized access can occur
- Sensitive data may be leaked
- Applications can be exploited

Best practices ensure:

- Confidentiality, integrity, and availability (CIA)
- Regulatory compliance
- Trustworthy user experience

---

## 3. Password Hashing, Salting, and Secure Storage

### 3.1 Password Hashing

- Converts plain text password into a fixed-length, irreversible string  
- Protects against password theft if database is compromised

```javascript
import bcrypt from "bcryptjs";

async function hashPassword(password) {
  return await bcrypt.hash(password, 10);
}

async function verifyPassword(inputPassword, hashedPassword) {
  return await bcrypt.compare(inputPassword, hashedPassword);
}
````

### 3.2 Salting

- Adds a random string to password before hashing
    
- Prevents attackers from using precomputed hash tables (rainbow tables)
    

```javascript
const saltRounds = 12;
const hashed = await bcrypt.hash("userpassword", saltRounds);
```

### 3.3 Secure Storage

- Never store plain text passwords
    
- Store only hashed + salted passwords in database
    
- Protect database access using firewalls and least privilege
    

---

## 4. Refresh Tokens and Token Expiry Management

- **Access Tokens**: Short-lived tokens for API access
    
- **Refresh Tokens**: Long-lived tokens to request new access tokens
    

```javascript
import jwt from "jsonwebtoken";

const ACCESS_SECRET = "access_secret";
const REFRESH_SECRET = "refresh_secret";

// Generate access token
const accessToken = jwt.sign({ userId: 1 }, ACCESS_SECRET, { expiresIn: "15m" });

// Generate refresh token
const refreshToken = jwt.sign({ userId: 1 }, REFRESH_SECRET, { expiresIn: "7d" });

// Refresh token endpoint
function refreshAccessToken(token) {
  try {
    const payload = jwt.verify(token, REFRESH_SECRET);
    return jwt.sign({ userId: payload.userId }, ACCESS_SECRET, { expiresIn: "15m" });
  } catch (err) {
    throw new Error("Invalid refresh token");
  }
}
```

**Step-by-Step Breakdown**

1. User logs in → server issues access + refresh tokens
    
2. Client uses access token for requests
    
3. When access token expires → use refresh token to get new access token
    
4. Refresh token can be revoked if suspicious activity occurs
    

---

## 5. Preventing Unauthorized Access

### 5.1 CSRF (Cross-Site Request Forgery)

- Attack where unauthorized commands are transmitted from a user’s browser
    
- Prevention: Use **CSRF tokens**, **SameSite cookies**, and verify origin headers
    

```javascript
// Express CSRF middleware
import csurf from "csurf";
app.use(csurf());
```

### 5.2 XSS (Cross-Site Scripting)

- Injecting malicious scripts into web pages
    
- Prevention: Escape output, use **Content Security Policy (CSP)**
    

```javascript
// Example: Sanitizing user input
import DOMPurify from "dompurify";
const cleanInput = DOMPurify.sanitize(userInput);
```

### 5.3 Replay Attacks

- Reusing intercepted credentials or tokens
    
- Prevention:
    
    - Short-lived access tokens
        
    - Nonces or timestamps
        
    - HTTPS to encrypt traffic
        

---

## 6. Real-World Usage

### 6.1 Backend: Secure Login Flow

```javascript
app.post("/login", async (req, res) => {
  const user = await getUser(req.body.email);
  if (!user || !await bcrypt.compare(req.body.password, user.password)) {
    return res.status(401).send("Invalid credentials");
  }

  const accessToken = jwt.sign({ userId: user.id }, ACCESS_SECRET, { expiresIn: "15m" });
  const refreshToken = jwt.sign({ userId: user.id }, REFRESH_SECRET, { expiresIn: "7d" });

  res.cookie("refreshToken", refreshToken, { httpOnly: true, secure: true });
  res.json({ accessToken });
});
```

### 6.2 Frontend: Safe Token Storage

```javascript
// Store refresh token in HTTP-only cookie
// Store access token in memory (avoid localStorage for XSS safety)
let accessToken = null;
function setAccessToken(token) {
  accessToken = token;
}

// Send request with access token
fetch("/api/data", {
  headers: { "Authorization": `Bearer ${accessToken}` }
});
```

---

## 7. Edge Cases and Pitfalls

1. **Storing sensitive tokens in localStorage** → XSS risk
    
2. **Long-lived access tokens** → replay attack vulnerability
    
3. **Reusing passwords across sites** → weak protection
    
4. **Not validating CSRF/XSS** → allows session hijacking
    

---

## 8. Key Points

- Always hash and salt passwords before storage
    
- Use short-lived access tokens + refresh tokens
    
- Implement CSRF and XSS protections
    
- Use HTTPS and secure cookies
    
- Monitor and rotate credentials regularly
    

---

## 9. Common Mistakes (With Fixes)

|Mistake|Problem|Fix|
|---|---|---|
|Storing plain passwords|Immediate compromise if DB leaks|Use bcrypt/argon2 + salt|
|Storing JWT in localStorage|XSS vulnerability|Use HTTP-only secure cookies|
|Long-lived access tokens|Replay attacks|Use short-lived tokens + refresh tokens|
|Missing CSRF/XSS protection|Session hijacking / script injection|Implement CSRF tokens, escape outputs|
|Reusing tokens after logout|Unauthorized continued access|Invalidate refresh tokens on logout|

---

## 10. Interview Tips / Summary

- **Why hash and salt passwords?** → Prevent dictionary/rainbow table attacks
    
- **JWT best practices?** → Short-lived, refresh token, HTTPS, secure storage
    
- **How to prevent CSRF and XSS?** → Tokens, SameSite cookies, input sanitization
    
- **Replay attack prevention?** → Short-lived tokens, HTTPS, nonces
    

---

## 11. Final Summary

- Secure authentication requires hashing, salting, and safe storage
    
- Tokens should have expirations and proper refresh mechanisms
    
- Protect against CSRF, XSS, and replay attacks
    
- Always enforce security on backend, never trust client inputs