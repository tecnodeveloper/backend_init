# JavaScript Promises

## Definition
  
A Promise is an object that represents the eventual completion (or failure) of an asynchronous operation and its resulting value.    
### Simple Understanding

A promise is an object that represents the result of an asynchronous operation that will be available in the future.

It provides a mechanism to handle success (resolve) or failure (reject) once the operation is completed.

---
## Real Life Analogy

Ordering food in a restaurant:

- You place an order (async operation starts)
- You don’t wait, you do other things
- Waiter promises to bring food
- If successful → food is served (fulfilled)
- If something goes wrong → informed (rejected)

---

## Syntax

~~~javascript
const promise = new Promise((resolve, reject) => {
  // async operation

  if (success) {
    resolve(value)
  } else {
    reject(error)
  }
})
~~~

---

## Basic Example

~~~javascript
const promise = new Promise((resolve, reject) => {
  const success = true

  if (success) {
    resolve("Success")
  } else {
    reject("Error")
  }
})

promise
  .then((result) => {
    console.log(result)
  })
  .catch((error) => {
    console.log(error)
  })
~~~

---
## Consuming a Promise

### then()

Executed when promise is fulfilled.

~~~javascript
promise.then((result) => {
  console.log(result)
})
~~~

---

### catch()

Executed when promise is rejected.

~~~javascript
promise.catch((error) => {
  console.log(error)
})
~~~

---

### finally()

Runs regardless of success or failure.

~~~javascript
promise.finally(() => {
  console.log("Completed")
})
~~~
---

## Additional Examples

### Using setTimeout (Async Simulation)

~~~javascript
const promise = new Promise((resolve) => {
  setTimeout(() => {
    resolve("Data received")
  }, 1000)
})

promise.then((data) => {
  console.log(data)
})
~~~

### Output

~~~javascript
Data received   // after 1 second
~~~

---

## When to use

- Handling asynchronous operations  
- API calls  
- File handling  
- Avoiding callback hell  
- When multiple async tasks need coordination  
## When NOT to use

- Simple synchronous logic  
- When a direct return is enough  
- When async handling is unnecessary  

---

## Behavior

- A Promise has 3 states:
  1. Pending → initial state  
  2. Fulfilled → resolved successfully  
  3. Rejected → operation failed  

- Promises execute immediately when created
- The executor function inside a Promise runs synchronously, but the resolution happens asynchronously

~~~javascript
const promise = new Promise(() => {
  console.log("Running...");
});

console.log("After creation");
~~~

### Output

~~~javascript
Running...
After creation
~~~

- `.then()` runs after the promise is resolved  
- `.catch()` runs if the promise is rejected  
- `.finally()` runs regardless of result  
- Each `.then()` returns a new Promise (important for chaining)

---

## Edge Cases

### Multiple resolve/reject

~~~javascript
const promise = new Promise((resolve, reject) => {
  resolve("First")
  resolve("Second")
  reject("Error")
})

promise.then(console.log).catch(console.log)
~~~
### Explanation

Only the **first call** is considered.  
Subsequent calls are ignored.
### Output

~~~javascript
First
~~~

---
### Missing catch()

~~~javascript
const promise = new Promise((resolve, reject) => {
  reject("Something went wrong")
})

promise.then((res) => {
  console.log(res)
})
~~~

### Explanation

Rejection is not handled, leading to an **Unhandled Promise Rejection**.

### Output

~~~javascript
Uncaught (in promise) Something went wrong
~~~

---
## Common Mistakes

### ❌ Wrong Code

~~~javascript
const promise = new Promise((resolve, reject) => {
  setTimeout(() => {
    return "Data"
  }, 1000)
})
~~~

### Output

~~~javascript
(no output)
~~~

### Why it is a mistake

Returning inside an async function does NOT resolve a Promise.

---
### ✅ Fix

~~~javascript
const promise = new Promise((resolve) => {
  setTimeout(() => {
    resolve("Data")
  }, 1000)
})
~~~

### Output

~~~javascript
Data   // after 1 second
~~~

### Why the fix works

`resolve()` properly sends the value to the Promise.

---
### ❌ Wrong Code

~~~javascript
promise.then((res) => {
  console.log(res)
})

promise.then((res) => {
  console.log(res)
})
~~~
### Output

~~~javascript
Success
Again: Success
~~~

### Why it is a mistake

These `.then()` calls are not chained, so they run independently on the same promise.

Each `.then()` should return a value or another promise to pass data to the next `.then()`.

---

### ✅ Fix

~~~javascript
promise
  .then((res) => {
    console.log(res)
    return res
  })
  .then((res) => {
    console.log("Again:", res)
  })
~~~
### Output

~~~javascript
Success
Again: Success
~~~

### Why the fix works

Chaining ensures proper data flow between steps.

---
### ❌ Wrong Code

~~~javascript
const promise = new Promise((resolve, reject) => {
  const success = false

  if (!success) {
    throw new Error("Something went wrong")
  }

  resolve("Success")
})

promise.then((res) => {
  console.log(res)
})
~~~

### Output

~~~javascript
Uncaught (in promise) Error: Something went wrong
~~~

### Why it is a mistake

The error rejects the Promise, but there is no `.catch()` to handle it.

---

### ✅ Fix

~~~javascript
const promise = new Promise((resolve, reject) => {
  const success = false;

  if (!success) {
    throw new Error("Something went wrong");
  }

  resolve("Success");
});

promise
  .then((res) => {
    console.log(res);
  })
  .catch((err) => {
    console.log(err.message);
  });
~~~

### Why the fix works

Errors inside a Promise automatically reject it, and `.catch()` handles it.

---
## Promise Methods

### Promise.resolve()

Returns a resolved Promise.

~~~javascript
Promise.resolve("Hello").then(console.log)
~~~

---

### Promise.reject()

Returns a rejected Promise.

~~~javascript
Promise.reject("Error").catch(console.log)
~~~

---

### Promise.all()

Waits for all promises to resolve.  
Fails if any one promise rejects.

~~~javascript
Promise.all([p1, p2, p3]).then(console.log)
~~~

---

### Promise.race()

Returns the first settled promise (resolve or reject).

~~~javascript
Promise.race([p1, p2]).then(console.log)
~~~

---

### Promise.allSettled()

Waits for all promises to complete (both resolve and reject).

~~~javascript
Promise.allSettled([p1, p2]).then(console.log)
~~~

---

### Promise.any()

Returns the first fulfilled promise.  
Ignores rejected ones unless all fail.

~~~javascript
Promise.any([p1, p2]).then(console.log)
~~~

---
## Promise Chaining (Intro)

Used to execute multiple asynchronous operations in sequence.

Each `.then()` should return a value or another Promise so the next `.then()` can use it.

### Basic Example

~~~javascript
Promise.resolve(2)
  .then((num) => {
    return num * 2
  })
  .then((num) => {
    console.log(num)
  })
~~~

### Output

~~~javascript
4
~~~


### Why Promise Chaining is Important

When multiple asynchronous operations depend on each other, chaining ensures:

- Clean and readable code  
- Proper execution order  
- No nested callbacks (avoids callback hell)  

### Detailed Explanation

→ Continue: [[Promise Chaining]]

---
## Final Notes

- Promises are a core part of asynchronous JavaScript  
- They help manage async operations cleanly  
- They are the foundation for `async/await`  
- Proper chaining and error handling are critical for real-world applications  