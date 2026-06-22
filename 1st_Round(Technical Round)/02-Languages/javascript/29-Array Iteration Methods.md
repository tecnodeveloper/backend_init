# JavaScript Array Iteration Methods

Array iteration methods are used to **loop through arrays and process elements** without writing manual loops.

---

# 1. forEach

### Syntax

```
arr.forEach((item, index, array) => {})
```

---

### Example

```javascript
[1,2,3].forEach((num, index) => {
  console.log(num, index)
})
```

---

### Key Points

- Does **NOT return anything** (`undefined`)
- Used for **side effects** (logging, API calls, DOM updates)
- Cannot use `break` or `continue`
- Always iterates through entire array

---

### Edge Cases

```javascript
let result = [1,2,3].forEach(x => x * 2)

console.log(result) // undefined
```

```javascript
[].forEach(x => console.log(x))
// nothing happens
```

---

### Mental Model

```
forEach → just loop, no return
```

---

# 2. map

### Syntax

```
arr.map((item, index, array) => {})
```

---

### Example

```javascript
let result = [1,2,3].map(num => num * 2)

console.log(result) // [2,4,6]
```

---

### Key Points

- Returns a **new array**
- Output length = input length
- Does NOT modify original array
- Used for **transforming data**

---

### Edge Cases

```javascript
[1,2,3].map(() => {})
// [undefined, undefined, undefined]
```

```javascript
[].map(x => x * 2)
// []
```

```javascript
[1,2,3].map(parseInt)
// [1, NaN, NaN] ❌
```

Reason:

```
map passes (value, index)
parseInt(value, radix)
```

Fix:

```javascript
[1,2,3].map(x => parseInt(x))
```

---

### Mental Model

```
map → same size array, values changed
```

---

# 3. filter

### Syntax

```
arr.filter((item, index, array) => {})
```

---

### Example

```javascript
let result = [1,2,3,4].filter(num => num > 2)

console.log(result) // [3,4]
```

---

### Key Points

- Returns a **new array**
- Output size ≤ input size
- Does NOT modify original
- Used for **selecting data**

---

### Edge Cases

```javascript
[1,2,3].filter(() => true)
// [1,2,3]
```

```javascript
[1,2,3].filter(() => false)
// []
```

```javascript
[].filter(x => x > 2)
// []
```

---

### Mental Model

```
filter → keep what matches condition
```

---

%% # 4. reduce

### Syntax

```
arr.reduce((accumulator, current, index, array) => {}, initialValue)
```

---

### Example (Sum)

```javascript
let sum = [1,2,3].reduce((acc, curr) => acc + curr, 0)

console.log(sum) // 6
```

---

### Example (Object Creation)

```javascript
let arr = ["a", "b"]

let result = arr.reduce((acc, curr) => {
  acc[curr] = true
  return acc
}, {})

console.log(result) // {a: true, b: true}
```

---

### Key Points

- Returns a **single value**
- Most flexible method
- Can return number, object, array, etc.

---

### Edge Cases

```javascript
[].reduce((a,b) => a + b)
// ❌ Error
```

Fix:

```javascript
[].reduce((a,b) => a + b, 0)
```

---

```javascript
[1].reduce((a,b) => a + b)
// 1 (no iteration happens)
```

---

### Important Behavior

If no initial value:

- First element → accumulator
- Loop starts from second element

---

### Step-by-Step Example

```javascript
[1,2,3,4].reduce((acc, curr) => acc + curr, 0)
```

Steps:

```
0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
```

---

### Mental Model

```
reduce → take many values → produce one result
```
 %%
---

# 4. reduce

### Syntax

```
arr.reduce((accumulator, current, index, array) => {}, initialValue)
```

---

### What is accumulator?

Accumulator = value that stores the result after each step

---

### Example (Sum)

```javascript
[1,2,3,4].reduce((acc, curr) => acc + curr, 0)
```

Steps:

```
acc = 0

0 + 1 = 1
1 + 2 = 3
3 + 3 = 6
6 + 4 = 10
```

Final result → `10`

---

### Example (Find Max)

```javascript
[1,5,2,9].reduce((acc, curr) => {
  return acc > curr ? acc : curr
}, 0)

// 9
```

---

### Example (Count Occurrences)

```javascript
let arr = ["a","b","a"]

let result = arr.reduce((acc, curr) => {
  acc[curr] = (acc[curr] || 0) + 1
  return acc
}, {})

console.log(result)
// {a: 2, b: 1}
```

---

### Important Behavior

If NO initial value:

```javascript
[1,2,3].reduce((a,b) => a + b)
```

Then:

```
acc = first element (1)
loop starts from second element
```

---

### Edge Cases

```javascript
[].reduce((a,b) => a + b)
// ❌ Error
```

Fix:

```javascript
[].reduce((a,b) => a + b, 0)
```

---

### Common Mistake

```javascript
[1,2,3].reduce((acc, curr) => {
  acc + curr
}, 0)
```

Returns:

```
undefined
```

Fix:

```javascript
return acc + curr
```

---

### Mental Model

```
reduce → build something step by step
```

---

### When to use reduce?

Use when:

- you want a **single value**
- you want to build:
  - sum
  - object
  - grouped data
# 5. Key Differences

| Method | Returns | Output Size | Use Case |
|--------|--------|------------|----------|
| forEach | undefined | same | side effects |
| map | new array | same | transform |
| filter | new array | ≤ same | select |
| reduce | single value | 1 | aggregate |

---

# 6. Common Mistakes

### Mistake 1

```javascript
[1,2,3].map(x => { x * 2 })
// [undefined, undefined, undefined]
```

Fix:

```javascript
[1,2,3].map(x => x * 2)
```

---

### Mistake 2

```javascript
forEach used when return is needed ❌
```

Use `map` instead.

---

### Mistake 3

```javascript
reduce without initial value ❌
```

Always safer to provide initial value.

---

# 7. Mutating vs Non-Mutating Methods

### Non-Mutating (Safe)

These return new arrays and do NOT change original:

```
map
filter
reduce
```

Example:

```javascript
let arr = [1,2,3]

let result = arr.map(x => x * 2)

console.log(arr)    // [1,2,3]
console.log(result) // [2,4,6]
```

---

### Mutating (Modify Original)

These change the original array:

```
push, pop, shift, unshift, splice, sort, reverse
```

Example:

```javascript
let arr = [1,2,3]

arr.push(4)

console.log(arr) // [1,2,3,4]
```

---

### Important Note

Iteration methods (`map`, `filter`, `reduce`) are designed to be **non-mutating**.

But…

You *can still mutate manually* inside them:

```javascript
let arr = [1,2,3]

arr.map((x, i, a) => {
  a[i] = x * 2
})

console.log(arr) // [2,4,6] ❗ mutated
```

So:
```
Method → non-mutating  
Your code → can still mutate
```

# 7. Interview Summary

- `forEach` → no return, used for side effects  
- `map` → transform each element  
- `filter` → select elements  
- `reduce` → combine into one value  
- `map(parseInt)` is a common trap  
- Always give initial value in `reduce`  