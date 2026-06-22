# JavaScript 'this' keyword

## Definition

The `this` keyword refers to the object that is currently executing the function.

Its value depends on how the function is called, not where it is defined.


## Syntax

~~~javascript
this
~~~

---

## Basic Example

~~~javascript
const user = {
  name: "John",
  greet() {
    console.log(this.name)
  }
}

user.greet()
~~~

### Output

~~~javascript
John
~~~

---

## Additional Examples

### Global Context

~~~javascript
console.log(this)
~~~

### Output (browser)

~~~javascript
window
~~~

---

### Inside Regular Function

~~~javascript
function show() {
  console.log(this)
}

show()
~~~

### Output

~~~javascript
window (non-strict)
undefined (strict mode)
~~~

---

### Arrow Function Behavior

~~~javascript
const obj = {
  value: 20,
  getValue: () => {
    console.log(this.value)
  }
}

obj.getValue()
~~~

### Output

~~~javascript
undefined
~~~

---

## When to use

- Access object properties inside methods  
- Maintain context in OOP  
- Work with dynamic execution context  

## When NOT to use

- Inside arrow functions when object context is needed  
- When `this` creates confusion (prefer explicit variables)  

## Behavior

- Determined at runtime (dynamic binding)  
- Depends on call site  
- Arrow functions do NOT have their own `this`  
- In strict mode, `this` in functions is `undefined`  

---

## Hoisting (only if applicable)

- `this` is not hoisted  
- It is assigned during execution  

---

## Edge Cases

### Losing `this` in Callback

~~~javascript
const obj = {
  name: "John",
  greet() {
    setTimeout(function () {
      console.log(this.name)
    }, 1000)
  }
}

obj.greet()
~~~

### Output

~~~javascript
undefined
~~~

### Why it is an edge case

Callback function loses object context.

---

### Fix

~~~javascript
setTimeout(() => {
  console.log(this.name)
}, 1000)
~~~

### Output

~~~javascript
John
~~~

### Why the fix works

Arrow function inherits `this` from parent scope.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
const obj = {
  value: 10,
  getValue: () => {
    console.log(this.value)
  }
}

obj.getValue()
~~~

### Output

~~~javascript
undefined
~~~

### Why it is a mistake

Arrow function does not bind `this`.

---

### ✅ Fix

~~~javascript
const obj = {
  value: 10,
  getValue() {
    console.log(this.value)
  }
}

obj.getValue()
~~~

### Output

~~~javascript
10
~~~

### Why the fix works

Regular function binds `this` to object.

---

### ❌ Wrong Code

~~~javascript
function test() {
  console.log(this)
}

test()
~~~

### Output

~~~javascript
window
~~~

### Why it is a mistake

Unexpected global binding.

---

### ✅ Fix

~~~javascript
"use strict"

function test() {
  console.log(this)
}

test()
~~~

### Output

~~~javascript
undefined
~~~

### Why the fix works

Strict mode prevents global binding.

---

### ❌ Wrong Code

~~~javascript
const obj = {
  name: "John",
  greet() {
    const fn = this.greet
    fn()
  }
}

obj.greet()
~~~

### Output

~~~javascript
undefined
~~~

### Why it is a mistake

Function is detached from object.

---

### ✅ Fix

~~~javascript
const fn = this.greet.bind(this)
fn()
~~~

### Output

~~~javascript
John
~~~

### Why the fix works

`bind` preserves context.

---