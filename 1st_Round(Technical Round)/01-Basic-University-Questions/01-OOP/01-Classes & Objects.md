# Classes and Objects in C++

---

##  Definition

- A **class** is a [blueprint](https://www.urdupoint.com/dictionary/english-to-urdu/blueprint-meaning-in-urdu/11199.html) or template - Think of a class as a **design**
- An **object** is an [instance](https://www.urdu2eng.com/instance-urdu-meanings.html)) of a class - Object as the **actual item** created from that design

---

##  Mental Model

Imagine a **Car Factory**:

- **Class = Car Blueprint**
    - Defines properties: color, speed called Members
    - Defines behaviors: accelerate(), brake() called Methods

- **Object = Actual Car**
    - A red car
    - A blue car

Each car is independent but follows the same blueprint.

---

### Example: Simple Class and Object

```c++
class Student {
public:
    string name;
    int age;

    void display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

int main() {
    Student s1;  // Object creation

    s1.name = "Ali";
    s1.age = 20;

    s1.display();

    return 0;
}
```

### Step-by-Step Breakdown

1. `class Student` defines structure
2. `s1` is an object
3. `s1.name` assigns data
4. `s1.display()` calls function

---
## Real-World Example

### Example: Bank Account System

```javascript
#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double b) {
        balance = b;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds" << endl;
    }

    void display() {
        cout << "Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc(1000);

    acc.deposit(500);
    acc.withdraw(200);
    acc.display();

    return 0;
}
```

### Breakdown

1. `balance` is private → protected from direct access
2. Controlled via methods → `deposit`, `withdraw`
3. Demonstrates **encapsulation**

---

## Internal Behavior

### What happens in memory?

- Class = **no memory allocated**
- Object = **memory allocated**

Each object has **its own copy** of data members.


---

## Key Points

- Class = blueprint
- Object = instance
- Objects hold real data
- Methods define behavior
- Access specifiers control visibility
- Each object has separate memory

---

## Comparison Table

| Concept    | Class            | Object        |
| ---------- | ---------------- | ------------- |
| Definition | Blueprint        | Instance      |
| Memory     | No               | Yes           |
| Purpose    | Define structure | Use structure |
| Example    | `class Car`      | `Car c1;`     |

---


---

## Interview Tips / Summary

### Must-Know Answers:

- **What is a class?**  
    → A user-defined data type that groups variables and functions.
    
- **What is an object?**  
    → An instance of a class.
    
- **Difference between class and object?**  
    → Class defines structure, object uses it.
    
- **Why use classes?**  
    → For modularity, reusability, and abstraction.

