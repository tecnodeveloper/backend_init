# Function Overloading &  Overriding and operator overloading
## Function Overloading

Function overloading means **multiple functions with the same name but different parameters** within the same class or scope.

## Function Overriding

Function overriding occurs when a derived class defines a function with the same name, parameters, and return type as in the base class.

---

#  Why Do These Concepts Exist?

## Overloading:

- Avoids multiple confusing function names
- Improves readability
- Allows same operation with different inputs

## Overriding:

- Enables runtime polymorphism
- Allows child classes to modify inherited behavior
- Supports flexible and extensible design

---

#  Mental Models

## Overloading Mental Model

Think of a **restaurant menu button labeled “Order”**:

- Order(Pizza)
- Order(Burger)
- Order(Drink)

Same name → different inputs → different behavior

---

## Overriding Mental Model

Think of a **base app feature (Login)**:

- Base login = email/password
- Google login overrides behavior
- Apple login overrides behavior

Same function → different class → different behavior

##  Common Mistakes

- Changing parameter list (becomes overloading, not overriding)
- Forgetting inheritance
- Ignoring runtime binding rules

---

## Function Overloading Syntax

```javascript
class Calculator {
  add(a, b) {}
  add(a, b, c) {}
}
```

---

## Function Overriding Syntax

```javascript
class Parent {
  show() {
    console.log("Parent show");
  }
}

class Child extends Parent {
  show() {
    console.log("Child show");
  }
}
```
##  Key Points

- Same function signature
- Different class (inheritance required)
- Runtime polymorphism
- Child replaces parent behavior

---

#  OVERLOADING vs OVERRIDING

|Feature|Overloading|Overriding|
|---|---|---|
|Concept Type|Compile-time polymorphism|Runtime polymorphism|
|Location|Same class|Parent-child classes|
|Parameters|Must differ|Must be same|
|Inheritance needed|No|Yes|
|Binding|Early binding|Late binding|
|Purpose|Flexibility in inputs|Behavior modification|

---

#  Edge Cases & Pitfalls

---

## Overloading Pitfalls

- Only parameter difference matters (C++)
- Return type alone cannot differentiate
- Ambiguous calls cause compiler errors

---

## Overriding Pitfalls

- Signature mismatch breaks override
- Missing virtual keyword in C++
- Accidentally creating overload instead of override

---

#  Internal Behavior (Advanced Insight)

---

## Overloading (Compile-Time Resolution)

- Compiler selects function before execution
- Based on:
    - Number of parameters
    - Types of parameters

---

## Overriding (Runtime Resolution)

- Uses **virtual function table (vtable)** in C++
- Decision happens during execution
- Enables polymorphism

---
## Payment Gateway System (Overriding)

- Stripe overrides payment processing
- PayPal overrides payment processing
- Razorpay overrides payment processing

---

#  Mental Model Summary

## Overloading:

> Same name, different inputs → “Multiple ways to do same action”

## Overriding:

> Same function, different class → “Replace behavior in child”

---

#  Key Points

- Overloading = multiple behaviors in same class
- Overriding = modified behavior in subclass
- Overloading is compile-time
- Overriding is runtime
- C++ supports both; JavaScript only simulates them

---

#  Interview Summary

- Overloading: same function name, different parameters
- Overriding: same function signature in derived class
- Overloading = compile-time polymorphism
- Overriding = runtime polymorphism
- Overriding requires inheritance
- C++ uses vtable for overriding internally

---

#  Final Mental Model

- Overloading → “Many forms of input”
- Overriding → “New form of behavior”

---