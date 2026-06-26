#  Access Specifiers in C++

**Access specifiers** control **who can access the data and functions** of a class.
They define the **visibility (scope)** of class members.

---
## Types of Access Specifiers

C++ has **three main access specifiers**:

- `public`
- `private`
- `protected`

---
##  Public Access Specifier

 Members declared as **public** can be accessed **from anywhere** in the program.

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

##  Private Access Specifier

 Members declared as **private** can only be accessed **inside the class**.

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

##  Protected Access Specifier

   Members declared as **protected**:
    - Can be accessed inside the class or child classes
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
        cout<<x;
    }
};
int main(){
	Derived objDerived;
	objDerived.setX();
}
```

---

## Comparison Table

| Access Specifier | Same Class | Outside Class | Derived Class |
| ---------------- | ---------- | ------------- | ------------- |
| Public           | Yes        | Yes           | Yes           |
| Private          | Yes        | No            | No            |
| Protected        | Yes        | No            |  Yes          |

---

## Why Access Specifiers Are Important

They help in:

- **Encapsulation** (data hiding)
- Protecting data from unauthorized access    
- Controlling how data is modified
- Making code more secure and maintainable

---

## Real-World Analogy

Think of a **mobile phone**:

- **Public** → Screen (everyone can use)
- **Private** → Internal circuits (hidden)
- **Protected** → System settings (only accessible by advanced/system-level access)
-  Use getter/setter functions instead

---

### Overusing Public

Making everything public defeats **encapsulation**

---

##  Key Points

- `public` → open access
    
- `private` → restricted access
    
- `protected` → inheritance-based access

---

## Interview Tips

- **What is an access specifier?**  
    → A keyword that defines visibility of class members
    
- **Difference between private and protected?**  
    → Protected is accessible in derived classes, private is not
