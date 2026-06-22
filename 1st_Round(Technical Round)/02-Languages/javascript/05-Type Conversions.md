# JavaScript Type Conversions

JavaScript automatically converts data types when performing operations.  
This process is called **Type Conversion** or **Type Coercion**.

Type conversion happens in two ways:

1. **Implicit Conversion (Type Coercion)** → done automatically by JavaScript  
2. **Explicit Conversion (Type Casting)** → done manually by the developer  

---

# 1. Implicit Type Conversion (Type Coercion)

JavaScript automatically converts values when different types interact.

Example:

```javascript
"5" + 2
```

Output

```
"52"
```

Reason

```
2 → "2"
```

String concatenation happens.

---

Another example

```javascript
"5" - 2
```

Output

```
3
```

Reason

```
"5" → 5
```

Subtraction forces **number conversion**.

---

### Important Rule

If **+ operator sees a string → everything becomes a string**

Example

```javascript
1 + "2" + 3
```

Output

```
"123"
```

---

# 2. Explicit Type Conversion (Type Casting)

Explicit conversion is performed manually using built-in functions.

Common methods:

```
String()
Number()
Boolean()
parseInt()
parseFloat()
```

Example

```javascript
Number("100")  // 100
String(50)     // "50"
Boolean(1)     // true
```

---

# 3. String Conversion

Convert values into strings.

Methods:

- `String()`
- `.toString()`
- String concatenation

Example

```javascript
let value = 100

String(value)      // "100"
value.toString()   // "100"
```

Using concatenation

```javascript
let num = 50

num + ""   // "50"
```

---

# 4. Number Conversion

Convert values into numbers.

Methods

- `Number()`
- `parseInt()`
- `parseFloat()`

Example

```javascript
Number("100")  // 100
Number("10.5") // 10.5
```

Using `parseInt`

```javascript
parseInt("25px") // 25
```

Using `parseFloat`

```javascript
parseFloat("10.75px") // 10.75
```

Invalid conversion

```javascript
Number("hello") // NaN
```

`NaN` means **Not a Number**.

---

### Special Number Conversions

```javascript
Number(true)  // 1
Number(false) // 0
Number(null)  // 0
Number(undefined) // NaN
```

These are common **interview traps**.

---

# 5. Boolean Conversion

Convert values into boolean.

Method

```
Boolean(value)
```

Example

```javascript
Boolean(1)       // true
Boolean(0)       // false
Boolean("hello") // true
Boolean("")      // false
```

---

# 6. Truthy and Falsy Values

When values are used in conditions, JavaScript converts them to **boolean**.

JavaScript internally uses:

```javascript
Boolean(value)
```

Only **6 values are falsy**:

```
false, 0, "", null, undefined, NaN
```

Everything else is **truthy**.

Example

```javascript
if("hello"){
  console.log("Runs")
}
```

Output

```
Runs
```

For detailed explanation and edge cases → [[09-Truthy and Falsy]]

---

# 7. Loose Equality vs Strict Equality

JavaScript has two comparison operators. 

refer [[12-Equality Comparison]]

---

## Loose Equality (`==`)

Performs **type coercion** before comparison.

Example

```javascript
5 == "5"
```

Output

```
true
```

Because `"5"` becomes `5`.

---

## Strict Equality (`===`)

Does **not perform type conversion**.

Example

```javascript
5 === "5"
```

Output

```
false
```

Because types differ.

---

# 8. Common Type Coercion Examples

Example

```javascript
"5" + 2
```

Output

```
"52"
```

---

Example

```javascript
"5" - 2
```

Output

```
3
```

---

Example

```javascript
true + 1
```

Output

```
2
```

Reason

```
true → 1
false → 0
```

---

Example

```javascript
null + 1
```

Output

```
1
```

---

Example

```javascript
undefined + 1
```

Output

```
NaN
```

---

# 9. Weird JavaScript Coercion (Interview Traps)

These confuse developers constantly.

Example

```javascript
[] + []
```

Output

```
""
```

Because arrays convert to empty strings.

---

Example

```javascript
[] + {}
```

Output

```
"[object Object]"
```

---

Example

```javascript
{} + []
```

Output may differ depending on context.

---

Example

```javascript
null == undefined
```

Output

```
true
```

But

```javascript
null === undefined
```

Output

```
false
```

---

# 10. Mental Model (Important)

When JavaScript converts values, it usually follows this order:

```
Object → Primitive
Primitive → String / Number / Boolean
```

And operators influence the conversion.

Example

```
+  → prefers strings
-  → prefers numbers
```

---

# 11. Interview Summary

Important things interviewers expect you to know:

- JavaScript performs **automatic type conversion**
- `==` performs **type coercion**
- `===` compares both **value and type**
- JavaScript has **6 falsy values**
- `NaN` represents an invalid number
- `Number(null)` → `0`
- `Number(undefined)` → `NaN`
- `+` prefers **string conversion**
- Arrays convert to strings in many operations

---

# Related Concepts

JavaScript Operators  
JavaScript Truthy Falsy  
JavaScript Equality Comparison