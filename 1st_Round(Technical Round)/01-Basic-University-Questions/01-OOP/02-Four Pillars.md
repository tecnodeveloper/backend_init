# Four Pillars of OOP

---

## Definition

Object-Oriented Programming (OOP) is a programming paradigm based on the concept of **objects** which bundle **data (variables)** and **behavior (functions)** together.

The **four pillars of OOP** are EIPA:

1. **Encapsulation**
2. **Inheritance**
3. **Polymorphism**
4. **Abstraction**

---

# Encapsulation

Encapsulation is the concept of wrapping data members (variables) and member functions (function) together inside a class and restricting direct access to the data.

---
## Mental Model

Think of a **capsule**:
- Inside: medicine (data)
- Outside: shell (methods controlling access)
You **don’t touch the medicine directly**, you interact through the capsule.

---
## Example Encapsulation 

```cpp

class Employee{
    private:
        int salary;
    public:
        Employee(int IntialSalary){
            salary = IntialSalary;
        }
        void getSalary(){
            cout<<"Your salary is "<<salary<<endl;
        }
};
int main(){

    Employee Salman(2000);
    Salman.getSalary();
//    Salman.salary; you cann't change directly salary this is encapsulation
}
```

---

## Why It Exists

- Protects data from accidental modification
- Enforces controlled access
- Improves maintainability

---

## Interview Tip

Encapsulation = **data hiding + controlled access**

---

# Inheritance

Inheritance is a mechanism in which a Child Class acquires the properties of Parent class using extend keyword

---

## Mental Model

Parent → Child relationship:

- Child inherits traits from parent
- Can add or modify behavior

---

## Example Inheritance

```cpp

class Animal {
public:
    void eat() { cout << "Eating..."; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Woof!"; }
};

int main() {
    Dog myDog;
    myDog.eat();
    myDog.bark();
    return 0;
}
```

---

## Why It Exists

- Code reuse
- Logical hierarchy
- Reduces duplication

---

## Step-by-Step Breakdown

1. Define parent class
2. Use `extends` keyword
3. Override methods if needed

---

## Interview Tip

Inheritance = **“is-a” relationship**
Example: Dog **is an** Animal

---

# Polymorphism

Polymorphism means **one interface, multiple implementations**.

- it may be compile time polymorphism like Function overloading and Runtime polymorphism like function overriding.

---

## Mental Model

Same action, different behavior:

- Button click → different outcomes
- Same method → different outputs

---

## Example Polymorphism (P)

```cpp

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

## Why It Exists

- Flexibility
- Extensibility
- Cleaner code

---

## Step-by-Step Breakdown

1. Define common method in base class
2. Override in subclasses
3. Call same method dynamically

---

## Common Mistakes

- Using conditionals instead of polymorphism
- Not overriding methods properly

---

## Key Points

- Same method name
- Different behavior
- Works via method overriding

---

## Interview Tip

Polymorphism = **same interface, different behavior**

---

# Abstraction

Abstraction means **hiding complex implementation details** and showing only essential features.

---

## Mental Model

Driving a car:

- You use **steering & pedals**
- You don’t see engine internals

---

## Example

```cpp
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

## Why It Exists

- Reduces complexity
- Improves usability
- Focuses on _what_ instead of \_how

---

## Step-by-Step Breakdown

1. Create base class (`Shape`)
2. Define method placeholder (`area`)
3. Force subclasses to implement it
4. Hide actual logic from user

---

## Interview Tip

Abstraction = **Hide complexity, expose essentials**

---

# Comparison Table

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

# Interview Summary

- OOP is about structuring code using objects
- Four pillars work **together**, not separately
- Always explain with **real-world analogy**
- Mention:
  - Encapsulation = data hiding
  - Inheritance = reuse
  - Polymorphism = flexibility
  - Abstraction = hiding complexity
