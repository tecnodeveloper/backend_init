# Classes and Objects in C++

---

##  Definition

- A **class** is a blueprint or template for creating objects.
- An **object** is an instance of a class — a real, usable entity built from that blueprint.

 Think of a class as a **design** and an object as the **actual item** created from that design.

---

## 3. Mental Model

Imagine a **Car Factory**:

- **Class = Car Blueprint**
    - Defines properties: color, speed
    - Defines behaviors: accelerate(), brake()

- **Object = Actual Car**
    - A red car
    - A blue car

Each car is independent but follows the same blueprint.

---

### Example: Simple Class and Object

```javascript
#include <iostream>
using namespace std;

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
## 7. Real-World Example

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

## 8. Internal Behavior

### What happens in memory?

- Class = **no memory allocated**
- Object = **memory allocated**

Each object has **its own copy** of data members.


---

## 11. Key Points

- Class = blueprint
- Object = instance
- Objects hold real data
- Methods define behavior
- Access specifiers control visibility
- Each object has separate memory

---

## 12. Comparison Table

| Concept    | Class            | Object        |
| ---------- | ---------------- | ------------- |
| Definition | Blueprint        | Instance      |
| Memory     | No               | Yes           |
| Purpose    | Define structure | Use structure |
| Example    | `class Car`      | `Car c1;`     |

---


---

## 15. Interview Tips / Summary

### Must-Know Answers:

- **What is a class?**  
    → A user-defined data type that groups variables and functions.
    
- **What is an object?**  
    → An instance of a class.
    
- **Difference between class and object?**  
    → Class defines structure, object uses it.
    
- **Why use classes?**  
    → For modularity, reusability, and abstraction.

