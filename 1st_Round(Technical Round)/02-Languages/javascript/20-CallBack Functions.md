# Callback Functions

## Definition

A callback function is a function passed as an argument to another function and executed later.

It allows one function to control when and how another function runs.

---

## Syntax

```javascript
function mainFunction(callback) {
  callback()
}
```

---

## Basic Example

```javascript
function greet(name, callback) {
  console.log("Hello " + name)
  callback()
}

function sayBye() {
  console.log("Goodbye")
}

greet("John", sayBye)

// Output:
// Hello John
// Goodbye
```

---

## Additional Examples

### Example 1: Anonymous Callback

```javascript
function greet(callback) {
  console.log("Hello")
  callback()
}

greet(function () {
  console.log("This is a callback")
})
```

---

### Example 2: Arrow Function Callback

```javascript
function process(callback) {
  callback()
}

process(() => {
  console.log("Arrow callback executed")
})
```

---

### Example 3: Callback in Array Methods

```javascript
const numbers = [1, 2, 3]

numbers.forEach(function (num) {
  console.log(num)
})
```

---

### Example 4: Asynchronous Callback

```javascript
setTimeout(function () {
  console.log("Executed after 2 seconds")
}, 2000)
```

---

## Calling vs Invoking a Function

### Calling a Function

Calling means executing a function directly using its name.

```javascript
function greet() {
  console.log("Hello")
}

greet()
```

---

### Invoking a Function

Invoking means executing a function through a reference, often inside another function.

```javascript
function main(callback) {
  callback()
}

function sayHi() {
  console.log("Hi")
}

main(sayHi)
```

---

### Key Idea

- Calling → direct execution  
- Invoking → execution via reference (common in callbacks)

---

### Callback Flow

1. Function is passed as an argument  
2. Received as a parameter  
3. Invoked using `callback()`

```javascript
function outerFunction(callback) {
  console.log("Before callback")
  callback()
  console.log("After callback")
}

function innerFunction() {
  console.log("Inside callback")
}

outerFunction(innerFunction)
```

---
## How JavaScript Differentiates Callback vs Normal Argument

JavaScript does NOT explicitly differentiate between a callback and a normal argument.

It checks the **type of the value at runtime**.

---

### Key Idea

- If argument is a function → it can be invoked  
- If not → it throws an error  

---

### Example

```javascript
function execute(value) {
  value()
}

execute(() => console.log("I am a callback")) // works
execute(10) // error
```

---

### What Happens Internally

When `value()` runs:

- Function → executes  
- Non-function → TypeError  

```
TypeError: value is not a function
```

---

### Safe Handling

```javascript
function execute(value) {
  if (typeof value === "function") {
    value()
  } else {
    console.log("Not a function")
  }
}
```

---

### Mixed Arguments Example

```javascript
function process(data, callback) {
  console.log(data)

  if (typeof callback === "function") {
    callback()
  }
}

process("Hello", () => console.log("Callback"))
process("Hello", 123)
```

---

### Key Difference

- Normal argument → used as value  
- Callback → used with `()` (invoked)

---

## When to use

- Asynchronous operations (API calls, timers)
- Event handling
- Array methods (map, filter, forEach)
- Reusable logic

---

## When NOT to use

- Deep nesting (callback hell)
- When Promises / async-await are clearer

---

## Behavior

- Callback runs only when invoked
- Can be synchronous or asynchronous
- Execution depends on where it is called

---

## Edge Cases

### 1. Callback is optional but not handled

```javascript
function greet(callback) {
  console.log("Hello")
  callback()
}

greet()
```

### What happens

Error: `callback is not a function`

### Why it is an edge case

Function assumes callback always exists

### Fix

```javascript
function greet(callback) {
  console.log("Hello")
  if (callback) {
    callback()
  }
}
```

---

### 2. Callback executed multiple times unintentionally

```javascript
function process(callback) {
  callback()
  callback()
}
```

### What happens

Callback runs twice

### Why it is an edge case

May cause duplicate actions

---

### 3. Asynchronous execution order confusion

```javascript
console.log("Start")

setTimeout(() => {
  console.log("Callback")
}, 0)

console.log("End")
```

### Output

```
Start
End
Callback
```

### Why it is an edge case

Callback runs later due to event loop

---

### 4. Callback never invoked

```javascript
function main(callback) {
  // forgot to call callback
}

main(() => console.log("Never runs"))
```

### Why it is an edge case

Logic fails silently

---

## Common Mistakes

### ❌ Wrong Code

```javascript
greet(callback())
```

### Why it is a mistake

Function executes immediately instead of being passed

### ✅ Fix

```javascript
greet(callback)
```

### Why the fix works

Passes function reference

---

### ❌ Wrong Code

```javascript
function greet(callback) {
  console.log("Hello")
}

greet(() => console.log("Callback"))
```

### Why it is a mistake

Callback is never executed

### ✅ Fix

```javascript
function greet(callback) {
  console.log("Hello")
  callback()
}
```

### Why the fix works

Explicit invocation

---

### ❌ Wrong Code

```javascript
setTimeout(callback(), 1000)
```

### Why it is a mistake

Executes immediately

### ✅ Fix

```javascript
setTimeout(callback, 1000)
```

### Why the fix works

Schedules execution properly

---

### ❌ Wrong Code

```javascript
function main(cb) {
  cb
}
```

### Why it is a mistake

Function is not executed

### ✅ Fix

```javascript
function main(cb) {
  cb()
}
```

### Why the fix works

Proper invocation

---

### ❌ Wrong Code

```javascript
function greet(cb) {
  console.log("Hello")
  cb
}
```

### Why it is a mistake

Missing parentheses

### ✅ Fix

```javascript
function greet(cb) {
  console.log("Hello")
  cb()
}
```

### Why the fix works

Ensures execution

---