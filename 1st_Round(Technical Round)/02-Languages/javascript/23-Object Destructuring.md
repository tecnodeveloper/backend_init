# JavaScript Object Destructuring

Object destructuring is used to **extract values from objects into variables**.

---

## Basic Syntax

```javascript
const obj = { name: "John", age: 25 }

const { name, age } = obj

console.log(name) // "John"
console.log(age)  // 25
```

---

## Renaming Variables

```javascript
const obj = { name: "John" }

const { name: userName } = obj

console.log(userName) // "John"
```

---

## Default Values

```javascript
const obj = { name: "John" }

const { name, age = 18 } = obj

console.log(age) // 18
```

---

## Missing Property

```javascript
const obj = { name: "John" }

const { age } = obj

console.log(age) // undefined
```

---

## Nested Destructuring

```javascript
const obj = {
  user: {
    name: "John"
  }
}

const { user: { name } } = obj

console.log(name) // "John"
```

---

## Function Parameters (Object Destructuring)

Using destructuring in function parameters allows passing an object and extracting values directly.

---

### Normal Parameters

```javascript
function printUser(name, age) {
  console.log(name, age)
}

printUser("John", 25)
```

**Limitations:**

- Order matters  
- Hard to manage with many parameters  

---

### Object Parameter (Destructuring)

```javascript
function printUser({ name, age }) {
  console.log(name, age)
}

printUser({ name: "John", age: 25 })
```

---

### Why use this?

- Order does NOT matter  

```javascript
printUser({ age: 25, name: "John" })
```

- More readable (self-explanatory)  
- Easy to add new fields  

```javascript
function printUser({ name, age, city }) {}
```

- Supports default values  

```javascript
function printUser({ name, age = 18 }) {}
```

---

### Behind the Scenes

```javascript
function printUser(obj) {
  const name = obj.name
  const age = obj.age
}
```

Destructuring is just a **shortcut**.

---

### When to Use

- Few parameters → normal parameters  
- Many / optional parameters → object destructuring  

---

## Rest Operator

```javascript
const obj = { name: "John", age: 25, city: "Salem" }

const { name, ...rest } = obj

console.log(name) // "John"
console.log(rest) // { age: 25, city: "Salem" }
```

---

## Important Points

- Extracts values from objects  
- Order does NOT matter (unlike arrays)  
- Variable name must match key (unless renamed)  
- Can use default values  

---

## Common Mistake

```javascript
const obj = { name: "John" }

const { age } = obj

console.log(age.toString()) // ❌ Error
```

### What’s happening?

- `age` does NOT exist in the object  
- So destructuring gives:

```javascript
age = undefined
```

Now this runs:

```javascript
undefined.toString()
```

Which causes:

```
TypeError: Cannot read properties of undefined
```

Because `undefined` does not have methods.

---

## Fix (Default Value)

```javascript
const { age = 0 } = obj

console.log(age.toString()) // "0"
```

### Why this works

- If `age` is missing → it uses default value `0`
- So now:

```javascript
age = 0
```

And:

```javascript
0.toString() // works
```

---

## Key Idea

If a property might be missing, always use a **default value** during destructuring.

## Mental Model

```
Destructuring → pull values out of object into variables
```

---

## Interview Summary

- Used to extract object values  
- Supports default values  
- Supports renaming  
- Works in function parameters  
- Supports nested objects  