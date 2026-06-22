# JavaScript Functions Basics

A function is a block of code designed to perform a specific task.

---

## Definition

Functions help to **reuse code**, improve readability, and organize logic.

---

## Syntax

```javascript
function functionName(parameters) {
  // code
}
```

---

## Basic Example

```javascript
function greet() {
  console.log("Hello")
}

greet() // Hello
```

---

## Function with Parameters

```javascript
function greet(name) {
  console.log("Hello " + name)
}

greet("John") // Hello John
```

---

## Return Value

```javascript
function add(a, b) {
  return a + b
}

const result = add(2, 3)
console.log(result) // 5
```

---

# Function Declarations & Types

JavaScript supports multiple ways to define functions.

---

## 1. Function Declaration

### Definition
A function defined using the `function` keyword with a name.

### Syntax
```javascript
function functionName() {
  // code
}
```

### Example
```javascript
function greet() {
  console.log("Hello")
}
```

### When to use
- When function should be available anywhere in the scope  
- When readability is important  

### When NOT to use
- When you need more control over execution order  

### Behavior
- Stored completely in memory during creation phase  

### Hoisting
- Can be called before declaration  

👉 Detailed explanation: [[16-Hoisting#^54928a]]

---

## 2. Function Expression

### Definition
A function stored inside a variable.

### Syntax
```javascript
const functionName = function () {
  // code
}
```

### Example
```javascript
const greet = function () {
  console.log("Hello")
}
```

### When to use
- When function should run only after definition  
- When assigning functions dynamically  

### When NOT to use
- When early access (before declaration) is required  

### Behavior
- Treated like a variable  

### Hoisting
- Cannot be called before declaration  

👉 Detailed explanation: [[16-Hoisting#^dc5e30]]

---

## 3. Arrow Function

### Definition
A shorter syntax for writing functions introduced in ES6.

### Syntax
```javascript
const functionName = () => {
  // code
}
```

### Example
```javascript
const greet = () => {
  console.log("Hello")
}
```

### When to use
- Short functions  
- Functional programming (map, filter, etc.)  

### When NOT to use
- When working with `this` keyword (object methods, constructors)  

### Behavior
- Does not have its own `this`  

→ [[21-Arrow functions]]

---

## 4. Callback Function

### Definition
A function passed as an argument to another function.

### Syntax
```javascript
function mainFunction(param, callback) {
  callback()
}
```

### Example
```javascript
function greet(name, callback) {
  console.log("Hello " + name)
  callback()
}
```

### When to use
- Async operations  
- Event handling  
- Reusable logic  

### When NOT to use
- When code becomes deeply nested (callback hell)  

### Behavior
- Executed after main function completes  

→ [[20-CallBack Functions]]

---

## 5. Constructor Function

### Definition
A function used to create multiple objects using `new`.

### Syntax
```javascript
function FunctionName() {
  this.property = value
}
```

### Example
```javascript
function User(name) {
  this.name = name
}

const user1 = new User("John")
```

### When to use
- Creating multiple similar objects  

### When NOT to use
- In modern apps (prefer classes)  

### Behavior
- `this` refers to new object  

→ [[24-Constructor Functions]]

---

## 6. call / apply / bind

### Definition
Methods used to control the value of `this` in functions.

### Syntax
```javascript
functionName.call(thisArg)
functionName.apply(thisArg)
functionName.bind(thisArg)
```

### Example
```javascript
function greet() {
  console.log(this.name)
}
```

### When to use
- Changing execution context (`this`)  

### When NOT to use
- When not dealing with `this` keyword  

### Behavior
- Explicitly sets `this`  

→ [[23-Call Apply Bind]]

---

# Additional Function Concepts

These are commonly asked in interviews and essential for deeper understanding.

---

## 7. Immediately Invoked Function Expression (IIFE)

### Definition
A function that runs immediately after it is defined.

### Syntax
```javascript
(function () {
  // code
})()
```

### Example
```javascript
(function (name) {
  console.log("Hello " + name)
})("John")
```

### When to use
- One-time execution  
- Creating private scope  
- Avoiding global variable pollution  

### When NOT to use
- Modern JavaScript modules already handle scope better  

### Behavior
- Executes immediately  
- No separate function call needed  

---

## 8. Named vs Anonymous Functions

### Definition
Functions can be named or anonymous.

### Example
```javascript
// Named
function greet() {}

// Anonymous
const greet = function () {}
```

### When to use
- Named → debugging, readability  
- Anonymous → callbacks  

### Behavior
- Named functions appear in stack traces  

---

## 9. First-Class Functions

### Definition
Functions are treated as values in JavaScript.

### Example
```javascript
function greet() {}

const sayHello = greet
```

### Behavior
- Can be stored in variables  
- Passed as arguments  
- Returned from functions  

---

## 10. Higher-Order Functions

### Definition
A function that takes another function as argument or returns a function.

### Example
```javascript
function main(fn) {
  fn()
}
```

### When to use
- Functional programming  
- Array methods (map, filter, reduce)  

---

## 11. Default Parameters

### Definition
Allows default values for function parameters.

### Example
```javascript
function add(a = 0, b = 0) {
  return a + b
}
```

### Behavior
- Used when argument is `undefined`  

---

## 12. Rest Parameters

### Definition
Allows handling multiple arguments as an array.

### Example
```javascript
function sum(...numbers) {
  return numbers.reduce((a, b) => a + b)
}
```

### Behavior
- Collects all remaining arguments  

---

## 13. Pure vs Impure Functions

### Pure Function
```javascript
function add(a, b) {
  return a + b
}
```

### Impure Function
```javascript
let total = 0

function add(num) {
  total += num
}
```

### Behavior
- Pure → predictable, no side effects  
- Impure → modifies external state  

---

# ⚠️ Edge Cases

### Missing return

```javascript
function test() {}

console.log(test()) // undefined
```

---

### Extra arguments

```javascript
function add(a, b) {
  return a + b
}

add(2, 3, 4) // 5
```

---

### Missing arguments

```javascript
add(2) // NaN
```

---

# ❌ Common Mistakes

### Forgetting return

```javascript
function add(a, b) {
  a + b // ❌
}
```

### Fix
```javascript
function add(a, b) {
  return a + b // ✅
}
```

---

### Calling function expression before declaration

```javascript
greet() // ❌ Error

const greet = function () {
  console.log("Hello")
}
```

### Fix
```javascript
const greet = function () {
  console.log("Hello")
}

greet() // ✅
```

---

### Not passing required arguments

```javascript
function add(a, b) {
  return a + b
}

add(2) // ❌ NaN
```

### Fix
```javascript
function add(a = 0, b = 0) {
  return a + b
}
```

---

# 💡 When to Use

- Reusable logic  
- Avoid repetition  
- Organize code into smaller units  

---