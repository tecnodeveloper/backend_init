# JavaScript - null vs undefined

`null` and `undefined` both represent **absence of a value**, but they mean **different things** in JavaScript.

- **undefined** → value **not assigned yet**
- **null** → value **intentionally empty**

---

# undefined

`undefined` is the **default value assigned by JavaScript** when something has no value.

## When does `undefined` occur?

### 1. Variable declared but not assigned

```javascript
let a
console.log(a)
```

Output

```
undefined
```

---

### 2. Function without return

```javascript
function test() {}

console.log(test())
```

Output

```
undefined
```

---

### 3. Missing object property

```javascript
const user = { name: "John" }

console.log(user.age)
```

Output

```
undefined
```

---

### 4. Missing function parameter

```javascript
function greet(name) {
  console.log(name)
}

greet()
```

Output

```
undefined
```

---

# null

`null` is **assigned intentionally** to represent **empty or no value**.

## Example

```javascript
let user = null
```

Meaning:

> The variable exists but currently has no value.

---

## Example use cases

- Reset a variable
- Empty object reference
- Placeholder value

```javascript
let selectedUser = null
```

---

# typeof behavior (JavaScript weirdness)

```javascript
typeof undefined // "undefined"
typeof null      // "object"
```

⚠️ `typeof null` returning `"object"` is a **historical bug** in JavaScript.

---

# Equality comparison

## Loose equality (`==`)

```javascript
null == undefined // true
```

Because JavaScript treats them as **equal absence of value**.

---

## Strict equality (`===`)

```javascript
null === undefined // false
```

Different types → not equal.

---

# Conversion Behavior (Important)

```javascript
Number(null)      // 0
Number(undefined) // NaN
```

See:  
[[08-Type Conversions]]

---

# Boolean Context

Both values are **falsy**.

```javascript
Boolean(null)      // false
Boolean(undefined) // false
```

---

# Quick Comparison

| Feature | undefined | null |
|--------|-----------|------|
| Meaning | Value not assigned | Intentional empty value |
| Assigned by | JavaScript | Developer |
| Type | undefined | object (bug) |
| Number conversion | NaN | 0 |
| Boolean conversion | false | false |

---

# Common Interview Traps

## 1. typeof null

```javascript
typeof null // "object"
```

---

## 2. Equality confusion

```javascript
null == undefined  // true
null === undefined // false
```

---

## 3. Conversion trap

```javascript
Number(null)      // 0
Number(undefined) // NaN
```

---

# Mental Model

```
undefined → JavaScript hasn't assigned a value yet
null → Developer intentionally says "no value"
```

---

# When to use which?

## Use `undefined`

Let JavaScript handle it for:

- uninitialized variables
- missing values
- default states

---

## Use `null`

Use when you want to **explicitly indicate empty value**.

```javascript
let currentUser = null
```

Meaning:

> A value may exist later, but currently none is assigned.

---

# Interview Summary

Important points:

- `undefined` = default value by JavaScript
- `null` = intentional empty value
- `typeof null` → `"object"` (bug)
- `null == undefined` → true
- `null === undefined` → false
- `Number(null)` → 0
- `Number(undefined)` → NaN
- Both are **falsy values**

---

# Related Concepts
Truthy Falsy
JavaScript Equality Comparison