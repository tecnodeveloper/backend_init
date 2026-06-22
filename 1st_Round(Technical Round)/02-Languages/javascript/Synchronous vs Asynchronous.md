# JavaScript Synchronous vs Asynchronous 

## Definition

### Synchronous

Synchronous code executes **line by line**, one after another.  
Each statement waits for the previous one to finish before executing.

---

## Syntax

~~~javascript
statement1
statement2
statement3
~~~

---

## Basic Example

~~~javascript
console.log("Start")

function task() {
  console.log("Task running")
}

task()

console.log("End")
~~~

---

## Execution Flow (Step by Step)

1. `console.log("Start")` → executes  
2. function `task` is defined  
3. `task()` is called → executes  
4. `console.log("End")` → executes  

---

## Output

~~~javascript
Start
Task running
End
~~~

---

## Definition (Asynchronous)

### Asynchronous

Asynchronous code allows certain operations to run **in the background**, without blocking the execution of the next lines.

---

## Syntax

~~~javascript
setTimeout(() => {
  // async code
}, delay)

// Promise
fetch(url).then()

// async/await
async function fn() {
  await something()
}
~~~

---

## Basic Example

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async Task")
}, 1000)

console.log("End")
~~~

---

## Execution Flow (Step by Step)

1. `console.log("Start")` → executes  
2. `setTimeout` is registered → handled by Web APIs  
3. `console.log("End")` → executes  
4. After delay → callback pushed to queue  
5. Callback is handled by the JavaScript runtime using the Event Loop  
   → For detailed understanding: [[Event Loop]]

---

## Output

~~~javascript
Start
End
Async Task
~~~

---

## Blocking vs Non-Blocking

### Blocking (Synchronous Behavior)

~~~javascript
function heavyTask() {
  for (let i = 0; i < 1e9; i++) {}
  console.log("Done")
}

console.log("Start")
heavyTask()
console.log("End")
~~~

#### Explanation

- `heavyTask` blocks execution  
- "End" waits until loop finishes  

---

### Non-Blocking (Asynchronous Behavior)

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Done")
}, 0)

console.log("End")
~~~

#### Explanation

- Task is deferred  
- Execution continues without waiting  

---

## When to use

### Synchronous

- Simple logic  
- When strict order is required  
- Small and fast operations  

---

### Asynchronous

- API calls  
- File operations  
- Timers  
- Long-running tasks  

---

## When NOT to use

### Synchronous

- Heavy computations (blocks UI / freezes app)  

---

### Asynchronous

- When strict step-by-step execution is required without control  

---

## Behavior

- Synchronous → blocking  
- Asynchronous → non-blocking (handled using Event Loop, Call Stack, and Callback Queue)  
  → See: [[Event Loop]], [[18-Call Stack]], [[Event Queue]]

---

## Edge Cases

### setTimeout with 0 delay

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async")
}, 0)

console.log("End")
~~~

---

### Why it is an edge case

Even with `0ms`, it does NOT run immediately.  
It waits until the call stack is empty.

---

### Output

~~~javascript
Start
End
Async
~~~

---

### Async return issue

~~~javascript
function getData() {
  let data

  setTimeout(() => {
    data = "Hello"
  }, 1000)

  return data
}

console.log(getData()) // undefined
~~~

---

### Why it is an edge case

Function returns before async task completes.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async")
}, 1000)

console.log("End")

// Expected:
// Start
// Async
// End
~~~

### Why it is a mistake

Async code does not block execution.

---

### ✅ Fix

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Async")
  console.log("End")
}, 1000)
~~~

### Why the fix works

Dependent logic is moved inside async callback.

---

### ❌ Wrong Code

~~~javascript
function getData() {
  let data

  setTimeout(() => {
    data = "Hello"
  }, 1000)

  return data
}
~~~

### Why it is a mistake

Returns before async completes.

---

### ✅ Fix

~~~javascript
function getData(callback) {
  setTimeout(() => {
    callback("Hello")
  }, 1000)
}

getData((data) => {
  console.log(data)
})
~~~

### Why the fix works

Uses callback to access result after completion.

---

## Next Step

### Promises

Callbacks can become hard to manage in complex scenarios.

Promises provide a cleaner and more structured way to handle asynchronous operations.

→ Continue: [[Promises]]