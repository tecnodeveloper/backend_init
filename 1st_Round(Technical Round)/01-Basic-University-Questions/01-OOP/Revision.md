


---
# Summary

---
class is blueprint like Map of building
Object is an instance like Real physical Building

---
Encapsulation is like binding data and functions in class So that direct access na ho We use private access specifier for data. 
Inheritence means child class has acquire properties of parent class through extend keyword.
polymorphism means one interface multiple implementation like function overloading at compile time and function overriding at runtime

---

public can access by everywhere
private can access only inside the class
protected access by module level

---

Constructor is special function that is used to intialize the object value
Destructor is used to clean up memory resources that is allocated by object

this pointer points to current object. like if there is displayName() function inside person class So we can access name by this.name;

---

Exception handling is used to handle unexpected errors that may lead to program crash. Such as during file storing the user Storage is full

Friend function is non member function which has access to private and protected part of class. like prefer to use getter setter function instead of friend function bcz it's break encapsulation

---

Function overloading means same name of function but different parameter like getUser(id), getUser(string email) but same name but input different
 
 Function overriding: means Same signature, different implementation in derived class. like payment gatway() parent class -> stripe gatway(), paypal gatway() are derived class
 
operator overloading means Same operator, custom behavior for classes.

---

Relationship between two object where they can communicate and interact with each other is [Association](https://blog.devgenius.io/association-composition-and-aggregation-in-c-925465987061). like patient class and doctor class can communicate with each other

In composition the parent and derived class are tightly coupled. Strong relationship. like Engine and car class, car can't exist without engine. 

In aggregation the child can live independently without parent class. weak relationship like University and student class student can study without University

---
Virtual function means Same signature, different implementation in derived class. like payment gatway() parent class -> stripe gatway(), paypal gatway() are derived class implementation.

Non member function that can execute without need of creating object.

---
