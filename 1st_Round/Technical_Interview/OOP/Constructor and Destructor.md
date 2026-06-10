# Constructor and Destructor

---

## 1. Definition

- A **constructor** is a special member function that is automatically called when an object is created. It initializes the object.

- A **destructor** is a special function that is automatically called when an object is destroyed. It cleans up resources.
---
## 3. Mental Model

Think of an object like a **hotel room**:
- Constructor → preparing the room before guest arrives
- Destructor → cleaning the room after guest leaves

---

## 4. Syntax

```cpp
#include <iostream>
using namespace std;

class Example {
public:
    int value;

    // Constructor
    Example(int v) {
        value = v;
        cout << "Constructor called\n";
    }

    // Destructor
    ~Example() {
        cout << "Destructor called\n";
    }
};
```


---

``` C++

## 8. Real-World Example (Database Connection)

```cpp
#include <iostream>
using namespace std;

class DatabaseConnection {
public:
    string connectionString;

    DatabaseConnection(string conn) {
        connectionString = conn;
        cout << "Connected to DB\n";
    }

    ~DatabaseConnection() {
        cout << "Disconnected from DB\n";
    }
};

int main() {
    DatabaseConnection db("localhost");
}
```

## 11. Key Points

- Same name as class    
- No return type
- Called automatically 
- Can be overloaded

---

## 12. Interview Tip

Constructor = **object initialization**

---

# Destructor

---

## 13. Definition

A destructor is used to **release resources automatically** when an object is destroyed.

---

## 19. Key Points

- Same name as class with `~`
- No parameters, no return type
- Called automatically
- Only one destructor per class

---

## 20. Interview Tip

Destructor = **automatic cleanup**

---

#  Constructor vs Destructor

|Feature|Constructor|Destructor|
|---|---|---|
|Purpose|Initialize object|Clean resources|
|Execution|On creation|On destruction|
|Name|Class name|~ClassName|
|Parameters|Allowed|Not allowed|
|Overloading|Yes|No|

---

#  Final Mental Model

- Constructor → **Setup phase**
- Destructor → **Cleanup phase**
- Together → **Lifecycle control (RAII)**

---

#  Interview Summary

- Constructor initializes object automatically
- Destructor cleans resources automatically
- Always manage dynamic memory properly
