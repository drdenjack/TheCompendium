# Notes concerning all things that may be interesting

# SOLID Principles

## Single Responsiblity Principle
Classes should have a single reason to change
- Classes should only do one thing and that should be the only reason to change
- Example: A class can store information, but shouldn't be responsible for printing the information.  The information may change, that's one thing.  If the printing changes, that's a second thing.


## Open/Closed Principle
Classes should be open for extension but closed for modification
- Use inheritance instead of changing things


## Liskov Substitution Principle
Should be able to substitute a child class for a parent class without losing functionality.


## Interface Segregation Principle
Clients should not be forced to depend upon interfaces that they do not use.
Interfaces should be small so they can be used without including too many unused dependencies.

## Dependency Inversion Principle
High level modules should not depend on low level modules.
Both should depend on abastractions.

Parent classes should not know anything about their children

# GRASP - General Responsibility Assignment Software Patterns
- 9 principles

1. Information Expert
2. Creator
3. Low Coupling
4. High Cohesion
5. Controller
6. Polymorphism
7. Pure Fabrication
8. Indirection
9. Protected Variations

## Information Expert
Give the right job to the right class that has all the needed information

## Creator
Objects create the things they have.
Car "has a" wheel, so car class should create wheels.

## Low Coupling
Objects shouldn't depend on other objects if possible.

## High Cohesion
Class responsibilities are tightly focused.  Do one thing ...

## Controller
Controllers tells the worker classes to do the work so UI and whatever doesn't have to.

## Polymorphism
Child class can be substituted for parent classes.  
Shape.area() or Circle.area() ... blah blah

## Pure Fabrication
Create "fake" classes to interface from class A to class C.  It's a util or adapter, etc.

## Indirection
Middle man decoupling thing.  It's also an adapter thing.

## Protected Variations
Make an interface for things that change often, so regular classes don't have to change much.  Example: class that handles variable interest rates.

