
#  Access Specifiers in C++

---

##  Definition

**Access specifiers** control **who can access the data and functions** of a class.
They define the **visibility (scope)** of class members.

---
## 2. Types of Access Specifiers

C++ has **three main access specifiers**:

- `public`
- `private`
- `protected`

---

## 3. Public Access Specifier

- Members declared as **public** can be accessed **from anywhere** in the program.

### Example:

```cpp
class Demo {
public:
    int x;
};

int main() {
    Demo d;
    d.x = 10; // Allowed
}
```

---

## 4. Private Access Specifier

- Members declared as **private** can only be accessed **inside the class**.

### Example:

```cpp
class Demo {
private:
    int x;
};

int main() {
    Demo d;
    d.x = 10; //  Error
}
```

---

## 5. Protected Access Specifier

- Members declared as **protected**:
    - Can be accessed inside the class
    - Can also be accessed by **derived (child) classes**
    - Cannot be accessed from outside

### Example:

```cpp
class Base {
protected:
    int x;
};

class Derived : public Base {
public:
    void setX() {
        x = 20; // Allowed
    }
};
```

---

## 6. Comparison Table

| Access Specifier | Same Class | Outside Class | Derived Class |
| ---------------- | ---------- | ------------- | ------------- |
| Public           | Yes        | Yes           | Yes           |
| Private          | Yes        | No            | No            |
| Protected        | Yes        | No            |  Yes          |

---

## 7. Why Access Specifiers Are Important

They help in:

- **Encapsulation** (data hiding)
- Protecting data from unauthorized access    
- Controlling how data is modified
- Making code more secure and maintainable

---

## 8. Real-World Analogy

Think of a **mobile phone**:

- **Public** → Screen (everyone can use)
- **Private** → Internal circuits (hidden)
- **Protected** → System settings (only accessible by advanced/system-level access)
---

-  Use getter/setter functions instead

---

### 3. Overusing Public

Making everything public defeats **encapsulation**

---

## 10. Key Points

- `public` → open access
    
- `private` → restricted access
    
- `protected` → inheritance-based access

---

## 11. Interview Tips

- **What is an access specifier?**  
    → A keyword that defines visibility of class members
    
- **Difference between private and protected?**  
    → Protected is accessible in derived classes, private is not
