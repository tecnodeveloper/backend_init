# JavaScript Math Object

JavaScript provides a built-in **Math object** for performing mathematical operations.

It is a **static object**, meaning you do not create it using `new`.

---

# Basic Usage

```javascript
Math.method()
```

Example:

```javascript
Math.round(4.6) // 5
```

---

# Common Math Methods

## Math.round()

Rounds to the nearest integer.

```javascript
Math.round(4.4) // 4
Math.round(4.6) // 5
```

---

## Math.floor()

Rounds **down** to the nearest integer.

```javascript
Math.floor(4.9) // 4
```

---

## Math.ceil()

Rounds **up** to the nearest integer.

```javascript
Math.ceil(4.1) // 5
```

---

## Math.trunc()

Removes decimal part.

```javascript
Math.trunc(4.9) // 4
```

---

## Math.random()

Generates a random number between **0 and 1**.

```javascript
Math.random()
```

### Random integer example

```javascript
Math.floor(Math.random() * 100)
```

Range: `0 → 99`

---

## Math.max()

Returns the largest value.

```javascript
Math.max(10, 20, 5) // 20
```

---

## Math.min()

Returns the smallest value.

```javascript
Math.min(10, 20, 5) // 5
```

---

## Math.pow()

Raises a number to a power.

```javascript
Math.pow(2, 3) // 8
```

Alternative (modern):

```javascript
2 ** 3 // 8
```

---

## Math.sqrt()

Returns square root.

```javascript
Math.sqrt(25) // 5
```

---

## Math.abs()

Returns absolute value.

```javascript
Math.abs(-10) // 10
```

---

# Math Constants

## Math.PI

```javascript
Math.PI // 3.141592653589793
```

---

## Math.E

```javascript
Math.E // 2.718...
```

---

# Random Number Patterns (Important)

## Random between 0–9

```javascript
Math.floor(Math.random() * 10)
```

---

## Random between min and max

```javascript
let min = 1
let max = 10

Math.floor(Math.random() * (max - min + 1)) + min
```

---

# Common Use Cases

- Rounding values
- Generating random numbers
- Calculations (power, square root)
- Finding min/max values

---

# Interview Summary

Important points:

- Math is a **static object**
- `Math.random()` gives values between **0 and 1**
- Use `Math.floor()` for integer conversion
- `Math.pow()` can be replaced with `**`
- `Math.round()`, `floor()`, `ceil()` behave differently

---

