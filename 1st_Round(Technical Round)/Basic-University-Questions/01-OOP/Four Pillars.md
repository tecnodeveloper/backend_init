# Four Pillars of OOP

---

##  Definition

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of **objects**, which bundle **data (variables)** and **behavior (functions)** together.

The **four pillars of OOP** are:

1. **Encapsulation**
2.  **Inheritance**
3. **Polymorphism**
4. **Abstraction**

These pillars help structure code in a way that is **modular, reusable, and easier to maintain**.

---


# 1. Encapsulation

---

##  Definition

Encapsulation is the concept of wrapping data members (variables) and member functions (function) together inside a class and restricting direct access to the data.

---

##  Mental Model

Think of a **capsule**:
- Inside: medicine (data)
- Outside: shell (methods controlling access)

You **don’t touch the medicine directly**, you interact through the capsule.

---
## 1. Encapsulation (E)

```cpp
#include <iostream>

class BankAccount {
private:
    double balance = 500.00; // Hidden data

public:
    void deposit(double amount) { 
        if (amount > 0) balance += amount; 
    }
    
    double getBalance() { return balance; }
};

int main() {
    BankAccount account;
    account.deposit(150.00);
    std::cout << "Balance: \$" << account.getBalance(); 
    return 0;
}
```

---

##  Why It Exists

- Protects data from accidental modification
- Enforces controlled access
- Improves maintainability

---

##  Interview Tip

Encapsulation = **data hiding + controlled access**

---
# 2. Inheritance

---

##  Definition

Inheritance is a mechanism in which a derived class(Child Class) acquires the properties of base class (Parent class)

---

##  Mental Model

Parent → Child relationship:
- Child inherits traits from parent
- Can add or modify behavior

---
## 2. Inheritance (I)

```cpp
#include <iostream>

class Animal {
public:
    void eat() { std::cout << "Eating...\n"; }
};

class Dog : public Animal {
public:
    void bark() { std::cout << "Woof!\n"; }
};

int main() {
    Dog myDog;
    myDog.eat();  
    myDog.bark(); 
    return 0;
}
```

---



##  Why It Exists

- Code reuse
- Logical hierarchy
- Reduces duplication

---


##  Step-by-Step Breakdown

1. Define parent class
2. Use `extends` keyword
3. Override methods if needed

---

##  Interview Tip

Inheritance = **“is-a” relationship**
Example: Dog **is an** Animal

---

# 3. Polymorphism

---

##  Definition

Polymorphism means **one interface, multiple implementations**. 

- it may be compile time polymorphism like Function overloading and Runtime polymorphism like function overriding.

---

##  Mental Model

Same action, different behavior:
- Button click → different outcomes
- Same method → different outputs


---

## 3. Polymorphism (P)

```cpp
#include <iostream>

class Shape {
public:
    virtual void draw() { std::cout << "Drawing a shape.\n"; } 
};

class Circle : public Shape {
public:
    void draw() override { std::cout << "Drawing a circle.\n"; }
};

int main() {
    Shape* myShape = new Circle(); 
    myShape->draw(); 
    delete myShape;
    return 0;
}
```


---

##  Why It Exists

- Flexibility
- Extensibility
- Cleaner code

---

##  Step-by-Step Breakdown

1. Define common method in base class
2. Override in subclasses
3. Call same method dynamically

---

##  Common Mistakes

- Using conditionals instead of polymorphism
- Not overriding methods properly

---

##  Key Points

- Same method name
- Different behavior
- Works via method overriding

---

##  Interview Tip

Polymorphism = **same interface, different behavior**

---

# 4. Abstraction

---

##  Definition

Abstraction means **hiding complex implementation details** and showing only essential features.

---

## Mental Model

Driving a car:
- You use **steering & pedals**
- You don’t see engine internals

---
## 4. Abstraction (A)

```cpp
#include <iostream>

class CoffeeMachine {
public:
    virtual void makeCoffee() = 0; 
};

class EspressoMachine : public CoffeeMachine {
public:
    void makeCoffee() override {
        std::cout << "Pouring Espresso Shot!\n"; 
    }
};

int main() {
    EspressoMachine machine;
    machine.makeCoffee(); 
    return 0;
}
```

---

##  Why It Exists

- Reduces complexity
- Improves usability
- Focuses on _what_ instead of _how

---


##  Step-by-Step Breakdown

1. Create base class (`Shape`)
2. Define method placeholder (`area`)
3. Force subclasses to implement it
4. Hide actual logic from user
---
##  Interview Tip

Abstraction = **Hide complexity, expose essentials**

---


#  Comparison Table

| Pillar        | Focus       | Key Benefit             | Example Concept   |
| ------------- | ----------- | ----------------------- | ----------------- |
| Encapsulation | Data hiding | Security                | Private variables |
| Inheritance   | Reusability | reuse                   | `extends`         |
| Polymorphism  | Flexibility | Dynamic behavior        | Method overriding |
| Abstraction   | Simplicity  | Reduced complexity Code | Abstract classes  |

---

# Final Mental Model

- **Encapsulation** → Protect data
- **Inheritance** → Reuse code    
- **Polymorphism** → Flexible behavior
- **Abstraction** → Hide complexity


 

---

#  Interview Summary

- OOP is about structuring code using objects
- Four pillars work **together**, not separately
- Always explain with **real-world analogy**
    
- Mention:
    - Encapsulation = data hiding
    -  Inheritance = reuse
    - Polymorphism = flexibility
    -  Abstraction = hiding complexity  



