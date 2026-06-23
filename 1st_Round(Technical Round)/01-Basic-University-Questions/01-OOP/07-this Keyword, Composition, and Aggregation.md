# `this` Pointer, Composition, and Aggregation in C++

# `this` keyword


The **`this` pointer** is a special pointer automatically available inside every non-static member function.

It points to the object that invoked the member function. `this` = "pointer to the current object"

---

## Mental Model

Think of `this` as:

> "Who am I right now?"

Whenever an object calls a member function, C++ automatically passes the address of that object through the `this` pointer.

---

# 2. Basic Syntax

```cpp

class Person
{
public:
    string name = "Ali";

    void greet()
    {
        cout << this->name << endl;
    }
};

int main()
{
    Person person;
    person.greet();
}
```

Here:

```cpp
this == &person
```

---

# How `this` Works Internally

When C++ executes:

```cpp
person.greet();
```

The compiler internally treats it similarly to:

```cpp
Person::greet(&person);
```

Meaning:

```cpp
this = &person;
```

Inside the function:

```cpp
this->name
```

becomes:

```cpp
person.name
```

---

# Resolving Naming Conflicts


```cpp
class User
{
public:
    string name;
//Constructor with same input as private variable so this is used
    User(string name)
    {
        name = name;
    }
};
```

---

## Correct Solution

```cpp
class User
{
public:
    string name;

    User(string name)
    {
        this->name = name;
    }
};
```

---

# 10. Common Mistakes with `this`

## Mistake 1: Using `this` in Static Functions

### Wrong

```cpp
class User
{
public:
    static void greet()
    {
        cout << this->name;
    }
};
```

### Why?

Static functions belong to the class, not an object.

No `this` pointer exists.

---

## Correct

```cpp
void greet()
{
    cout << this->name;
}
```

---

#  Composition

## Definition

Composition is an OOP relationship where one object is made up of one or more other objects.

The contained objects typically cannot exist independently within the context of the relationship. Composition = Strong "has-a" relationship

---
## Mental Model

Think of:

- Car has Engine    
- House has Rooms    
- Computer has CPU    

The parent object owns its components.

---

# Composition Example

## Engine and Car

```cpp
class Engine
{
public:
    void start()
    {
        cout << "Engine Started" << endl;
    }
};

class Car
{
private:
    Engine engine;

public:
    void startCar()
    {
        engine.start();
    }
};
```

Usage:

```cpp
Car car;
car.startCar();
```

Output:

```text
Engine Started
```

---

# Composition Lifecycle

A key characteristic of Composition:

> Child object's lifetime depends on the parent object's lifetime.

---

## Example

```cpp
class Engine
{
public:
    Engine()
    {
        cout << "Engine Created\n";
    }

    ~Engine()
    {
        cout << "Engine Destroyed\n";
    }
};

class Car
{
private:
    Engine engine;

public:
    Car()
    {
        cout << "Car Created\n";
    }

    ~Car()
    {
        cout << "Car Destroyed\n";
    }
};
```

Output:

```text
Engine Created
Car Created
Car Destroyed
Engine Destroyed
```

---

## Internal Behavior

```text
Car
 └── Engine
```

Engine is automatically created and destroyed with Car.

---

# Real-World Composition Examples

## E-Commerce Order

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

If Order is deleted, OrderItems are deleted too.

---

# Aggregation

## Definition

Aggregation is relationship where child object can exist independently. Aggregation = Weak "has-a" relationship The 

---

## Why Aggregation Exists

Some objects need collaboration without ownership.

Examples:

- University has Students
- Company has Employees    
- Team has Players    

Destroying the parent does not destroy the child.

---

## Mental Model

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

---

#  Aggregation Example

## University and Student

```cpp
#include <vector>

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
};
```


---

## Internal Behavior

```text
Student Ali
Student Ahmed

       ▲
       │
University
```

University references Students.

Students live independently.

---

#  Composition vs Aggregation

|Feature|Composition|Aggregation|
|---|---|---|
|Ownership|Strong|Weak|
|Lifetime Dependency|Yes|No|
|Child Exists Independently|No|Yes|
|Relationship|Part Of|Uses|
|Coupling|Strong|Loose|
|Memory Management|Owner Controls|External Control|

---

# Composition vs Aggregation Code

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

Engine exists independently.

---

# 20. Common Mistakes

## Mistake 1: Confusing Aggregation with Composition

### Wrong Assumption

```cpp
class Car
{
    Engine* engine;
};
```

Many assume this is Composition.

Usually it represents Aggregation because Engine may exist independently.

---

## Mistake 2: Ownership Confusion

```cpp
class University
{
    Student* student;
};
```

Question:

```text
Who deletes Student?
```

Ownership is unclear.

Prefer smart pointers when ownership matters.

---

## Mistake 3: Misusing Inheritance

### Wrong

```cpp
class Car : public Engine
{
};
```

A Car is not an Engine.

---

### Correct

```cpp
class Car
{
private:
    Engine engine;
};
```

A Car has an Engine.

---

# Real-World Usage

## Backend Systems

### Composition

```cpp
Order → OrderItem
Invoice → InvoiceLine
```

---

### Aggregation

```cpp
Company → Employee
School → Student
```

---
# Key Points

- `this` points to the current object.
    
- `this` is automatically available in non-static member functions.
    
- Composition represents strong ownership.
    
- Aggregation represents weak ownership.
    
- Composition objects cannot exist independently.
    
- Aggregation objects can exist independently.
    
- Composition usually stores objects directly.
    
- Aggregation usually stores pointers or references.
    
- Use Composition when ownership exists.
    
- Use Aggregation when objects only collaborate.

---

# Interview Summary

### What is `this`?

A pointer that refers to the current object.

Example:

```cpp
this->name
```

---

### What is Composition?

A strong "has-a" relationship where one object owns another.

Example:

```cpp
class Car
{
    Engine engine;
};
```

---

### What is Aggregation?

A weak "has-a" relationship where one object uses another without ownership.

Example:

```cpp
class Car
{
    Engine* engine;
};
```

---

### Main Difference Between Composition and Aggregation

Composition:

```text
Child cannot exist without Parent.
```

Aggregation:

```text
Child can exist without Parent.
```

---

# Final Mental Model

```text
this
    = Current Object

Composition
    = Owns Object
    = Strong HAS-A

Aggregation
    = Uses Object
    = Weak HAS-A
```

```text
Car
 └── Engine
      (Composition)

University
 └── Student
      (Aggregation)
```

> The `this` pointer helps an object refer to itself, while Composition and Aggregation help objects build relationships with other objects. Together, these concepts form a foundation for designing clean, modular, and maintainable C++ applications.