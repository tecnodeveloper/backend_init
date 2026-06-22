# JavaScript Operators

Operators are used to perform operations on variables and values.

---

# 1. Arithmetic Operators

Used for mathematical calculations.

| Operator | Description | Example |
|--------|------------|--------|
| + | Addition | 5 + 2 → 7 |
| - | Subtraction | 5 - 2 → 3 |
| * | Multiplication | 5 * 2 → 10 |
| / | Division | 5 / 2 → 2.5 |
| % | Modulus (remainder) | 5 % 2 → 1 |
| ** | Exponentiation | 2 ** 3 → 8 |

---

# 2. Assignment Operators

Used to assign values.

```javascript
let x = 10
```

Common types:

```javascript
x += 5   // x = x + 5
x -= 5
x *= 2
x /= 2
x %= 2
```

---

# 3. Comparison Operators

Used to compare values. Returns boolean.

```javascript
5 > 3   // true
5 < 3   // false
```

| Operator | Meaning |
|--------|--------|
| == | Loose equality |
| === | Strict equality |
| != | Not equal |
| !== | Strict not equal |
| > | Greater than |
| < | Less than |
| >= | Greater than or equal |
| <= | Less than or equal |

---

# 4. Logical Operators

Used for combining conditions.

| Operator | Description |
| -------- | ----------- |
| &&       | AND         |
| \|\|     | OR          |
| !        | NOT         |

---

## Examples

```javascript
true && false   // false
true || false   // true
!true           // false
```

---

## Short-Circuit Behavior

### AND (`&&`)

Returns first falsy value or last value.

```javascript
0 && "Hello"   // 0
"Hi" && "JS"   // "JS"
```

---

### OR (`||`)

Returns first truthy value.

```javascript
"" || "Default"   // "Default"
"Hello" || "JS"   // "Hello"
```

---

# 5. Ternary Operator

Short form of if-else.

```javascript
condition ? value1 : value2
```

Example

```javascript
let age = 18

let result = age >= 18 ? "Adult" : "Minor"
```

---

# 6. Type Operators

### typeof

Returns the type of a variable.

```javascript
typeof "hello"  // string
typeof 10       // number
typeof true     // boolean
typeof {}       // object
```

---

# 7. Special Operators

### Nullish Coalescing (`??`)

Returns right side only if left is `null` or `undefined`.

```javascript
null ?? "Default"       // "Default"
undefined ?? "Default"  // "Default"
0 ?? 10                // 0
```

---

### Optional Chaining (`?.`)

Prevents errors when accessing nested properties.

```javascript
user?.name
```

If `user` is null/undefined → returns undefined instead of error.

---

# 8. Operator Precedence (Basic Idea)

Operators follow priority rules.

Example

```javascript
2 + 3 * 4   // 14
```

Because `*` has higher precedence than `+`.

---

# 9. Interview Summary

- Operators perform operations on values
- `===` is preferred over `==`
- `&&` returns first falsy value
- `||` returns first truthy value
- `??` works only with null and undefined
- `typeof null` → "object" (known bug)
- Operator precedence affects evaluation order

---



