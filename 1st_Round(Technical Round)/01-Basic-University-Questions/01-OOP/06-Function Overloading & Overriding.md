# Function Overloading, Overriding, and Operator Overloading

# Function Overloading

Multiple functions having the same name but different parameter lists.

---

## Example

```cpp
class Calculator
{
public:
    int add(int a, int b)
    {
        return a + b;
    }

    double add(double a, double b)
    {
        return a + b;
    }

    int add(int a, int b, int c)
    {
        return a + b + c;
    }
};

int main()
{
    Calculator c;

    cout << c.add(2, 3) << endl;
    cout << c.add(2.5, 3.5) << endl;
    cout << c.add(1, 2, 3) << endl;
}
```

---

## Internal Behavior

Compiler chooses function based on:

- Number of arguments
- Data types of arguments
- Order of arguments

---

## Common Mistake

### Wrong

```cpp
int show();
double show();
```

This causes an error. Why?

Return type alone cannot overload functions.
### Correct

```cpp
int show(int x);
double show(double x);
```

---

# Function Overriding

> A derived class provides its own implementation of  inherited parent class function.

---

## Example

```cpp
#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void sound()
    {
        cout << "Animal Sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void sound() override
    {
        cout << "Bark" << endl;
    }
};

int main()
{
    Animal* a = new Dog();

    a->sound();
}
```

---
## Internal Behavior 

Most C++ compilers use:

### Virtual Table (vtable)

```text
Animal
 |
 +---- sound() -> Animal::sound
```

Dog updates entry:

```text
Dog
 |
 +---- sound() -> Dog::sound
```

Runtime looks up the table and calls the correct function.

---

## Common Mistake

### Wrong

```cpp
class Dog : public Animal
{
public:
    void sound(int x)
    {
        cout << "Bark";
    }
};
```

This is NOT overriding.

This is overloading.

---

### Correct

```cpp
void sound() override
{
    cout << "Bark";
}
```

---

# Operator Overloading


> Built-in operators to work with user-defined classes.

---

## Why Needed?

Built-in types support:

```cpp
int a = 5;
int b = 10;

int c = a + b;
```

Custom classes do not.

Without operator overloading:

```cpp
Complex c3 = c1.add(c2);
```

With operator overloading:

```cpp
Complex c3 = c1 + c2;
```

---

## Example

```cpp

class Complex
{
public:
    int real;
    int imag;

    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(const Complex& c)
    {
        return Complex(
            real + c.real,
            imag + c.imag
        );
    }
};

int main()
{
    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex c3 = c1 + c2;

    cout << c3.real << " "
         << c3.imag;
}
```

Output:

```text
6 8
```

---
# Real-World Examples

## Function Overloading: Backend API Service

Different ways to fetch users.

```cpp
getUser(int id);
getUser(string email);
getUser(string email, bool active);
```

Same operation:

```text
Get User
```

Different inputs.

---

## Function Overriding: Payment Gateway System

Base class:

```cpp
PaymentGateway
```

Derived classes:

```cpp
Stripe
PayPal
Razorpay
```

Each overrides:

```cpp
processPayment()
```

with its own implementation.

---

## Operator Overloading: Financial Software

```cpp
Money salary(50000);
Money bonus(10000);

Money total = salary + bonus;
```

More readable than:

```cpp
salary.add(bonus);
```    

---

# Comparison Table

|Feature|Function Overloading|Function Overriding|Operator Overloading|
|---|---|---|---|
|Purpose|Same function, different inputs|Change inherited behavior|Redefine operator behavior|
|Inheritance Required|No|Yes|No|
|Parameters|Must differ|Must be same|Depends on operator|
|Return Type|Can differ but not alone|Usually same/covariant|User-defined|
|Binding|Compile-Time|Runtime|Compile-Time|
|Polymorphism Type|Static|Dynamic|Static|
|Uses Virtual Function|No|Yes|No|
|Scope|Same class|Parent-child classes|User-defined classes|

---

# Edge Cases & Pitfalls

## Overloading Ambiguity

```cpp
void show(int);
void show(double);

show('A');
```

Compiler may choose an unexpected conversion.

---

## Overriding Without virtual

```cpp
class Animal
{
public:
    void sound();
};
```

Runtime polymorphism will not work.

Use:

```cpp
virtual void sound();
```

---

## Operator Overloading Abuse

Bad practice:

```cpp
user1 + user2;
```

Meaning:

```cpp
sendEmail(user1, user2);
```

Operators should represent intuitive actions.

---

# Key Points

- Function Overloading = Same name, different parameters.
    
- Function Overriding = Same signature, different implementation in derived class.
    
- Operator Overloading = Same operator, custom behavior for classes.
    
- Overloading and operator overloading are compile-time polymorphism.
    
- Overriding is runtime polymorphism.
    
- Overriding requires inheritance and virtual functions.
    
- Operator overloading improves readability for custom types.
    
- Not all operators can be overloaded (`::`, `.`, `?:`, `sizeof`).

---

# Interview Summary

### What is Function Overloading?

Same function name with different parameter lists in the same scope.

### What is Function Overriding?

A derived class redefines a virtual function from the base class.

### What is Operator Overloading?

Redefining the behavior of existing operators for user-defined types.

### Which Concepts Provide Compile-Time Polymorphism?

- Function Overloading
- Operator Overloading

### Which Concept Provides Runtime Polymorphism?

- Function Overriding

### Why is `virtual` Important?

It enables dynamic dispatch through the vtable mechanism.

### How Does `a + b` Work for Objects?

Compiler converts:

```cpp
a + b
```

into:

```cpp
a.operator+(b);
```

or

```cpp
operator+(a, b);
```

depending on implementation.

---

# Final Mental Model

### Function Overloading

```text
Same Function Name
+
Different Inputs
=
Different Behaviors
```

### Function Overriding

```text
Same Function
+
Different Class
=
Different Behavior
```

### Operator Overloading

```text
Same Operator
+
Different Object Type
=
Custom Behavior
```

### Unified View

```text
Overloading
    ├── Function Overloading
    └── Operator Overloading

Overriding
    └── Runtime Polymorphism
```

> Function Overloading, Function Overriding, and Operator Overloading are three different mechanisms that allow C++ programs to express polymorphic behavior while keeping code readable, maintainable, and closer to real-world problem modeling.