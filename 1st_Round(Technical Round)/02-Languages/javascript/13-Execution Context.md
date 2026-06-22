# JavaScript Execution Context

## Definition

An Execution Context is the environment in which JavaScript code is executed.

It contains all the information needed to run the code, including variables, functions, and the value of `this`.

---

## Types of Execution Context

### Global Execution Context (GEC)

- Created when the JavaScript program starts  
- Only one global context exists  
- `this` refers to global object (`window` in browser)  

---

### Function Execution Context (FEC)

- Created whenever a function is called  
- Each function call gets its own execution context  

---

## Phases of Execution Context

Each execution context has two phases:

### 1. Creation Phase

- Memory is allocated for variables and functions  
- Variables are initialized with `undefined`  
- Functions are stored completely in memory  
- `this` is determined  

---

### 2. Execution Phase

- Code is executed line by line  
- Variables are assigned actual values  
- Functions are invoked  

---

## Example

~~~javascript
var a = 10

function test() {
  var b = 20
  console.log(a + b)
}

test()
~~~

---

## Execution Flow

### Global Execution Context (Creation Phase)

- `a` → undefined  
- `test` → function stored  

---

### Global Execution Context (Execution Phase)

- `a = 10`  
- `test()` is called → new Function Execution Context created  

---

### Function Execution Context (Creation Phase)

- `b` → undefined  

---

### Function Execution Context (Execution Phase)

- `b = 20`  
- `console.log(a + b)` → 30  

---

## Output

~~~javascript
30
~~~

---

## Call Stack + Execution Context

- Each function call creates a new Execution Context  
- These contexts are pushed onto the Call Stack  
- When execution completes, they are removed  

→ Related: [[18-Call Stack]]

---

## Scope Chain

Execution Context also manages scope:

- Inner functions can access outer variables  
- JavaScript looks for variables in current scope, then outer scopes  

---

## Example

~~~javascript
var a = 10

function outer() {
  var b = 20

  function inner() {
    console.log(a + b)
  }

  inner()
}

outer()
~~~

### Output

~~~javascript
30
~~~

---

## Behavior

- JavaScript creates execution context before running code  
- Each function has its own context  
- Works with Call Stack for execution  

---

## Edge Cases

### Variable hoisting

~~~javascript
console.log(a)
var a = 5
~~~

### Output

~~~javascript
undefined
~~~

### Why it happens

Variable is created during creation phase but assigned later.

---

### Function hoisting

~~~javascript
test()

function test() {
  console.log("Hello")
}
~~~

### Output

~~~javascript
Hello
~~~

### Why it happens

Functions are fully stored during creation phase.

---

## Common Mistakes

### ❌ Wrong Assumption

~~~javascript
console.log(a)
let a = 10
~~~

### Output

~~~javascript
ReferenceError
~~~

### Why it is a mistake

`let` and `const` are hoisted but not initialized (Temporal Dead Zone).

---

## When to use

(Not directly used, but important for understanding)

- Understanding hoisting  
- Debugging scope issues  
- Understanding function execution  

---

## When NOT to use

- You don’t directly control execution context  
- It is handled by the JavaScript engine  

---

## Next Step

### Call Stack

Execution Contexts are managed using the Call Stack.

→ Continue: [[18-Call Stack]]