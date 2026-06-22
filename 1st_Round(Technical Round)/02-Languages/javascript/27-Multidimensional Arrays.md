# JavaScript Multidimensional Arrays

A multidimensional array is an array that contains **other arrays** as elements.

```javascript
let arr = [
  [1, 2, 3],
  [4, 5, 6]
]
```

This is a **2D array** (array of arrays).

---

# 1. Structure

Think of it like a table:

```
[ [1, 2, 3],
  [4, 5, 6] ]
```

| Index | Value |
|------|------|
| arr[0] | [1,2,3] |
| arr[1] | [4,5,6] |

---

# 2. Accessing Elements

Use **multiple indexes**.

```javascript
let arr = [
  [1, 2, 3],
  [4, 5, 6]
]

console.log(arr[0])     // [1,2,3]
console.log(arr[0][1])  // 2
console.log(arr[1][2])  // 6
```

---

# 3. Modifying Values

```javascript
let arr = [
  [1, 2],
  [3, 4]
]

arr[0][1] = 10

console.log(arr) // [[1,10],[3,4]]
```

---

# 4. Iterating Multidimensional Arrays

### Using nested loops

```javascript
let arr = [
  [1,2],
  [3,4]
]

for(let i = 0; i < arr.length; i++){
  for(let j = 0; j < arr[i].length; j++){
    console.log(arr[i][j])
  }
}
```

---

### Using for...of

```javascript
for(let row of arr){
  for(let value of row){
    console.log(value)
  }
}
```

---

# 5. Adding Elements

### Add new row

```javascript
let arr = [[1,2],[3,4]]

arr.push([5,6])

console.log(arr) // [[1,2],[3,4],[5,6]]
```

---

### Add element inside row

```javascript
arr[0].push(3)

console.log(arr) // [[1,2,3],[3,4]]
```

---

# 6. Common Use Cases

- Matrix representation  
- Grids (game boards, UI layouts)  
- Tables (rows & columns) 

---

# 7. Important Concepts

### Jagged Arrays

Rows can have different lengths.

```javascript
let arr = [
  [1,2],
  [3,4,5]
]
```

Valid in JavaScript.

---

### Reference Behavior

```javascript
let a = [[1,2]]
let b = a

b[0][0] = 99

console.log(a) // [[99,2]]
```

Nested arrays are also **reference types**.

---

# 8. Interview Traps

### Accessing wrong index

```javascript
arr[0][5] // undefined
```

---

### Shallow Copy Issue

```javascript
let arr = [[1,2],[3,4]]

let copy = [...arr]

copy[0][0] = 99

console.log(arr) // [[99,2],[3,4]]
```

Because inner arrays are still referenced.

---

# 9. Interview Summary

- Multidimensional arrays = arrays inside arrays  
- Access using multiple indexes  
- Use nested loops for traversal  
- Arrays can have uneven lengths (jagged arrays)  
- Inner arrays are reference types  
- Shallow copy does NOT clone nested arrays  