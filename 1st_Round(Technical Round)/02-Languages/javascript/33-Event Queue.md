# JavaScript Event Queue (Callback Queue)

## Definition

The Event Queue is a data structure that stores callback functions from asynchronous operations that are ready to be executed.

These callbacks wait in the queue until the Call Stack is empty.

---

## Key Concept

- Stores callbacks from async operations  
- Works with the Event Loop  
- Uses FIFO (First In First Out)  
- Executes only when Call Stack is empty  

---

## How It Works

1. Async operation is triggered (e.g., setTimeout, fetch)  
2. Handled by Web APIs  
3. Once completed → callback moves to Event Queue  
4. Event Loop checks if Call Stack is empty  
5. Callback is moved to Call Stack and executed  

---

## Example

~~~javascript
console.log("Start")

setTimeout(() => {
  console.log("Callback")
}, 0)

console.log("End")
~~~

---

## Output

~~~javascript
Start
End
Callback
~~~

---

## Execution Flow

1. `Start` → Call Stack  
2. `setTimeout` → Web API  
3. `End` → Call Stack  
4. Callback added to Event Queue  
5. Event Loop moves callback → Call Stack  
6. `Callback` executes  

---

## Important Clarification

- Even with `0ms`, callbacks are NOT executed immediately  
- They must wait until the Call Stack is empty  

---
## Nested Async Callback Behavior

Inside an async callback (like `setTimeout`), all synchronous code runs first.

Even if another async function is called inside, it does NOT execute immediately.

The inner async callback is added to the Event Queue and waits for the Call Stack to be empty again.

---

### Example

~~~javascript
setTimeout(() => {
  console.log("A")

  setTimeout(() => {
    console.log("B")
  }, 0)

  console.log("C")
}, 0)
~~~

### Output

~~~javascript
A
C
B
~~~

### Explanation

- "A" runs first  
- Inner `setTimeout` is scheduled and sent to Event Queue  
- "C" runs immediately after (still synchronous inside callback)  
- "B" runs later when Event Loop processes the queue  

---

### Key Point

Execution does NOT pause for nested async calls.  
Each async callback is scheduled separately and handled by the Event Loop.

---

## FIFO Behavior

Callbacks are executed in the order they are added.

~~~javascript
setTimeout(() => console.log("A"), 0)
setTimeout(() => console.log("B"), 0)
~~~

### Output

~~~javascript
A
B
~~~

---

## Event Queue vs Microtask Queue

| Queue Type | Example | Priority |
|-----------|--------|----------|
| Event Queue (Macrotask) | setTimeout, setInterval | Lower |
| Microtask Queue | Promise `.then()`, `.catch()` | Higher |

---

## Example: Priority Difference

~~~javascript
setTimeout(() => console.log("Timeout"), 0)

Promise.resolve().then(() => {
  console.log("Promise")
})
~~~

### Output

~~~javascript
Promise
Timeout
~~~

---

## Why it happens

- Promise callbacks go to Microtask Queue  
- Microtasks run before Event Queue  
- Event Loop prioritizes Microtasks  

---

## Behavior

- Works with Event Loop  
- Executes after Call Stack is empty  
- Lower priority than Microtask Queue  
- Maintains execution order (FIFO)  

---

## Edge Cases

### Multiple async tasks

~~~javascript
setTimeout(() => console.log("A"), 0)
setTimeout(() => console.log("B"), 0)
setTimeout(() => console.log("C"), 0)
~~~

### Output

~~~javascript
A
B
C
~~~

### Why it works

Callbacks are queued and executed in order.

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
setTimeout(() => console.log("A"), 0)
console.log("B")
~~~

### Expected (wrong thinking)

~~~javascript
A
B
~~~

### Actual Output

~~~javascript
B
A
~~~

### Why it is a mistake

Async callbacks always go through Event Queue and wait for Call Stack.

---

## When to use

(Not directly used, but important for understanding)

- Understanding async execution  
- Debugging execution order  
- Handling timing-related issues  

## When NOT to use

- You don’t directly interact with Event Queue  
- It is managed by the JavaScript runtime  

---
## Next Step

### Event Loop

The Event Queue works with the Event Loop to schedule execution of asynchronous tasks.

→ Continue: [[Event Loop]]