# JavaScript Call Stack

## Definition

The Call Stack is a data structure used by JavaScript to manage the execution of function calls.

It keeps track of which function is currently running and what should be executed next.

---

## Key Concept

- JavaScript executes code line by line (synchronously)  
- Each function call is added to the Call Stack  
- The Call Stack follows LIFO (Last In First Out)  
- The last function added is executed first  

---

## How It Works

1. Global execution starts and is pushed to the stack  
2. When a function is called → pushed onto stack  
3. When a function completes → removed (popped)  
4. Control returns to the previous function  

---

## Example: Sequential Execution

~~~javascript
function a() {
  console.log("A")
}

function b() {
  console.log("B")
}

a()
b()
~~~

### Output

~~~javascript
A
B
~~~

### Execution Flow

1. Global context pushed  
2. `a()` pushed → executed → popped  
3. `b()` pushed → executed → popped  

---

## Example: Nested Function Calls

~~~javascript
function a() {
  console.log("A start")
  b()
  console.log("A end")
}

function b() {
  console.log("B")
}

a()
~~~

### Output

~~~javascript
A start
B start // pushed into stack  
B end   // poped into stack 
A end
~~~

### Execution Flow

1. Global context pushed  
2. `a()` pushed  
3. Inside `a()`, `b()` pushed  
4. `b()` executes → popped  
5. Back to `a()` → completes → popped  

---

## Important Clarification

- LIFO applies to ALL function calls  
- Not only nested functions  
- Nested calls simply make LIFO behavior more visible  

---

## Call Stack + Execution Context

Each function in the stack has its own execution context:

- Variables  
- Function scope  
- this keyword  

→ Related: [[17-Execution Context]]

---

## Stack Overflow

### What is it?

When too many function calls are added to the stack, exceeding its limit.

---

### Example

~~~javascript
function recurse() {
  recurse()
}

recurse()
~~~

### Output

~~~javascript
RangeError: Maximum call stack size exceeded
~~~

---

### Why it happens

- Infinite recursion  
- No base condition  

---

## Behavior

- Single-threaded execution  
- Executes one function at a time  
- Blocks execution during long tasks  

---

## When to use

(Not directly used, but important for understanding)

- Debugging execution order  
- Understanding synchronous behavior  
- Avoiding stack overflow errors  

---

## When NOT to use

- You do not directly control the call stack  
- It is managed by the JavaScript engine  

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
function a() {
  b()
}

function b() {
  console.log("B")
}

a()
console.log("Done")
~~~

### Expected (wrong thinking)

~~~javascript
Done
B
~~~

### Actual Output

~~~javascript
B
Done
~~~

### Why it is a mistake

JavaScript executes functions immediately using the Call Stack before moving to the next line.

---

## Next Step

### Event Loop

The Call Stack works with the Event Loop to handle asynchronous operations.

→ Continue: [[Event Loop]]