# JavaScript Arrays

Arrays are used to store **multiple values in a single variable**.

```javascript
let numbers = [1, 2, 3, 4]
```

Arrays are a special type of **object** in JavaScript.

---

# 1. Creating Arrays

### Using array literal

**Syntax**

```javascript
let arr = [element1, element2, element3]
```

Example

```javascript
let arr = [1, 2, 3]
```

---

### Using Array constructor

**Syntax**

```javascript
let arr = new Array(element1, element2, element3)
```

Example

```javascript
let arr = new Array(1, 2, 3)
```

---

### Edge Case

```javascript
let arr1 = new Array(3)
console.log(arr1) // [empty × 3]

let arr2 = new Array(1, 2, 3)
console.log(arr2) // [1, 2, 3]
```

If `Array()` gets **one number**, it creates an array with that length.  
If it gets **multiple values**, it creates an array with those values.

Because JavaScript enjoys ambiguity more than it should.

---

# 2. Accessing Elements

Arrays are **zero-indexed**, which means indexing starts from `0`.

**Syntax**

```javascript
arr[index]
```

Example

```javascript
let arr = ["a", "b", "c"]

console.log(arr[0]) // "a"
console.log(arr[2]) // "c"
```

---

### Edge Cases

```javascript
let arr = ["a", "b", "c"]

console.log(arr[5])   // undefined
console.log(arr[-1])  // undefined
```

Normal array indexing does not support negative indexes directly. which usually works in python or other languages , which bring and show the element from last .

---

# 3. Modifying Arrays

Array elements can be changed using their index.

**Syntax**

```javascript
arr[index] = newValue
```

Example

```javascript
let arr = [1, 2, 3]

arr[1] = 10

console.log(arr) // [1, 10, 3]
```

---

### Adding value at a higher index

```javascript
let arr = [1, 2]

arr[5] = 100

console.log(arr) // [1, 2, empty × 3, 100]
console.log(arr.length) // 6
```

This creates **empty slots** in between.

---

# 4. Array Properties

## length

Returns the number of elements up to the highest index + 1.

**Syntax**

```javascript
arr.length
```

Example

```javascript
let arr = [1, 2, 3]

console.log(arr.length) // 3
```

---

### Changing length

```javascript
let arr = [1, 2, 3, 4]

arr.length = 2

console.log(arr) // [1, 2]
```

You can reduce array size by changing `length`.

---

### Edge Case

```javascript
let arr = []
arr[3] = "x"

console.log(arr.length) // 4
```

Length depends on the **highest index**, not just visible values.

---

# 5. Common Array Methods

Arrays have built-in methods to add, remove, search, and modify elements.

## Adding Elements

```javascript
arr.push(4)     // add to end
arr.unshift(0)  // add to beginning
```

## Removing Elements

```javascript
arr.pop()     // remove last
arr.shift()   // remove first
```

## Finding Elements

```javascript
arr.indexOf(2)   // returns index
arr.includes(2)  // returns true/false
```

## Slicing & Splicing

### slice (non-destructive)

```javascript
arr.slice(1, 3) // [2, 3]
```

### splice (destructive)

```javascript
arr.splice(1, 2) // [1,4]
```

For detailed explanation, syntax, and edge cases → [[Array Methods#5. Slicing & Splicing]]

---

# 6. Iterating Arrays

Iteration means going through array elements one by one.

## for loop

**Syntax**

```javascript
for(initialization; condition; update){
  // code
}
```

Example

```javascript
let arr = [10, 20, 30]

for(let i = 0; i < arr.length; i++){
  console.log(arr[i])
}
```

---

## for...of

Used to directly access values.

**Syntax**

```javascript
for(let value of arr){
  // code
}
```

Example

```javascript
let arr = [10, 20, 30]

for(let value of arr){
  console.log(value)
}
```

---

## forEach

Runs a callback for each element.

**Syntax**

```javascript
arr.forEach((item, index) => {
  // code
})
```

Example

```javascript
let arr = [10, 20, 30]

arr.forEach((item, index) => {
  console.log(item, index)
})
```

---

### Important Note

- `for` loop gives full control
- `for...of` is cleaner for values
- `forEach` cannot be stopped using `break` or `continue`

For advanced iteration methods → [[Array Iteration Methods]]

---

# 7. Important Concepts

## Arrays are Objects

```javascript
typeof [] // "object"
```

So arrays are technically objects, but they are used for **ordered collections**.

To correctly check an array:

```javascript
Array.isArray([]) // true
```

---

## Reference Behavior

Arrays are copied by **reference**, not by value.

```javascript
let a = [1, 2]
let b = a

b.push(3)

console.log(a) // [1, 2, 3]
```

Both variables point to the same array in memory.

---

## Empty Slots

```javascript
let arr = new Array(3)

console.log(arr) // [empty × 3]
```

These are not the same as `undefined` values.

### Example

```javascript
let a = [undefined]
let b = new Array(1)

console.log(a) // [undefined]
console.log(b) // [empty × 1]
```

---

## Array Destructuring

Used to extract values into variables.

**Syntax**

```javascript
let [a, b] = arr
```

Example

```javascript
let arr = [10, 20]

let [x, y] = arr

console.log(x) // 10
console.log(y) // 20
```

---

## Spread Operator with Arrays

Used to copy or merge arrays.

```javascript
let a = [1, 2]
let b = [...a, 3]

console.log(b) // [1, 2, 3]
```

This is a **shallow copy**.

---

# 8. Multidimensional Arrays

A multidimensional array is an array that contains **other arrays**.

Example

```javascript
let matrix = [
  [1, 2],
  [3, 4]
]
```

Accessing nested values:

```javascript
console.log(matrix[0][1]) // 2
```

For full explanation → [[05-Multidimensional Arrays]]

---

# 9. Interview Traps

## Comparing arrays

```javascript
[] == []   // false
[] === []  // false
```

Arrays are compared by **reference**, not by value.

---

## typeof array

```javascript
typeof [] // "object"
```

---

## Checking array

```javascript
Array.isArray([]) // true
```

---

## Empty array is truthy

```javascript
if([]){
  console.log("Runs")
}
```

Output

```javascript
Runs
```

Even empty arrays are **truthy**.

---

## Array constructor confusion

```javascript
new Array(5)       // empty array with length 5
new Array("5")     // ["5"]
```

---

# 10. Interview Summary

- Arrays store multiple values in one variable
- Arrays are **zero-indexed**
- Arrays are a special type of **object**
- `length` depends on the highest index
- Arrays are copied by **reference**
- Empty slots are different from `undefined`
- `push/pop` work at the end
- `shift/unshift` work at the beginning
- `slice` is non-destructive
- `splice` is destructive
- Use `Array.isArray()` to check arrays
- Multidimensional arrays are arrays inside arrays