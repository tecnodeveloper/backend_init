
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