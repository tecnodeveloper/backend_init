# JavaScript Optional Chaining (?.)

Optional chaining is used to **safely access nested object properties** without causing errors if a property does not exist.

---

## Definition

Prevents runtime errors when accessing properties of `undefined` or `null`.

---

## Syntax

```javascript
obj?.property
obj?.[key]
obj?.method()
```

---

## Example

### Without optional chaining ❌

```javascript
const user = {}

console.log(user.address.city) 
// ❌ Error: Cannot read properties of undefined
```

---

### With optional chaining ✅

```javascript
console.log(user.address?.city) 
// ✅ undefined (no error)
```

---

## Nested Example

```javascript
const user = {
  profile: {
    name: "John"
  }
}

console.log(user.profile?.name) // John
console.log(user.address?.city) // undefined
```

---

## Array Example

```javascript
const users = [{ name: "John" }]

console.log(users[0]?.name) // John
console.log(users[1]?.name) // undefined
```

---

## Function Example

```javascript
const user = {
  greet() {
    return "Hello"
  }
}

console.log(user.greet?.()) // Hello
console.log(user.sayHi?.()) // undefined
```

---

# ⚠️ Edge Cases

### 1. Only stops at null/undefined

```javascript
const obj = { a: null }

console.log(obj.a?.b) // undefined
```

- Works because `a` is null

---

### 2. Does NOT stop other errors

```javascript
const obj = { a: 10 }

console.log(obj.a?.b) // undefined (safe)

console.log(obj.a.toUpperCase()) // ❌ Error (not a function)
```

---

### 3. Cannot assign using optional chaining

```javascript
obj?.name = "John" // ❌ Error
```

---

# ❌ Common Mistakes

### Accessing without optional chaining

```javascript
const user = {}

console.log(user.address.city) // ❌ Error
```

### Why it is wrong
- `address` is undefined  
- Trying to access `.city` causes runtime error  

### Fix
```javascript
console.log(user.address?.city) // ✅ undefined
```

### How it fixes
- Stops execution if `address` is undefined  
- Returns `undefined` instead of crashing  

---

### Overusing optional chaining

```javascript
console.log(user?.name?.toUpperCase())
```

### Why it is wrong
- If `name` is undefined, result becomes `undefined`  
- You may hide bugs unintentionally  

### Fix
```javascript
if (user.name) {
  console.log(user.name.toUpperCase())
}
```

### How it fixes
- Ensures value exists before using it  
- Prevents silent failures  

---

### Using with non-existing root object

```javascript
console.log(user?.name) // ❌ if user is not defined at all
```

### Why it is wrong
- Optional chaining does NOT work on undeclared variables  

### Fix
```javascript
let user

console.log(user?.name) // ✅ undefined
```

### How it fixes
- Variable is declared, so JS can safely evaluate it  

---

# 💡 When to Use

- Accessing **API response data**
- Deeply nested objects
- Optional properties
- Function calls that may not exist

---

# 🚫 When NOT to Use

- When you expect value to always exist  
- When it hides real bugs  

---