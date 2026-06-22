# JavaScript Array Methods

Array methods are used to **add, remove, search, and transform data** inside arrays.

---

# 1. Adding Elements

### push

**Syntax**

```
arr.push(element1, element2, ...)
```

Adds element(s) to the **end**.

```javascript
let arr = [1,2]

arr.push(3)

console.log(arr) // [1,2,3]
```

---

### unshift

**Syntax**

```
arr.unshift(element1, element2, ...)
```

Adds element(s) to the **beginning**.

```javascript
let arr = [2,3]

arr.unshift(1)

console.log(arr) // [1,2,3]
```

---

# 2. Removing Elements

### pop

**Syntax**

```
arr.pop()
```

Removes last element.

```javascript
let arr = [1,2,3]

let removed = arr.pop()

console.log(removed) // 3
console.log(arr)     // [1,2]
```

---

### shift

**Syntax**

```
arr.shift()
```

Removes first element.

```javascript
let arr = [1,2,3]

let removed = arr.shift()

console.log(removed) // 1
console.log(arr)     // [2,3]
```

---

# 3. Finding Elements

### indexOf

**Syntax**

```
arr.indexOf(value)
```

```javascript
[1,2,3].indexOf(2) // 1
```

---

### includes

**Syntax**

```
arr.includes(value)
```

```javascript
[1,2,3].includes(2) // true
```

---

### find

**Syntax**

```
arr.find(callback)
```

Returns first matching element.

```javascript
[1,2,3,4].find(num => num > 2) // 3
```

---

### Edge Case

```javascript
[NaN].indexOf(NaN)   // -1
[NaN].includes(NaN)  // true
```

Because `indexOf` uses `===`, but `includes` handles `NaN`.

---

# 4. Filtering & Transforming

### map

**Syntax**

```
arr.map(callback)
```

Transforms each element.

```javascript
[1,2,3].map(x => x * 2) // [2,4,6]
```

---

### filter

**Syntax**

```
arr.filter(callback)
```

Returns elements that match condition.

```javascript
[1,2,3,4].filter(x => x > 2) // [3,4]
```

---

### reduce

**Syntax**

```
arr.reduce((accumulator, current) => {}, initialValue)
```

Reduces array to single value.

```javascript
[1,2,3].reduce((acc, curr) => acc + curr, 0) // 6
```

---

### Edge Case (reduce)

```javascript
[].reduce((a,b) => a + b)
// ❌ Error
```

Fix:

```javascript
[].reduce((a,b) => a + b, 0) // 0
```

---

# 5. Slicing & Splicing

## slice() → Non-Destructive (Safe Copy)

### Syntax

```
arr.slice(start, end)
```

---

### Key Points

- Returns a **shallow copy** of part of the array  
- **Does NOT modify** the original array  
- `end` index is **NOT included**  
- Supports **negative indexing**  
- No arguments → returns full copy  

---

### Examples

```javascript
let arr = [1, 2, 3, 4]

arr.slice(1, 3)   // [2, 3]
arr.slice(2)      // [3, 4]
arr.slice()       // [1, 2, 3, 4]
```

---

### Negative Indexing

```javascript
[1,2,3].slice(-1) // [3]
[1,2,3].slice(-2) // [2,3]
```

---

### Edge Cases

```javascript
[1,2,3].slice(5)      // []
[1,2,3].slice(2,1)    // []
[1,2,3].slice(-5, 2)  // [1,2]
```

---

### Mental Model

```
slice → copy without touching original
```

---

## splice() → Destructive (Modify Original)

### Syntax

```
arr.splice(start, deleteCount, item1, item2, ...)
```

---

### Parameters

- `start` → index to begin changes  
- `deleteCount` → number of elements to remove  
- `item1...` → elements to insert 
### Key Points

- **Modifies original array**  
- Returns **removed elements**  
- Can:
  - remove  
  - insert  
  - replace  

---

### Remove Elements

```javascript
let arr = [1,2,3,4]

let removed = arr.splice(1,2)

console.log(removed) // [2,3]
console.log(arr)     // [1,4]
```

---

### Insert Elements

```javascript
let arr = [1,2,3]

arr.splice(1,0,100)

console.log(arr) // [1,100,2,3]
```

---

### Replace Elements

```javascript
let arr = [1,2,3]

arr.splice(1,1,99)

console.log(arr) // [1,99,3]
```

---

### Edge Cases

```javascript
[1,2,3].splice(1)     
// removes [2,3], arr becomes [1]

[1,2,3].splice(-1)    
// removes [3]

[1,2,3].splice(5,1)   
// [], nothing removed

[1,2,3].splice(1,10)  
// removes [2,3]

[1,2,3].splice(1,0)   
// [], no change
```

### Mental Model

```
splice → cut / insert / replace in original array
```

# Final Difference

| Feature | slice | splice |
|--------|------|--------|
| Modifies original | ❌ No | ✅ Yes |
| Returns | Copied portion | Removed elements |
| Use case | Read / copy | Update / mutate |

---
# 6. Other Useful Methods

### concat

**Syntax**

```
arr.concat(array2)
```

```javascript
[1,2].concat([3,4]) // [1,2,3,4]
```

---

### join

**Syntax**

```
arr.join(separator)
```

```javascript
["a","b"].join("-") // "a-b"
```

---

### reverse

```javascript
[1,2,3].reverse() // [3,2,1]
```

⚠️ modifies original

---

### sort

**Syntax**

```
arr.sort(compareFn)
```

```javascript
[3,1,2].sort() // [1,2,3]
```

---

### Edge Case

```javascript
[10,2,5].sort() // [10,2,5]
```

Fix:

```javascript
[10,2,5].sort((a,b) => a - b)
```

---

# 7. Important Concepts

### Destructive Methods

```
push, pop, shift, unshift, splice, reverse, sort
```

---

### Non-Destructive Methods

```
map, filter, slice, concat
```

---

# 8. Interview Summary

- `push/pop` → end  
- `shift/unshift` → start  
- `slice` → safe (no mutation)  
- `splice` → modifies array  
- `map` → transform  
- `filter` → condition  
- `reduce` → single value  
- `sort()` needs compare function  
- `includes` works with `NaN`, `indexOf` does not  

---

