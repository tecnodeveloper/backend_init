# Constructor Functions

## Definition

A constructor function is a special type of function used to create multiple objects with the same structure using the `new` keyword.

It acts as a blueprint for creating objects.

---

## Syntax
```javascript
    function FunctionName(param1, param2) {
      this.property = param1
    }

    const obj = new FunctionName(value1, value2)
```




---

## Basic Example
```javascript
    function User(name, age) {
      this.name = name
      this.age = age
    }

    const user1 = new User("John", 25)

    console.log(user1.name)

```

```javascript
```

---

## Additional Examples

```javascript
 function Car(brand, price) {
      this.brand = brand
      this.price = price
    }

    const car1 = new Car("BMW", 50000)
    const car2 = new Car("Audi", 60000)
``` 
---
```javascript
function Person(name) {
      this.name = name
    }

    Person.prototype.greet = function () {
      return "Hello " + this.name
    }

    const p1 = new Person("Sam")
    p1.greet()
  
```
---

## Calling vs Invoking (if applicable)

- Calling a constructor uses `new`
- Invoking without `new` runs it like a normal function

```javascript
   function User(name) {
      this.name = name
    }

    new User("John")
    User("John")

```

---

## How It Works Internally (if applicable)

1. A new empty object is created  
2. `this` is set to that object  
3. Properties are assigned  
4. Object is returned automatically  

---

## When to use

- Creating multiple similar objects  
- Working with prototypes  
- Interview scenarios  

---

## When NOT to use

- Modern apps (use classes)  
- Simple object creation  
- No reuse needed  

---

## Behavior

- Functions are hoisted  
- `this` depends on call  
- `new` ensures correct object creation  
- Prototype enables method sharing  

---

## Edge Cases

### Code

 ``` javascript
    function User(name) {
      this.name = name
      return { name: "Override" }
    }

    const u = new User("John")
    console.log(u.name)
 ```

### What happens

Returned object replaces default object.

### Why it is an edge case

Explicit object return overrides constructor behavior.

---

### Code

```javascript
    function User(name) {
      this.name = name
      return 100
    }

    const u = new User("John")
    console.log(u.name)
```
### What happens

Primitive return is ignored.

### Why it is an edge case

Only objects override return, primitives do not.

---

### Code

```javascript
    function User(name) {
      this.name = name
    }

    const u = new User("John", 25)
    console.log(u.name)
```
### What happens

Extra arguments are ignored.

### Why it is an edge case

JavaScript does not enforce argument count.

---

## Common Mistakes

### ❌ Wrong Code

```javascript
    function user(name) {
      this.name = name
    }

    const u = new user("John")
```

### Why it is a mistake

Constructor naming convention is violated.

### ✅ Fix
```javascript
    function User(name) {
      this.name = name
    }

    const u = new User("John")
```

### Why the fix works

Uppercase naming indicates constructor usage.

---

### ❌ Wrong Code
```javascript
    function User(name) {
      this.name = name
    }

    const u = User("John")
```

### Why it is a mistake

`this` is not bound to a new object.

### ✅ Fix
```javascript
    const u = new User("John")

```
### Why the fix works

`new` creates object and binds `this`.

---

### ❌ Wrong Code

```javascript
    function User(name) {
      this.name = name

      this.greet = function () {
        return "Hello"
      }
    }
```

### Why it is a mistake

Method is recreated for every instance.

### ✅ Fix

```javascript
    function User(name) {
      this.name = name
    }

    User.prototype.greet = function () {
      return "Hello"
    }
```

### Why the fix works

Method is shared across instances using prototype.