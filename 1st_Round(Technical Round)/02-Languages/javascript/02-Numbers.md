# JavaScript Numbers

JavaScript uses a **single number type** to represent both integers and floating-point values.

Example:

```javascript
let a = 10        // integer
let b = 3.14      // floating point
```

---

# Number Basics

JavaScript numbers are based on **IEEE 754 (double precision)**.

This allows:

- Large range of values
- Decimal precision (with some limitations)

---

# Creating Numbers

```javascript
let num1 = 100
let num2 = 10.5
let num3 = Number("50") // explicit conversion
```

See:  
[[08-Type Conversions]]

---

# Special Numeric Values

## NaN (Not a Number)

Represents an invalid number. refer [[11-NaN]]

```javascript
Number("hello") // NaN
```

Check using:

```javascript
Number.isNaN(NaN) // true
```

---

## Infinity

Represents values larger than the maximum limit.

```javascript
1 / 0 // Infinity
-1 / 0 // -Infinity
```

---

# Number Methods

## toFixed()

Formats number to fixed decimal places.

```javascript
let num = 10.567

num.toFixed(2)
```

Output

```
"10.57"
```

---

## toString()

Converts number to string.

```javascript
let num = 100

num.toString()
```

Output

```
"100"
```

---

## parseInt()

Extracts integer from string.

```javascript
parseInt("25px") // 25
```

---

## parseFloat()

Extracts decimal number.

```javascript
parseFloat("10.75px") // 10.75
```

---

# Math Object

JavaScript provides a built-in **Math object** for calculations.
refer [[13-Math Object]]

---

## Math.round()

Rounds to nearest integer.

```javascript
Math.round(4.6) // 5
```

---

## Math.floor()

Rounds down.

```javascript
Math.floor(4.9) // 4
```

---

## Math.ceil()

Rounds up.

```javascript
Math.ceil(4.1) // 5
```

---

## Math.random()

Generates random number between 0 and 1.

```javascript
Math.random()
```

Random integer example:

```javascript
Math.floor(Math.random() * 100)
```

---

# Floating Point Precision Issue

JavaScript cannot precisely represent some decimal values.

Example:

```javascript
0.1 + 0.2
```

Output

```
0.30000000000000004
```

Reason:

- Binary representation of decimals is not exact

---

# Fixing Precision Issues

```javascript
(0.1 + 0.2).toFixed(2)
```

Output

```
"0.30"
```

Or:

```javascript
Number((0.1 + 0.2).toFixed(2))
```

---

# Number Conversion (Important)

JavaScript often converts values into numbers.

Example:

```javascript
"5" - 2
```

Output

```
3
```

See:  
[[08-Type Conversions]]

---

# Checking Numbers

```javascript
typeof 10 // "number"
```

Check if value is finite:

```javascript
Number.isFinite(10) // true
```

---

# Interview Summary

Important points:

- JavaScript has **only one number type**
- Uses **IEEE 754 floating point**
- `NaN` represents invalid numbers
- `Infinity` represents overflow
- `parseInt()` and `parseFloat()` extract numbers
- Floating point precision is not exact
- Math object provides utility functions

---

# Related Concepts
[[08-Type Conversions]]  
JavaScript Math Object