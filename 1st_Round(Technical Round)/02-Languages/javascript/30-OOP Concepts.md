# OOP Concepts (JavaScript)

## Definition

Object-Oriented Programming (OOP) is a programming paradigm that organizes code using objects, allowing better structure, reusability, and maintainability.

It is based on combining data (properties) and behavior (methods) into a single unit called an object.

---

## Syntax

There is no single syntax for OOP concepts, but they are commonly implemented using classes:

~~~javascript
class ClassName {
  constructor() {}
}
~~~

→ For detailed explanation: [[Classes]]

---

## Basic Example

~~~javascript
class Person {
  constructor(name) {
    this.name = name
  }

  greet() {
    console.log("Hello " + this.name)
  }
}

const user = new Person("John")
user.greet()
~~~

→ For detailed explanation: [[Classes]]

---

## Additional Examples

### Encapsulation

#### Definition

Encapsulation is the concept of restricting direct access to object data and allowing it to be modified only through controlled methods.

In JavaScript, true encapsulation is achieved using private fields (`#`).

---

#### Syntax

~~~javascript
class ClassName {
  #privateProperty

  constructor(value) {
    this.#privateProperty = value
  }

  publicMethod() {}
}
~~~

#### Example

~~~javascript
class BankAccount {
  #balance

  constructor(balance) {
    this.#balance = balance
  }

  deposit(amount) {
    this.#balance += amount
  }

  getBalance() {
    return this.#balance
  }
}

const acc = new BankAccount(100)
acc.deposit(50)
console.log(acc.getBalance())
~~~

#### Output

~~~javascript
150
~~~

#### Use Case

- Protect sensitive data  
- Control data modification  
- Prevent direct property misuse  

---

### Inheritance

#### Definition

Inheritance allows a class to acquire properties and methods from another class.

#### Syntax

~~~javascript
class Parent {}

class Child extends Parent {}
~~~

#### Example

~~~javascript
class Animal {
  speak() {
    console.log("Animal makes sound")
  }
}

class Dog extends Animal {
  speak() {
    super.speak()
    console.log("Dog barks")
  }
}

const d = new Dog()
d.speak()
~~~

#### Output

~~~javascript
Animal makes sound
Dog barks
~~~

#### Note

This example shows extending parent behavior using `super()`.

→ For detailed explanation: [[Inheritance]]

#### Use Case

- Code reuse  
- Hierarchical structure  
- Extend functionality  

---

### Polymorphism

#### Definition

Polymorphism allows the same method to behave differently depending on the object.

JavaScript mainly supports runtime polymorphism through method overriding.

#### Syntax

~~~javascript
class Parent {
  method() {}
}

class Child extends Parent {
  method() {}
}
~~~

#### Example

~~~javascript
class Shape {
  draw() {
    console.log("Drawing shape")
  }
}

class Circle extends Shape {
  draw() {
    console.log("Drawing circle")
  }
}

const shape = new Shape()
const circle = new Circle()

shape.draw()
circle.draw()
~~~

#### Output

~~~javascript
Drawing shape
Drawing circle
~~~

#### Use Case

- Same interface, different behavior  
- Flexible code design  
- Avoid condition-based logic  

---

### Abstraction

#### Definition

Abstraction hides internal implementation details and exposes only essential functionality.

It focuses on what an object does rather than how it does it. In JavaScript, abstraction is commonly achieved using private methods, base classes, and controlled APIs.

#### Syntax

~~~javascript
class ClassName {
  publicMethod() {
    this.#privateMethod()
  }

  #privateMethod() {}
}
~~~

#### Example

~~~javascript
class Car {
  start() {
    this.#ignite()
    console.log("Car started")
  }

  #ignite() {
    console.log("Engine ignited")
  }
}

const car = new Car()
car.start()
~~~

#### Output

~~~javascript
Engine ignited
Car started
~~~

#### Use Case

- Hide complex logic  
- Improve readability  
- Expose only necessary functionality  

---

### Composition (Association)

#### Definition

Composition is a design principle where one class contains an instance of another class to reuse functionality.

It is often preferred over inheritance for flexibility.

#### Example

~~~javascript
class Engine {
  start() {
    console.log("Engine started")
  }
}

class Car {
  constructor() {
    this.engine = new Engine()
  }

  startCar() {
    this.engine.start()
    console.log("Car started")
  }
}

const car = new Car()
car.startCar()
~~~

#### Output

~~~javascript
Engine started
Car started
~~~

#### Use Case

- Build complex objects from smaller parts  
- Prefer over inheritance when relationship is "has-a"  
- Improve flexibility and reusability  

---

## When to use

- When building scalable applications  
- When multiple objects share similar structure  
- When code reusability is required  
- When managing complex systems  

---

## When NOT to use

- Small scripts or simple logic  
- When OOP adds unnecessary complexity  
- When functional approach is simpler  

---

## Behavior

- Combines data and methods into objects  
- Promotes modular and reusable code  
- Supports inheritance and hierarchy  
- Allows method overriding (polymorphism)  
- JavaScript OOP is prototype-based (classes are syntactic sugar over prototypes)  

---

## Hoisting (only if applicable)

- Classes are hoisted but not initialized  
- They exist in the Temporal Dead Zone (TDZ)  
- Cannot be accessed before declaration  

~~~javascript
const obj = new Person() // ❌ Error

class Person {}
~~~

---

## Edge Cases

### ❌ Accessing Private Field

~~~javascript
class Test {
  #value = 10
}

const obj = new Test()
console.log(obj.#value)
~~~

### Output

~~~javascript
SyntaxError
~~~

### Why it is an edge case

Private fields cannot be accessed outside the class.

### ✅ Fix

~~~javascript
class Test {
  #value = 10

  getValue() {
    return this.#value
  }
}

const obj = new Test()
console.log(obj.getValue())
~~~

### Output

~~~javascript
10
~~~

### Why the fix works

Private fields are accessed only through class methods.

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

`this` assigns the value to the object instance.

---

### ❌ Wrong Code

~~~javascript
class Animal {
  constructor(name) {
    this.name = name
  }
}

class Dog extends Animal {
  constructor(name) {
    this.name = name
  }
}

const d = new Dog("Tom")
~~~

### Output

~~~javascript
ReferenceError: Must call super constructor before using 'this'
~~~

### Why it is a mistake

`super()` is not called before using `this`.

### ✅ Fix

~~~javascript
class Animal {
  constructor(name) {
    this.name = name
  }
}

class Dog extends Animal {
  constructor(name) {
    super(name)
  }
}

const d = new Dog("Tom")
console.log(d.name)
~~~

### Output

~~~javascript
Tom
~~~

### Why the fix works

`super()` initializes the parent class properly.

→ For detailed explanation: [[super]]

---

### ❌ Wrong Code

~~~javascript
class Test {
  static greet() {
    console.log("Hello")
  }
}

const obj = new Test()
obj.greet()
~~~

### Output

~~~javascript
TypeError: obj.greet is not a function
~~~

### Why it is a mistake

Static methods are not available on instances.

### ✅ Fix

~~~javascript
class Test {
  static greet() {
    console.log("Hello")
  }
}

Test.greet()
~~~

### Output

~~~javascript
Hello
~~~

### Why the fix works

Static methods belong to the class, not objects.

→ For detailed explanation: [[Static Methods]]

---