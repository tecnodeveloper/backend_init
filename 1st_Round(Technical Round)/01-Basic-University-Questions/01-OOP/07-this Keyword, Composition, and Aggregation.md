# `this` Keyword, Composition, and Aggregation 

---

# 1. Introduction

In Object-Oriented Programming (OOP), objects need a way to:

- Access their own properties and methods
    
- Build relationships with other objects
    
- Reuse functionality without unnecessary inheritance
    

JavaScript provides the **`this` keyword** for object context and supports object relationships through **Composition** and **Aggregation**.

These three concepts are fundamental for writing scalable frontend and backend applications.

---

# 2. The `this` Keyword in JavaScript

## Definition

The **`this` keyword** refers to the object that is currently executing a function.

In simple terms:

> `this` = "the object that is currently calling the function"

Unlike C++, JavaScript's `this` is determined at **runtime**, not at compile time.

---

## Why `this` Exists

Without `this`:

- Methods could not easily access their object's data
    
- Object behavior would be difficult to organize
    
- Reusable methods would be harder to write
    

With `this`:

- Methods can access object properties
    
- Objects can maintain their own state
    
- Reusable object-oriented designs become possible
    

---

## Mental Model

Think of `this` as:

> "Who called me?"

Whenever a function executes, JavaScript asks:

> "Which object invoked this function?"

That object becomes `this`.

---

# 3. Basic Syntax

```cpp
class Person {
public:
    std::string name = "Ali";

    void greet() {
        std::cout << this->name << std::endl;
    }
};

Person person;
person.greet();
```

Output:

```cpp
Ali
```

Here:

```cpp
this == &person
```

---

# 4. How `this` Works Internally

When C++ executes:

```cpp
person.greet();
```

It internally behaves like:

```cpp
Person::greet(&person);
```

Meaning:

```cpp
this = &person;
```

---

# 5. Example: Accessing Object Properties

```cpp
class Student {
public:
    std::string name = "Ahmed";

    void display() {
        std::cout << this->name << std::endl;
    }
};

Student student;
student.display();
```

Output:

```cpp
Ahmed
```

---

# 6. Naming Conflict Example

Similar to C++ constructor examples.

## Problem

```cpp
class User {
public:
    std::string name;

    User(std::string name) {
        name = name;
    }
};
```

This does nothing.

---

## Correct Solution

```cpp
class User {
public:
    std::string name;

    User(std::string name) {
        this->name = name;
    }
};
```

### Breakdown

```cpp
this->name
```

Refers to object's property.

```cpp
name
```

Refers to constructor parameter.

---

# 7. `this` Inside Classes

```cpp
class Car {
private:
    std::string brand;

public:
    Car(std::string brand) {
        this->brand = brand;
    }

    void showBrand() {
        std::cout << this->brand << std::endl;
    }
};

Car car("Toyota");

car.showBrand();
```

Output:

```cpp
Toyota
```

---

# 8. Losing `this` Context

A common issue when using function pointers or callbacks.

## Incorrect Example

```cpp
class User {
public:
    std::string name = "Ali";

    void showName() {
        std::cout << name << std::endl;
    }
};

User user;

auto fn = &User::showName;

// fn(); // Error
```

Output:

```cpp
Compilation Error
```

---

## Why?

Because:

```cpp
auto fn = &User::showName;
```

stores a member function pointer.

A member function requires an object instance.

Therefore:

```cpp
this is missing
```

---

## Fix Using `std::bind`

```cpp
auto fixedFn = std::bind(&User::showName, &user);

fixedFn();
```

Output:

```cpp
Ali
```

---

# 9. `this` Inside Lambdas

Lambdas can capture `this`.

They inherit access to the current object.

---

## Example

```cpp
class Person {
public:
    std::string name = "Ali";

    void show() {
        auto lambda = [this]() {
            std::cout << this->name << std::endl;
        };

        lambda();
    }
};

Person person;
person.show();
```

Output:

```cpp
Ali
```

---

# 10. Regular Function vs Lambda

|Feature|Regular Function|Lambda|
|---|---|---|
|Own `this`|No|Can Capture|
|Dynamic Binding|No|No|
|Suitable for Object Methods|Yes|Usually|
|Inherits Parent Context|No|If Captured|

---

# 11. Explicitly Setting `this`

C++ commonly provides:

- Member function pointers
    
- Lambdas
    
- `std::bind`
    

---

## Using Member Function Pointer

```cpp
class User {
public:
    std::string name = "Ali";

    void greet() {
        std::cout << name << std::endl;
    }
};

User user;

auto fn = std::bind(&User::greet, &user);

fn();
```

Output:

```cpp
Ali
```

---

## Using Lambda

```cpp
class Calculator {
public:
    std::string name = "Calculator";

    void sum(int a, int b) {
        std::cout << name << " " << a + b << std::endl;
    }
};

Calculator obj;

auto fn = [&obj]() {
    obj.sum(5, 3);
};

fn();
```

Output:

```cpp
Calculator 8
```

---

## Using `std::bind`

```cpp
auto boundFn = std::bind(&User::greet, &user);

boundFn();
```

---

# 12. Method Chaining with `this`

Returning the current object enables chaining.

```cpp
class Counter {
public:
    int count = 0;

    Counter& increment() {
        count++;
        return *this;
    }

    Counter& decrement() {
        count--;
        return *this;
    }
};

Counter counter;

counter
    .increment()
    .increment()
    .decrement();

std::cout << counter.count << std::endl;
```

Output:

```cpp
1
```

---

# 13. Common Mistakes with `this`

## Mistake 1

```cpp
class User {
public:
    std::string name = "Ali";

    static void greet() {
        std::cout << this->name << std::endl;
    }
};
```

### Problem

Static functions do not have a `this` pointer.

---

## Fix

```cpp
class User {
public:
    std::string name = "Ali";

    void greet() {
        std::cout << this->name << std::endl;
    }
};
```

---

## Mistake 2

```cpp
auto fn = &User::greet;

fn();
```

Context missing.

---

## Fix

```cpp
auto fn = std::bind(&User::greet, &user);

fn();
```

---

# 14. Composition in JavaScript

---

## Definition

**Composition** is an OOP relationship where one object is made up of one or more other objects, and those contained objects typically cannot exist independently in the context of that relationship.

In simple terms:

> Composition = "has-a" relationship with strong ownership.

---

## Why Composition Exists

Inheritance can create tight coupling.

Composition allows:

- Better code reuse
    
- Flexible object design
    
- Easier maintenance
    
- Smaller focused objects
    

---

## Mental Model

Think of a:

- House has Rooms
    
- Car has Engine
    
- Computer has CPU
    

The parent object owns its parts.

---

# 15. Composition Example

## Engine and Car

```cpp
class Engine {
public:
    void start() {
        std::cout << "Engine started" << std::endl;
    }
};

class Car {
private:
    Engine engine;

public:
    void startCar() {
        engine.start();
    }
};

Car car;

car.startCar();
```

Output:

```cpp
Engine started
```

Send **"part 2"** for the next section.