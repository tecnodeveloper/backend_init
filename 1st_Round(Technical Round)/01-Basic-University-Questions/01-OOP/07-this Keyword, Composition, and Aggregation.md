# `this` Keyword, Composition, and Aggregation 

#  Introduction

In Object-Oriented Programming (OOP), objects need a way to:

- Access their own properties and methods
- Build relationships with other objects
- Reuse functionality without unnecessary inheritance

JavaScript provides the **`this` keyword** for object context and supports object relationships through **Composition** and **Aggregation**.

These three concepts are fundamental for writing scalable frontend and backend applications.

---

# The `this` Keyword in JavaScript

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

#  Basic Syntax

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

#  How `this` Works Internally

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

# Example: Accessing Object Properties

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

# Part 2: Composition and Aggregation in C++

---

# 16. Composition Lifecycle

One of the most important characteristics of Composition is:

> The contained object's lifetime depends on the owner object's lifetime.

If the parent object is destroyed, its composed objects are also destroyed.

---

## Example

```cpp
#include <iostream>
using namespace std;

class Engine
{
public:
    Engine()
    {
        cout << "Engine Created" << endl;
    }

    ~Engine()
    {
        cout << "Engine Destroyed" << endl;
    }
};

class Car
{
private:
    Engine engine;

public:
    Car()
    {
        cout << "Car Created" << endl;
    }

    ~Car()
    {
        cout << "Car Destroyed" << endl;
    }
};

int main()
{
    Car car;
}
```

### Output

```text
Engine Created
Car Created
Car Destroyed
Engine Destroyed
```

---

## Internal Behavior

When:

```cpp
Car car;
```

is created:

```text
Car
 └── Engine
```

The Engine object is automatically created.

When Car is destroyed:

```text
Car Destroyed
Engine Destroyed
```

The Engine cannot outlive the Car.

---

# 17. Real-World Composition Examples

---

## Computer and CPU

```cpp
class CPU
{
public:
    void process()
    {
        cout << "Processing..." << endl;
    }
};

class Computer
{
private:
    CPU cpu;

public:
    void run()
    {
        cpu.process();
    }
};
```

---

## House and Rooms

```cpp
class Room
{
};

class House
{
private:
    Room room1;
    Room room2;
    Room room3;
};
```

Rooms are part of the house.

---

## Order and Order Items

```cpp
class OrderItem
{
};

class Order
{
private:
    vector<OrderItem> items;
};
```

If the order disappears, its items disappear as well.

---

# 18. Aggregation

## Definition

Aggregation is an OOP relationship where one object uses another object, but does not own it.

In simple terms:

> Aggregation = "has-a" relationship with weak ownership.

The child object can exist independently of the parent.

---

# Why Aggregation Exists

Sometimes objects need to collaborate without ownership.

Examples:

- University has Students
    
- Team has Players
    
- Department has Employees
    

If the parent is destroyed, the child objects still exist.

---

# Mental Model

Think of:

```text
University
    ├── Student A
    ├── Student B
    └── Student C
```

If the University closes:

```text
Students still exist.
```

Unlike Composition, lifetime is independent.

---

# 19. Aggregation Example

## Student and University

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Student
{
public:
    string name;

    Student(string n)
    {
        name = n;
    }
};

class University
{
private:
    vector<Student*> students;

public:
    void addStudent(Student* student)
    {
        students.push_back(student);
    }

    void showStudents()
    {
        for (auto student : students)
        {
            cout << student->name << endl;
        }
    }
};

int main()
{
    Student s1("Ali");
    Student s2("Ahmed");

    University university;

    university.addStudent(&s1);
    university.addStudent(&s2);

    university.showStudents();
}
```

### Output

```text
Ali
Ahmed
```

---

# 20. Aggregation Lifecycle

Observe:

```cpp
Student s1("Ali");
Student s2("Ahmed");
```

Students are created independently.

Then:

```cpp
university.addStudent(&s1);
```

The University simply stores references/pointers.

It does NOT own them.

---

## Visualization

```text
Student Ali
Student Ahmed

        ▲
        │
        │
University
```

The University points to Students.

Students exist independently.

---

# 21. Composition vs Aggregation

|Feature|Composition|Aggregation|
|---|---|---|
|Ownership|Strong|Weak|
|Lifetime Dependency|Yes|No|
|Child Exists Independently|No|Yes|
|Relationship Type|Part Of|Uses|
|Memory Management|Owner Controls|External Control|
|Coupling|Stronger|Looser|

---

# 22. Composition Example vs Aggregation Example

## Composition

```cpp
class Engine
{
};

class Car
{
private:
    Engine engine;
};
```

Engine belongs to Car.

---

## Aggregation

```cpp
class Engine
{
};

class Car
{
private:
    Engine* engine;

public:
    Car(Engine* e)
    {
        engine = e;
    }
};
```

Engine exists separately and is provided to Car.

---

# 23. Real-World Backend Examples

---

## Composition: E-Commerce Order System

```cpp
class OrderItem
{
};

class Order
{
private:
    vector<OrderItem> items;
};
```

Order owns its items.

If Order is deleted:

```text
Order Items are deleted too.
```

---

## Aggregation: Company and Employees

```cpp
class Employee
{
};

class Company
{
private:
    vector<Employee*> employees;
};
```

Employees can exist without a company.

They may move to another company.

---

# 24. Real-World Game Development Examples

---

## Composition

```cpp
class Weapon
{
};

class Player
{
private:
    Weapon weapon;
};
```

Weapon is tightly coupled to Player.

---

## Aggregation

```cpp
class Weapon
{
};

class Player
{
private:
    Weapon* weapon;
};
```

Weapon can be shared or transferred.

---

# 25. Common Mistakes

## Mistake 1: Confusing Composition with Aggregation

### Wrong Understanding

```cpp
class Car
{
    Engine* engine;
};
```

Many developers assume this is Composition.

Not necessarily.

A pointer usually indicates Aggregation because the object may exist independently.

---

## Mistake 2: Ownership Confusion

### Problem

```cpp
class University
{
    Student* student;
};
```

Who deletes Student?

The ownership is unclear.

---

### Better

Use smart pointers when ownership matters.

```cpp
std::unique_ptr<Student>
```

for Composition.

```cpp
Student*
```

or

```cpp
std::shared_ptr<Student>
```

for Aggregation.

---

## Mistake 3: Overusing Inheritance

### Wrong Design

```cpp
class Car : public Engine
{
};
```

A Car is NOT an Engine.

---

### Correct Design

```cpp
class Car
{
private:
    Engine engine;
};
```

A Car HAS an Engine.

---

# 26. Internal Behavior

## Composition

```text
Car
 └── Engine
```

Memory Layout:

```text
Car Object
 ├── Engine Data
 └── Car Data
```

Engine is embedded inside Car.

---

## Aggregation

```text
Car
 └── Engine*
```

Memory Layout:

```text
Car Object
 ├── Pointer
 └── Car Data

Engine Object
 └── Separate Memory
```

Engine lives elsewhere.

---

# 27. Composition and Aggregation Together

Large systems often use both.

Example:

```cpp
class Address
{
};

class Employee
{
private:
    Address address; // Composition
};

class Company
{
private:
    vector<Employee*> employees; // Aggregation
};
```

Relationship:

```text
Company
    Aggregates Employees

Employee
    Composes Address
```

---

# Key Points

- Composition represents strong ownership.
    
- Aggregation represents weak ownership.
    
- Composition objects cannot exist independently.
    
- Aggregation objects can exist independently.
    
- Composition usually stores objects directly.
    
- Aggregation usually stores pointers or references.
    
- Composition creates tighter coupling.
    
- Aggregation provides greater flexibility.
    

---

# Interview Summary

### What is Composition?

A "has-a" relationship where one object owns another object and controls its lifetime.

Example:

```cpp
class Car
{
    Engine engine;
};
```

---

### What is Aggregation?

A "has-a" relationship where one object uses another object without owning it.

Example:

```cpp
class Car
{
    Engine* engine;
};
```

---

### Main Difference?

Composition:

```text
Child cannot exist without Parent.
```

Aggregation:

```text
Child can exist without Parent.
```

---

### Which Provides Strong Ownership?

```text
Composition
```

---

### Which Provides Weak Ownership?

```text
Aggregation
```

---

# Final Mental Model

```text
Composition
    = Owns Object
    = Part Of Relationship
    = Strong Ownership

Examples:
Car → Engine
House → Room
Computer → CPU
Order → OrderItem
```

```text
Aggregation
    = Uses Object
    = Independent Relationship
    = Weak Ownership

Examples:
University → Student
Company → Employee
Team → Player
Library → Book
```

```text
HAS-A Relationship
        │
        ▼
 ┌──────────────┐
 │ Composition  │
 │ Owns Object  │
 └──────────────┘

 ┌──────────────┐
 │ Aggregation  │
 │ Uses Object  │
 └──────────────┘
```

> Composition and Aggregation are two ways to model "has-a" relationships in C++. Composition implies ownership and lifetime dependency, while Aggregation represents association without ownership, allowing objects to exist independently.