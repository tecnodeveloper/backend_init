# JavaScript Call Apply Bind

## Definition

`call`, `apply`, and `bind` are methods used to control the value of `this` in JavaScript functions.

They allow a function to be reused with different objects.

---

## Syntax

### call

~~~javascript
functionName.call(thisArg, arg1, arg2, ...)
~~~

### apply

~~~javascript
functionName.apply(thisArg, [arg1, arg2, ...])
~~~

### bind

~~~javascript
const newFunction = functionName.bind(thisArg, arg1, arg2, ...)
~~~

---

## Basic Example

~~~javascript
function greet() {
  console.log(this.name)
}

const user = { name: "John" }

greet.call(user) // John
~~~

---

## Additional Examples

### call()

#### Definition
Invokes the function immediately with a given `this` value and arguments passed individually.
 
~~~javascript
function greet(age) {
  console.log(this.name + " is " + age)
}

const user = { name: "Alice" }

greet.call(user, 25)
// Alice is 25
~~~

---

### apply()

#### Definition
Invokes the function immediately with a given `this` value and arguments passed as an array.

~~~javascript
function greet(age, city) {
  console.log(this.name + " is " + age + " from " + city)
}

const user = { name: "Bob" }

greet.apply(user, [30, "Chennai"])
// Bob is 30 from Chennai
~~~

---

### bind()

#### Definition
Returns a new function with a fixed `this` value. It does NOT execute immediately.

~~~javascript
function greet(age) {
  console.log(this.name + " is " + age)
}

const user = { name: "Charlie" }

const boundFn = greet.bind(user)

boundFn(28)
// Charlie is 28
~~~

---

## When to use

- When you need to manually control `this`
- Reusing a function across different objects
- Fixing `this` inside callbacks (setTimeout, event handlers)
- Partial application (using bind)

---

## When NOT to use

- When `this` is not involved
- With arrow functions (they ignore call/apply/bind)
- When normal function calls are sufficient

---

## Behavior

- `call` → executes immediately, arguments passed one by one  
- `apply` → executes immediately, arguments passed as array  
- `bind` → returns new function, execution happens later  

---

## Hoisting (only if applicable)

Not applicable.

There is no special hoisting behavior for `call`, `apply`, or `bind`.

They are just methods used at runtime.

Hoisting depends only on how the function is declared:
- Function declaration → hoisted  
- Function expression → not hoisted  

---

## Edge Cases

### Arrow functions ignore call/apply/bind

~~~javascript
const obj = { name: "John" }

const greet = () => {
  console.log(this.name)
}

greet.call(obj) // undefined
~~~

---

%% ### Partial application using bind

~~~javascript
function multiply(a, b) {
  return a * b
}

const double = multiply.bind(null, 2)

double(5) // 10
~~~
 %%

### Partial Application using bind

Partial application means fixing some arguments of a function in advance and creating a new function.
'bind' is not used to bind thisArg but also normal arg

~~~javascript
function multiply(a, b) {
  return a * b;
}

// Fix the first argument (a = 2)
const double = multiply.bind(null, 2); 

// Now only one argument is needed
double(5); // 10
~~~

### Explanation

- `bind` creates a new function
- First argument → `this` (not needed here, so we pass `null`)
- Remaining arguments → pre-filled values

So this line:
~~~javascript
const double = multiply.bind(null, 2);
~~~

means:

- "Create a new function where `a` is always 2"
- The new function only needs `b`

So internally it behaves like:
~~~javascript
function double(b) {
  return multiply(2, b);
}
~~~

---

### Method Borrowing

#### Definition
Using a function from one object with another object by changing `this`.

~~~javascript
const person1 = {
  name: "A"
}

const person2 = {
  name: "B"
}

function greet() {
  console.log(this.name)
}

// Borrowing greet for different objects
greet.call(person1) // A
greet.call(person2) // B
~~~

#### Explanation

- `greet` is not inside any object  
- But using `call`, we "attach" it temporarily to different objects  
- So the same function works for multiple objects  

---

## Comparison: call vs apply vs bind

| Feature        | call                | apply               | bind                     |
|----------------|---------------------|---------------------|--------------------------|
| Execution      | Immediate           | Immediate           | Not immediate            |
| Arguments      | Individual          | Array               | Individual (preset)      |
| Return value   | Function result     | Function result     | New function             |
| Use case       | Direct invocation   | Dynamic arguments   | Reusable function        |

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
greet.bind(user)
~~~

### Why it is a mistake

`bind` does not execute the function.

---

### ✅ Fix

~~~javascript
const fn = greet.bind(user)
fn()
~~~

### Why the fix works

`bind` returns a function which must be called.

---

### ❌ Wrong Code

~~~javascript
greet.apply(user, 25, "Chennai")
~~~

### Why it is a mistake

`apply` requires arguments as an array.

---

### ✅ Fix

~~~javascript
greet.apply(user, [25, "Chennai"])
~~~

### Why the fix works

Arguments are passed correctly as an array.

---

### ❌ Wrong Code

~~~javascript
const greet = () => {
  console.log(this.name)
}

greet.call(user) // greet is an arrow function => this directs to global object
~~~

### Why it is a mistake

Arrow functions do not have their own `this`.

---

### ✅ Fix

~~~javascript
function greet() {
  console.log(this.name)
}

greet.call(user) // 'this' is directs towards the object provided
~~~

### Why the fix works

Regular functions allow dynamic `this`.
