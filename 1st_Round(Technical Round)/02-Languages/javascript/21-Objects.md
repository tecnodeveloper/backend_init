# JavaScript Objects

Objects store **key-value pairs** and are used to represent **structured data**.

---

## Example

```javascript
const user = {
  name: "John",
  age: 25
}
```

- key → `name`
- value → `"John"`

---

## Array vs Object

```javascript
let arr = ["John", 25]
arr[0] // "John"

let obj = { name: "John", age: 25 }
obj.name // "John"
```

- Array → index-based
- Object → key-based

---

# Object Creation

```javascript
const obj = {
  name: "John"
}
```

Other ways:

```javascript
const obj = new Object()
```

---

## Prototype (Important Concept)

Every object in JavaScript has a **prototype (parent)**.

```javascript
const obj = { name: "John" }
```

Internally:

```
obj → Object.prototype → null
```

---

## Object.create()

Used to create an object with a **custom prototype**

```javascript
const parent = { city: "Salem" }

const obj = Object.create(parent)
obj.name = "John"
```

Structure:

```
obj → parent → Object.prototype → null
```

---

## Why use Object.create()?

### 1. Inheritance

```javascript
const animal = {
  speak() {
    console.log("Some sound")
  }
}

const dog = Object.create(animal)

dog.speak()
```

---

### 2. Shared methods (memory efficiency)

```javascript
const userMethods = {
  greet() {
    console.log("hi")
  }
}

const user1 = Object.create(userMethods)
const user2 = Object.create(userMethods)
```

---

### 3. Create object without default prototype

```javascript
const obj = Object.create(null)

console.log(obj.toString) // undefined
```

Structure:

```
obj → null
```

---

## When to use

- Mostly **not needed in modern React/MERN**
- Useful for:
  - inheritance
  - shared methods
  - special cases (dictionary objects)

---

# Accessing Properties

## Dot notation

```javascript
obj.name
```

## Bracket notation

```javascript
obj["name"]
```

Use when:
- dynamic keys
- keys with spaces

```javascript
const key = "name"
obj[key]
```

---

# Updating & Deleting

```javascript
obj.age = 25
delete obj.age
```

---

# Object Methods (User-defined)

```javascript
const user = {
  name: "John",
  greet() {
    return "Hello"
  }
}
```

---

# Object Methods

Used to work with object properties (keys, values, entries, iteration)

→ [[Object Methods]]

---

# Important Concepts

## Object Destructuring
Used to extract values from objects into variables.

→ [[Object Destructuring]]

---

## Spread Operator
Used to copy or merge objects (shallow copy).

→ [[Spread Operator]]

---

## Object Reference Behavior
Objects are stored by reference, not value.

→ [[Object Reference Behavior]]

---

## Optional Chaining
Safely access nested properties.

→ [[Optional Chaining]]

---

# Edge Cases

```javascript
typeof null // "object"
```

```javascript
const obj = {}
obj.a = undefined
console.log("a" in obj) // true
```

```javascript
const obj = { a: 1 }
delete obj.a
console.log(obj.a) // undefined
```

---