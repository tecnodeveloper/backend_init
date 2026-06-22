# JavaScript Event Loop

## Definition

The Event Loop is a mechanism in JavaScript that manages the execution of asynchronous operations.

It continuously checks the call stack and the callback queue, and moves tasks to the call stack when it is empty.

---

![[Pasted image 20260410172234.png]]
## Core Components

### Call Stack

- Executes synchronous code  
- Works in LIFO (Last In First Out) order  

→ See: [[18-Call Stack]]


---
### Web APIs

- Handle async operations (setTimeout, fetch, DOM events)  
- Provided by browser / Node.js  

---

### Callback Queue (Event Queue)

- Stores completed async callbacks  
- Example: setTimeout callbacks  

→ See: [[Event Queue]]

---

### Microtask Queue

- Stores Promise callbacks (`.then`, `catch`, `finally`)  
- Higher priority than callback queue  

---

## How Event Loop Works

1. Execute all synchronous code in Call Stack  
2. Async tasks are handled by Web APIs  
3. Once completed → moved to queue  
4. Event Loop checks if Call Stack is empty  
5. Moves tasks from queue → Call Stack  

---

## Example

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Timeout")
}, 0)

Promise.resolve().then(() => {
  console.log("Promise")
})

console.log("End")
~~~

---

## Output

~~~javascript
Start
End
Promise
Timeout
~~~

---

## Execution Flow

1. `Start` → call stack  
2. `setTimeout` → Web API  
3. Promise → Microtask queue  
4. `End` → call stack  
5. Microtasks run → `Promise`  
6. Callback queue → `Timeout`  

---

## Key Concept

- Microtasks (Promises) run BEFORE macrotasks (setTimeout)  
- Event Loop prioritizes Microtask Queue  

---

## When to use

(Not directly used, but important for understanding async behavior)

- Debugging async issues  
- Understanding execution order  
- Handling performance issues  

---

## When NOT to use

- You don’t directly "use" event loop in code  
- It is an internal mechanism  

---

## Behavior

- JavaScript is single-threaded  
- Event Loop enables non-blocking behavior  
- Executes tasks in order based on priority  

---

## Edge Cases

### setTimeout with 0ms

~~~javascript
setTimeout(() => {
  console.log("Hi")
}, 0)
~~~

### Why it is an edge case

It does NOT execute immediately.  
It waits until the call stack is empty.

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
setTimeout(() => console.log("A"), 0)
console.log("B")
~~~

### Output

~~~javascript
B
A
~~~

### Why it is a mistake

setTimeout is asynchronous and goes through the event loop.

---

## Next Step

### Promises

Promises use the microtask queue, which has higher priority in the event loop.

→ Continue: [[Promises]]