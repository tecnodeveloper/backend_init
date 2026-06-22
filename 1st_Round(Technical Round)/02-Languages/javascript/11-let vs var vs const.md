# JavaScript let vs var vs const

JavaScript provides three ways to declare variables:

- `var`
- `let`
- `const`

They differ in **scope, redeclaration, reassignment, and hoisting behavior**.

---

# var

`var` was the original way to declare variables in JavaScript.

### Example

```javascript
var name = "John"
```

### Characteristics

- Function scoped
- Can be **redeclared**
- Can be **reassigned**
- Gets **hoisted** with an initial value of `undefined`

### Example

```javascript
var a = 10
var a = 20   // allowed

a = 30       // allowed
```

### Scope Example

```javascript
function test(){
  var x = 10
}

console.log(x) // ReferenceError
```

`var` is limited to **function scope**, not block scope.

---

# let

`let` was introduced in **ES6 (2015)** to fix problems with `var`.

### Example

```javascript
let age = 25
```

### Characteristics

- **Block scoped**
- Cannot be **redeclared in the same scope**
- Can be **reassigned**

### Example

```javascript
let a = 10
a = 20   // allowed
```

### Invalid Redeclaration

```javascript
let a = 10
let a = 20 // SyntaxError
```

### Block Scope Example

```javascript
{
  let x = 10
}

console.log(x) // ReferenceError
```

---

# const

`const` is used for variables that **should not be reassigned**.

### Example

```javascript
const PI = 3.14
```

### Characteristics

- **Block scoped**
- Cannot be **redeclared**
- Cannot be **reassigned**
- Must be **initialized during declaration**

### Example

```javascript
const a = 10
a = 20 // Error
```

### Objects with const

`const` prevents reassignment, **not mutation**.

```javascript
const user = {name:"John"}

user.name = "Mike" // allowed
```

But this is not allowed:

```javascript
user = {} // Error
```

---

# Quick Comparison

|Feature|var|let|const|
|---|---|---|---|
|Scope|Function|Block|Block|
|Redeclaration|Allowed|Not Allowed|Not Allowed|
|Reassignment|Allowed|Allowed|Not Allowed|
|Initialization required|No|No|Yes|

---

# Hoisting Relationship

All three declarations are affected by **[[16-Hoisting]]**, but they behave differently.

- `var` is hoisted and initialized with `undefined`
- `let` and `const` are hoisted but remain in the **Temporal Dead Zone (TDZ)** until initialization

To understand this behavior in detail see:

→ [[16-Hoisting]]

---

# Interview Summary

Important points:

- `var` is **function scoped**
- `let` and `const` are **block scoped**
- `let` allows reassignment
- `const` does **not allow reassignment**
- `var` allows **redeclaration**
- `let` and `const` do **not allow redeclaration**
- `const` objects can still be **mutated**

---

# Related Concepts


JavaScript Scope
JavaScript Execution Context