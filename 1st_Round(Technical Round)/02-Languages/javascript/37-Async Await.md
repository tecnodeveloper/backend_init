# JavaScript Async Await

## Definition

`async/await` is a modern way to handle asynchronous operations in JavaScript.

It allows you to write asynchronous code that looks and behaves like synchronous code, improving readability and maintainability.

It is built on top of Promises.

---

## Syntax

~~~javascript
async function functionName() {
  const result = await promise
}
~~~

---

## Basic Example

~~~javascript
function getData() {
  return new Promise((resolve) => {
    setTimeout(() => {
      resolve("Data received")
    }, 1000)
  })
}

async function fetchData() {
  const data = await getData()
  console.log(data)
}

fetchData()
~~~

### Output  
  
~~~javascript  
Data received // after 1 second  
~~~


---

## Additional Examples

### Handling Multiple Awaits

~~~javascript
function getUser() {
  return new Promise((resolve) => {
    setTimeout(() => resolve("User"), 1000)
  })
}

function getPosts() {
  return new Promise((resolve) => {
    setTimeout(() => resolve("Posts"), 1000)
  })
}

async function fetchAll() {
  const user = await getUser()
  const posts = await getPosts()

  console.log(user, posts)
}

fetchAll()
~~~

### Output  
  
~~~javascript  
User Posts // after 2 seconds  
~~~  
  
### Note  
  
This runs sequentially (one after another).  
Total time = sum of all awaits (1s + 1s = 2s), because each runs one after another.  

For parallel execution, use `Promise.all()`.

---
### Parallel Execution using Promise.all()

~~~javascript
async function fetchAll() {
  const [user, posts] = await Promise.all([getUser(), getPosts()])
  console.log(user, posts)
}

fetchAll()
~~~

### Output

~~~javascript
User Posts // after 1 second
~~~

### Explanation

Both async operations run in parallel.  
Total time = maximum of all tasks instead of sum.

---
### Using try...catch for Error Handling

~~~javascript
function getData() {
  return new Promise((resolve, reject) => {
    reject("Error occurred")
  })
}

async function fetchData() {
  try {
    const data = await getData()
    console.log(data)
  } catch (error) {
    console.log(error.message)
  }
}

fetchData()
~~~

### Output  
  
~~~javascript  
Error occurred  
~~~

---

## When to use

- Handling asynchronous operations  
- API calls  
- Working with Promises in a cleaner way  
- Sequential async operations  

---

## When NOT to use

- Pure synchronous logic  
- When Promises are not involved  
- For simple one-line async operations where `.then()` is sufficient  

---

## Behavior

- `async` always returns a Promise  
- `await` pauses execution until the Promise resolves  
- Code after `await` runs only after completion  
- `await` pauses execution only inside the async function (non-blocking)  
- It does NOT block the JavaScript thread

---

## Hoisting

`async` function declarations are hoisted like normal functions.

~~~javascript
test()

async function test() {
  return "Hello"
}
~~~

### Output

~~~javascript
Promise {<fulfilled>: "Hello"}
~~~

### Explanation

Async functions are hoisted like normal functions.  
Calling them returns a Promise immediately.


---

## Edge Cases

### Await only works inside async

~~~javascript
function test() {
  const data = await Promise.resolve("Hello")
}
~~~
### Output  
  
~~~javascript  
SyntaxError: await is only valid in async functions  
~~~


### Why it is an edge case

`await` can only be used inside an `async` function.

---

### Async function return value

~~~javascript
async function test() {
  return "Hello"
}

console.log(test())
~~~

### Output

~~~javascript
Promise {<fulfilled>: "Hello"}
~~~

### Why it is an edge case

Even a normal return is wrapped inside a Promise.

---

### Await with non-Promise

~~~javascript
async function test() {
  const value = await 10
  console.log(value)
}

test()
~~~

### Output

~~~javascript
10
~~~

### Why it is an edge case

`await` automatically wraps non-promises into resolved Promises.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
async function test() {
  const data = getData()
  console.log(data)
}
~~~
### Output  
  
~~~javascript  
Promise {<pending>}  
~~~

### Why it is a mistake

`getData()` returns a Promise, not the resolved value.

---

### ✅ Fix

~~~javascript
async function test() {
  const data = await getData()
  console.log(data)
}
~~~

### Output  
  
~~~javascript  
Data received  
~~~
### Why the fix works

`await` extracts the resolved value from the Promise.

---

### ❌ Wrong Code

~~~javascript
async function test() {
  const data = await getData()
}

test().then((res) => {
  console.log(res)
})
~~~

### Output  
  
~~~javascript  
undefined  
~~~

### Why it is a mistake

Nothing is returned from the async function.

---

### ✅ Fix

~~~javascript
async function test() {
  const data = await getData()
  return data
}

test().then((res) => {
  console.log(res)
})
~~~
### Output  
  
~~~javascript  
Data received  
~~~

### Why the fix works

Returned value is wrapped in a Promise and passed to `.then()`.

---

### ❌ Wrong Code

~~~javascript
async function test() {
  const data = await getData()
  throw new Error("Failed")
}

test()
~~~

### Output  
  
~~~javascript  
Uncaught (in promise) Error: Failed  
~~~

### Why it is a mistake

Error is not handled.

---

### ✅ Fix

~~~javascript
async function test() {
  try {
    const data = await getData()
    throw new Error("Failed")
  } catch (error) {
    console.log(error.message)
  }
}
~~~
### Output  
  
~~~javascript  
Failed  
~~~

### Why the fix works

`try...catch` handles errors in async/await.

---
## Next Step  
  
### Fetch API  
  
`async/await` is commonly used with the Fetch API to handle API requests in a clean and readable way.  
  
It simplifies working with HTTP requests and responses compared to `.then()` chaining.  
  
→ Continue: [[Fetch API]]