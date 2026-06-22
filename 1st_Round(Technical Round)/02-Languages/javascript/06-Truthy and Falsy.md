# JavaScript Truthy and Falsy

In JavaScript, every value is either **truthy** or **falsy** when used in a boolean context.

This happens automatically in conditions like:

```javascript
if(value){
  // runs if truthy
}
```

JavaScript internally converts values using:

```javascript
Boolean(value)
```

---

# 1. Falsy Values

There are only **6 falsy values** in JavaScript.

```
false
0
""
null
undefined
NaN
```

These always evaluate to **false**.

---

## Example

```javascript
if(0){
  console.log("Will not run")
}
```

Because `0` is falsy.

---

# 2. Truthy Values

Everything that is **not falsy** is truthy.

Examples:

```
"hello"
1
[]
{}
true
"0"
"false"
```

---

## Example

```javascript
if("hello"){
  console.log("Runs")
}
```

Output

```
Runs
```

---

# 3. Important Rules

### Rule 1

Only **6 falsy values exist**. Everything else is truthy.

---

### Rule 2

Empty structures are still truthy.

```javascript
Boolean([])  // true
Boolean({})  // true
```

---

### Rule 3

Strings matter

```javascript
Boolean("")     // false
Boolean(" ")    // true (space is a character)
Boolean("0")    // true
```

---

# 4. Common Mistakes

### Mistake 1

```javascript
if([]){
  console.log("Runs")
}
```

Many expect false, but it runs because arrays are truthy.

---

### Mistake 2

```javascript
if({}){
  console.log("Runs")
}
```

Objects are also truthy.

---

### Mistake 3

```javascript
if("false"){
  console.log("Runs")
}
```

Strings are truthy unless empty.

---

# 5. Boolean Conversion Examples

```javascript
Boolean(false)      // false
Boolean(0)          // false
Boolean("")         // false
Boolean(null)       // false
Boolean(undefined)  // false
Boolean(NaN)        // false
```

Everything else → true

---

# 6. Real Use Cases

### Default Values

```javascript
let name = input || "Guest"
```

If `input` is falsy, `"Guest"` is used.

---

### Conditional Checks

```javascript
if(user){
  // user exists
}
```

---

### Filtering Values

```javascript
[0, 1, "", "hello", null].filter(Boolean)
```

Output

```
[1, "hello"]
```

---

# 7. Interview Summary

- JavaScript has **only 6 falsy values**
- Everything else is **truthy**
- Empty arrays `[]` and objects `{}` are **truthy**
- `"0"` and `"false"` are **truthy**
- Boolean conversion happens automatically in conditions
- `Boolean(value)` is used internally

---

