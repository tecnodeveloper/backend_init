# JavaScript Classes

## Definition

A class in JavaScript is a blueprint for creating objects with predefined properties and methods.

It provides a cleaner and more structured way to create objects compared to constructor functions.

---

## Syntax

~~~javascript
class ClassName {
  constructor(param) {
    this.property = param
  }

  methodName() {
    // logic
  }
}
~~~

---

## Basic Example

~~~javascript
class Person {
  constructor(name, age) {
    this.name = name
    this.age = age
  }

  greet() {
    console.log("Hello " + this.name)
  }
}

const user = new Person("John", 25)
user.greet()
~~~

---

## Additional Examples

### Multiple Methods

~~~javascript
class Car {
  constructor(brand) {
    this.brand = brand
  }

  start() {
    console.log(this.brand + " started")
  }

  stop() {
    console.log(this.brand + " stopped")
  }
}

const c = new Car("BMW")
c.start()
c.stop()
~~~

 %% output should be there   %%

---

### Default Values

~~~javascript
class User {
  constructor(name = "Guest") {
    this.name = name
  }
}

const u1 = new User()
console.log(u1.name)
~~~

---

### Dynamic Property Assignment

~~~javascript
class Product {
  constructor(name, price) {
    this.name = name
    this.price = price
  }
}

const p = new Product("Laptop", 50000)
console.log(p)
~~~

 %% output should be there   %%
 
---

## When to use

- When creating multiple objects with same structure  
- When organizing related data and behavior  
- When building scalable applications  

## When NOT to use

- Simple one-time objects  
- Small scripts where classes add unnecessary complexity  

## Behavior

- Classes are syntactic sugar over prototypes  
- Objects created using `new` are instances of the class  
- Methods are stored in the prototype, not inside each object  
- `this` refers to the current instance  

---

## Hoisting (only if applicable)

- Classes are hoisted but not initialized  
- They exist in the Temporal Dead Zone (TDZ)  
- Cannot be used before declaration  

~~~javascript
const obj = new Person() // ❌ Error

class Person {}
~~~

---

## Edge Cases

### Missing `new` Keyword

~~~javascript
class Person {
  constructor(name) {
    this.name = name
  }
}

const p = Person("John")
~~~

### Output

~~~javascript
TypeError
~~~

### Why it is an edge case

Classes must be called using `new`.


### Fix

~~~javascript
const p = new Person("John")
~~~

### Output

~~~javascript
Person { name: "John" }
~~~

### Why the fix works

`new` creates an instance and binds `this` correctly.

---

## Common Mistakes

### ❌ Wrong Code

~~~javascript
class User {
  constructor(name) {
    name = name
  }
}

const u = new User("John")
console.log(u.name)
~~~

### Output

~~~javascript
undefined
~~~

### Why it is a mistake

Value is not assigned to the instance. Missing `this`.


### ✅ Fix

~~~javascript
class User {
  constructor(name) {
    this.name = name
  }
}

const u = new User("John")
console.log(u.name)
~~~

### Output

~~~javascript
John
~~~

### Why the fix works

`this` assigns value to the object instance.

---

### ❌ Wrong Code

~~~javascript
class Test {
  greet() {
    console.log("Hello")
  }
}

const t = new Test()
const fn = t.greet
fn()
~~~

### Output

~~~javascript
undefined or error
~~~

### Why it is a mistake

`this` is lost when method is detached from object.

---

### ✅ Fix

~~~javascript
const fn = t.greet.bind(t)
fn()
~~~

### Output

	~~~javascript
Hello
~~~

### Why the fix works

`bind` ensures correct `this` context.

---

### ❌ Wrong Code

~~~javascript
class Car {
  start() {
    console.log(this.brand)
  }
}

const c = new Car()
c.start()
~~~

### Output

~~~javascript
undefined
~~~

### Why it is a mistake

Property is not initialized in constructor.

---

### ✅ Fix

~~~javascript
class Car {
  constructor(brand) {
    this.brand = brand
  }

  start() {
    console.log(this.brand)
  }
}

const c = new Car("BMW")
c.start()
~~~

### Output

~~~javascript
BMW
~~~

### Why the fix works

Property is properly initialized.

---

