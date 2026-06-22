# JavaScript Equality Comparison

JavaScript provides two types of equality comparison:

1. **Loose Equality (`==`)**
2. **Strict Equality (`===`)**

---

# 1. Loose Equality (`==`)

Loose equality compares values **after performing type conversion (coercion)**.

Example

```javascript
5 == "5"
```

Output

```
true
```

Reason

```
"5" → 5
```

---

## More Examples

```javascript
true == 1           // true
false == 0          // true
null == undefined   // true
```

---

## Important Rule

When using `==`, JavaScript tries to convert both values to the **same type** before comparing.

---

# 2. Strict Equality (`===`)

Strict equality compares **value AND type**.

No type conversion is performed.

Example

```javascript
5 === "5"
```

Output

```
false
```

Because:

```
number ≠ string
```

---

## More Examples

```javascript
true === 1           // false
false === 0          // false
null === undefined   // false
```

---

# 3. Key Differences

| Feature | `==` | `===` |
|--------|------|------|
| Type Conversion | Yes | No |
| Compares Value | Yes | Yes |
| Compares Type | No | Yes |
| Recommended | No | Yes |

---

# 4. Truthy vs Equality (Important)

Truthy/falsy and `==` are **different concepts**.

refer [[09-Truthy and Falsy]]

### Boolean Context

```javascript
if([]){
  console.log("Runs")
}
```

Output

```
Runs
```

Because:

```javascript
Boolean([]) // true
```

---

### Loose Equality

```javascript
[] == false   // true
```

This confuses many developers.

---

## Step-by-step Breakdown

```javascript
[] == false
```

Step 1

```
false → 0
```

Step 2

```
[] → ""
```

Step 3

```
"" → 0
```

Final

```
0 == 0 → true
```

---

# 5. Special Cases

### null and undefined

```javascript
null == undefined   // true
null === undefined  // false
```

---

### NaN comparison

```javascript
NaN == NaN   // false
NaN === NaN  // false
```

Correct way:

```javascript
Number.isNaN(NaN) // true
```

---

### Objects and Arrays

```javascript
[] == []   // false
{} == {}   // false
```

Because they are compared by **reference**, not value.

---

# 6. Common Edge Cases (Interview Traps)

### Empty array vs false

```javascript
[] == false   // true
```

---

### Empty string vs false

```javascript
"" == false   // true
```

---

### String vs false

```javascript
"0" == false   // true
```

---

### Array vs number

```javascript
[] == 0   // true
```

---

### Array with value

```javascript
[1] == 1   // true
```

---

### Weird case

```javascript
[] == ![]
```

Breakdown

```javascript
![] → false
[] == false → true
```

Final

```
true
```

---

# 7. Type Coercion Rules (Simplified)

When using `==`, JavaScript follows these conversions:

```
boolean → number
string → number
object → primitive → string → number
```

---

# 8. Best Practice

Always prefer:

```javascript
===
```

Avoid:

```javascript
==
```

Unless you fully understand coercion.

---

# 9. Mental Model (Important)

Remember:

```
Truthy/Falsy → Boolean conversion
==           → Type coercion rules
```

They are **not the same thing**.

---

# 10. Interview Summary

- `==` performs **type coercion**
- `===` compares **value and type**
- `null == undefined` → true
- `NaN !== NaN`
- Objects are compared by **reference**
- `[] == false` → true (due to coercion)
- Truthy/falsy is different from equality comparison
- Always prefer `===` in real-world code

---

