# JavaScript Hoisting

Hoisting is JavaScript's behavior where **variable and function declarations are processed before code execution**.

This happens during the **Creation Phase of the Execution Context**.

Hoisting does **not physically move code**, but JavaScript behaves *as if declarations were moved to the top of their scope*.

---

# Execution Context and Hoisting

When JavaScript runs code, it creates an **Execution Context**.

Each execution context has two phases:

1. **Creation Phase (Memory Creation Phase)**
2. **Execution Phase**

---

## Creation Phase (Memory Allocation)

During this phase JavaScript scans the entire scope and allocates memory.

|Declaration Type|Memory Behavior|
|---|---|
|var|initialized as `undefined`|
|let|created but placed in **Temporal Dead Zone**|
|const|created but placed in **Temporal Dead Zone**|
|function declaration|stored with full function body|

Example memory structure:

```
Creation Phase Memory

a → undefined
b → <TDZ>
c → <TDZ>
greet → function
```

No code runs yet. JavaScript is only **preparing memory**.

---

## Execution Phase

After memory allocation, JavaScript starts executing the code **line by line**.

Now assignments happen and functions execute.

---

# Hoisting with Variables

## Hoisting with var

`var` variables are hoisted and **initialized with undefined** during the creation phase.

Example:

```javascript
console.log(a)

var a = 10
```

Memory Phase:

```
a → undefined
```

Execution Phase:

```
console.log(a) → undefined
a = 10
```

Output:

```
undefined
```

The **declaration is hoisted**, but the **assignment happens later**.

---

## Hoisting with let and const

`let` and `const` are also hoisted, but they are **not initialized immediately**.

Instead they remain inside the **Temporal Dead Zone (TDZ)**.

Example:

```javascript
console.log(a)

let a = 5
```

Creation Phase:

```
a → <TDZ>
```

Execution Phase:

```
console.log(a) → ReferenceError
```

Output:

```
ReferenceError
```

The variable exists but **cannot be accessed yet**.

---

# Temporal Dead Zone (TDZ)

The **Temporal Dead Zone** is the period between:

```
Variable creation
and
Variable initialization
```

Example:

```javascript
{
  console.log(a)
  let a = 10
}
```

The area before `let a = 10` is the **TDZ**.

Accessing the variable during this time causes a **ReferenceError**.

---

# Hoisting with const

`const` behaves like `let` regarding hoisting.

Example:

```javascript
console.log(x)

const x = 10
```

Creation Phase:

```
x → TDZ
```

Execution Phase:

```
console.log(x) → ReferenceError
```

Additionally, `const` **must be initialized during declaration**.

---

# Hoisting with Functions

Function behavior during hoisting depends on **how the function is defined**.

---

## Function Declaration Hoisting

^54928a

Function declarations are **fully hoisted**.

The entire function definition is stored during the **creation phase**.

Example:

```javascript
greet()

function greet(){
  console.log("Hello")
}
```

Creation Phase:

```
greet → function(){ console.log("Hello") }
```

Execution Phase:

```
greet() executes successfully
```

Output:

```
Hello
```

The function already exists in memory before execution begins.

---

## Function Expression Hoisting

^dc5e30

Function expressions behave like **variables**.

Example:

```javascript
greet()

var greet = function(){
  console.log("Hello")
}
```

Creation Phase:

```
greet → undefined
```

Execution Phase:

```
greet() → undefined()
```

Output:

```
TypeError: greet is not a function
```

The variable is hoisted, but the **function assignment happens later**.

---

## Arrow Function Hoisting

Arrow functions behave like **function expressions**.

Example:

```javascript
greet()

const greet = () => {
  console.log("Hello")
}
```

Creation Phase:

```
greet → TDZ
```

Execution Phase:

```
greet() → accessing variable inside TDZ
```

Output:

```
ReferenceError: Cannot access 'greet' before initialization
```

---

# Function Hoisting Comparison

|Function Type|Creation Phase Value|Result|
|---|---|---|
|Function Declaration|Function stored|Works|
|Function Expression (var)|undefined|TypeError|
|Arrow Function (let/const)|TDZ|ReferenceError|

---

# Quick Visual Model

```
Execution Context
      ↓
Creation Phase
      ↓
Memory Allocation
      ↓
var → undefined
let/const → TDZ
function → full function stored
      ↓
Execution Phase
      ↓
Code runs line by line
```

---

# Key Takeaways

- Hoisting happens during the **creation phase of the execution context**
- `var` variables are hoisted and initialized with `undefined`
- `let` and `const` are hoisted but remain in the **Temporal Dead Zone**
- Function declarations are **fully hoisted**
- Function expressions behave like **variables**
- Arrow functions follow **TDZ rules when declared with let/const**

---

# Related Concepts

JavaScript Execution Context  
JavaScript Scope