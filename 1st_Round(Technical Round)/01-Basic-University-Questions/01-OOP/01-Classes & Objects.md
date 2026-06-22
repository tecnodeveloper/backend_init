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
class student{
    public:
        int rollNo;
        string Name;
        string ClassName;
    void studying(){
        cout<<"Student is studying";
    }
};
int main()
{
    student zain;
    student salman;
    zain.rollNo = 230201330;
    salman.rollNo = 12;
    zain.studying();
    return 0;
}
```

### Step-by-Step Breakdown

1. `class Student` defines structure
2. `zain` is an object
3. `zain.name` assigns data
4. `zain.display()` calls function

---
## Real-World Example

### Example: Bank Account System

```javascript
class Bank{
    private:
        double balance;
    public:
    Bank(int IntialBalance){
        balance = IntialBalance;
    }

    void deposit(){
        int depositMoney = 0;
        cout<<"Enter the money for deposit \n";
        cin>>depositMoney;
        if(depositMoney > 0){
            balance = balance + depositMoney;
            cout<<depositMoney<<" money is succussfully deposited. Your current balance is "<<balance<<endl;
        }else{
            cout<<"Please enter the correct number to deposit "<<" is not correct number"<<endl;
        }
    }

    void withdraw(){
        int withdrawMoney = 0;
        cout<<"Enter the money for withdraw"<<endl;
        cin>>withdrawMoney;
        if(withdrawMoney < balance){
            balance = balance - withdrawMoney;
            cout<<withdrawMoney<<" money is succussfully withdraw. Your current balance is "<<balance<<endl;
        }else{
            cout<<"Please enter the correct money for withdraw "<<withdrawMoney<<" is not correct number"<<endl;
        }
    }
    void display(){
        cout<<"Your current balance is "<<balance<<endl;
    }
};

int main(){
    Bank account(1000);
    account.display();
    account.deposit();
    account.withdraw();
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

