# JavaScript Promise Chaining

## Definition

Promise Chaining is a technique used to execute multiple asynchronous operations in sequence, where the result of one step is passed to the next using `.then()`.

Each `.then()` receives the value returned from the previous `.then()`.

---

## Syntax

~~~javascript
promise
  .then((result1) => {
    return result2
  })
  .then((result2) => {
    return result3
  })
  .then((result3) => {
    // final result
  })
  .catch((error) => {
    // handle error
  })
~~~

---

## Basic Example

~~~javascript
Promise.resolve(2)
  .then((num) => {
    return num * 2
  })
  .then((num) => {
    return num * 3
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
12
~~~

---

## How It Works

1. First `.then()` receives `2`
2. Returns `4`
3. Second `.then()` receives `4`
4. Returns `12`
5. Third `.then()` receives `12` and logs it

---

## Key Concept

- Each `.then()` always returns a new Promise
- This is what enables chaining

If nothing is returned, the next `.then()` receives `undefined`.

---

## Example: Missing Return

~~~javascript
Promise.resolve(2)
  .then((num) => {
    num * 2   // no return
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
undefined
~~~

### Explanation

Since the first `.then()` does not return anything, the next `.then()` receives `undefined`.

---

## Returning a Promise

~~~javascript
Promise.resolve(5)
  .then((num) => {
    return new Promise((resolve) => {
      setTimeout(() => resolve(num * 2), 1000)
    })
  })
  .then((result) => {
    console.log(result)
  })
~~~

### Output

~~~javascript
10   // after 1 second
~~~

### Explanation

If a promise is returned, the next `.then()` waits for it to resolve.

---

## When to use

- When multiple async steps depend on each other  
- When output of one operation is needed for the next  
- To avoid nested callbacks (callback hell)  

---

## When NOT to use

- When operations are independent (can run in parallel)  
- When logic becomes too complex (prefer async/await)  

---

## Error Handling in Chain

~~~javascript
Promise.resolve(10)
  .then((num) => {
    return num / 2
  })
  .then((num) => {
    throw new Error("Something broke")
  })
  .then((num) => {
    console.log(num)
  })
  .catch((err) => {
    console.log(err.message)
  })
~~~

### Output

~~~javascript
Something broke
~~~

### Explanation

- Error in any `.then()` skips remaining `.then()`  
- Control jumps directly to `.catch()`  

---

## Edge Cases

### Skipping `.then()`

~~~javascript
Promise.resolve(5)
  .then((num) => num * 2)
  .then()
  .then((num) => console.log(num))
~~~

### Output

~~~javascript
10
~~~

### Why it is an edge case

An empty `.then()` just passes the value to the next `.then()`.

---

### Returning undefined

~~~javascript
Promise.resolve(5)
  .then((num) => {
    return
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
undefined
~~~

### Why it is an edge case

Returning nothing is equivalent to returning `undefined`.

---

## Common Mistakes

### ❌ Wrong Code (Nested then instead of chaining)

~~~javascript
Promise.resolve(2)
  .then((num) => {
    Promise.resolve(num * 2).then((res) => {
      console.log(res)
    })
  })
~~~

### Why it is a mistake

Creates nested structure (callback-style), breaking the chain.

---

### Output

~~~javascript
4
~~~

---

### ✅ Fix

~~~javascript
Promise.resolve(2)
  .then((num) => {
    return Promise.resolve(num * 2)
  })
  .then((res) => {
    console.log(res)
  })
~~~

### Why the fix works

Returning the promise keeps the chain flat and predictable.

---

### Output

~~~javascript
4
~~~

---

### ❌ Wrong Code (Missing return in async chain)

~~~javascript
Promise.resolve(3)
  .then((num) => {
    setTimeout(() => {
      return num * 2
    }, 1000)
  })
  .then((res) => {
    console.log(res)
  })
~~~

### Why it is a mistake

The async operation is not returned, so the chain does not wait.

---

### Output

~~~javascript
undefined
~~~

---

### ✅ Fix

~~~javascript
Promise.resolve(3)
  .then((num) => {
    return new Promise((resolve) => {
      setTimeout(() => resolve(num * 2), 1000)
    })
  })
  .then((res) => {
    console.log(res)
  })
~~~

### Why the fix works

Returning the promise ensures the next `.then()` waits for completion.

---

### Output

~~~javascript
6   // after 1 second
~~~

---
## Next Step  
  
### Async Await  
  
Promise chaining can become hard to read when there are many steps.  
  
`async/await` provides a cleaner and more readable way to handle the same logic.  
  
→ Continue: [[Async Await]]