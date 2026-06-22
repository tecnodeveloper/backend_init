# JavaScript Fetch API

## Definition

The Fetch API is used to make HTTP requests (like GET, POST, PUT, DELETE) to interact with servers.

It returns a Promise that resolves to the response of the request.

---

## Syntax

~~~javascript
fetch(url, options)
  .then((response) => response.json())
  .then((data) => {
    // handle data
  })
  .catch((error) => {
    // handle error
  })
~~~

---

## Basic Example (GET Request)

~~~javascript
fetch("https://jsonplaceholder.typicode.com/posts/1")
  .then((response) => response.json())
  .then((data) => {
    console.log(data)
  })
  .catch((error) => {
    console.log(error)
  })
~~~

### Output

~~~javascript
{
  userId: 1,
  id: 1,
  title: "...",
  body: "..."
}
~~~

---

## Using Async/Await (Preferred)

~~~javascript
async function fetchData() {
  try {
    const response = await fetch("https://jsonplaceholder.typicode.com/posts/1")
    const data = await response.json()
    console.log(data)
  } catch (error) {
    console.log(error.message)
  }
}

fetchData()
~~~

### Output

~~~javascript
{
  userId: 1,
  id: 1,
  title: "...",
  body: "..."
}
~~~

---

## Important Concept

### fetch() returns a Promise

- First Promise → resolves to `Response` object  
- Second step → convert response using `.json()`

~~~javascript
const response = await fetch(url)
const data = await response.json()
~~~

---
## Request Components 

### method

Defines the type of HTTP request.

Common methods:
- GET → fetch data (default)
- POST → send new data
- PUT → update data
- DELETE → remove data

---

### headers

Provide additional information about the request.

~~~javascript
headers: {
  "Content-Type": "application/json"
}
~~~

- Tells the server what type of data is being sent  
- `"application/json"` means data is in JSON format  

---

### body

Contains the actual data being sent to the server.

~~~javascript
body: JSON.stringify({
  name: "John"
})
~~~

- Only used in POST/PUT requests  
- Must be a string (not an object)

---

### JSON.stringify()

Converts a JavaScript object into a JSON string.

~~~javascript
const obj = { name: "John" }
JSON.stringify(obj)
~~~

### Output

~~~javascript
'{"name":"John"}'
~~~

---

### response.json()

Converts JSON response from server into a JavaScript object.

~~~javascript
const response = await fetch(url)
const data = await response.json()
~~~

### Why it is needed

- Server sends data as JSON string  
- `.json()` converts it into usable JavaScript object  


### Flow Summary

~~~javascript
// Sending data
Object → JSON.stringify() → Server

// Receiving data
Server → JSON → response.json() → Object
~~~

---

## Why JSON.stringify() is Needed

### Problem

JavaScript objects cannot be sent directly over HTTP.

~~~javascript
{ name: "John" }
~~~

This is a JavaScript object, not a valid format for network transmission.

---

### Why JSON is Used

- HTTP requests send data as text (strings)  
- JSON is a universal format supported by all programming languages  
- It is lightweight and easy to parse  

---

### JSON.stringify()

Converts a JavaScript object into a JSON string so it can be sent over the network.

~~~javascript
JSON.stringify({ name: "John" })
~~~

### Output

~~~javascript
'{"name":"John"}'
~~~

---

### What Happens Without JSON.stringify()

~~~javascript
fetch(url, {
  method: "POST",
  body: { name: "John" }
})
~~~

### Output

~~~javascript
[object Object]
~~~

### Why it is a problem

- The server receives invalid data  
- It cannot parse the object properly  

---

### Key Concept

- JavaScript Object → used inside your code  
- JSON String → used for communication  

---

### Complete Flow

~~~javascript
// Sending data
JavaScript Object → JSON.stringify() → HTTP Request → Server

// Receiving data
Server → JSON string → response.json() → JavaScript Object
~~~

---

## HTTP Methods

### GET (default)

~~~javascript
fetch(url)
~~~

---

### POST

~~~javascript
fetch(url, {
  method: "POST",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify({
    name: "John"
  })
})
~~~

---

### PUT

~~~javascript
fetch(url, {
  method: "PUT",
  headers: {
    "Content-Type": "application/json"
  },
  body: JSON.stringify({
    name: "Updated"
  })
})
~~~

---

### DELETE

~~~javascript
fetch(url, {
  method: "DELETE"
})
~~~

---

## When to use

- API calls  
- Fetching data from server  
- Sending data to backend  
- CRUD operations  

---

## When NOT to use

- Simple synchronous logic  
- When no server communication is needed  

---

## Behavior

- `fetch()` returns a Promise  
- It does NOT reject on HTTP errors (like 404, 500)  
- You must manually check `response.ok`  

---

## Edge Cases

### fetch does NOT reject on HTTP errors

~~~javascript
const response = await fetch(url)

if (!response.ok) {
  throw new Error("Request failed")
}
~~~

### Why it is an edge case

Even if server returns 404 or 500, fetch still resolves the Promise.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
const data = fetch(url)
console.log(data)
~~~

### Output

~~~javascript
Promise {<pending>}
~~~

### Why it is a mistake

`fetch()` returns a Promise, not actual data.

---

### ✅ Fix

~~~javascript
const response = await fetch(url)
const data = await response.json()
console.log(data)
~~~

### Output

~~~javascript
{...data}
~~~

### Why the fix works

`await` extracts the resolved value from the Promise.

---

### ❌ Wrong Code

~~~javascript
const response = await fetch(url)
console.log(response)
~~~

### Why it is a mistake

Response is not actual data.

---

### ✅ Fix

~~~javascript
const response = await fetch(url)
const data = await response.json()
console.log(data)
~~~

### Why the fix works

`.json()` converts response to usable data.

---
