# Structural Design Patterns

Structural design patterns are design patterns that ease the design by identifying a simple way to realize relationships between entities. These patterns focus on how classes and objects can be composed to form larger structures.

## Types of Structural Design Patterns

1. **Adapter Pattern**
    - Converts the interface of a class into another interface clients expect. Adapter lets classes work together that couldn't otherwise because of incompatible interfaces.

2. **Bridge Pattern**
    - Decouples an abstraction from its implementation so that the two can vary independently.

3. **Composite Pattern**
    - Composes objects into tree structures to represent part-whole hierarchies. Composite lets clients treat individual objects and compositions of objects uniformly.

4. **Decorator Pattern**
    - Attaches additional responsibilities to an object dynamically. Decorators provide a flexible alternative to subclassing for extending functionality.

5. **Facade Pattern**
    - Provides a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

6. **Flyweight Pattern**
    - Uses sharing to support large numbers of fine-grained objects efficiently.

7. **Proxy Pattern**
    - Provides a surrogate or placeholder for another object to control access to it.

## Example

### Adapter Pattern Example in C++

```cpp
#include <iostream>
#include <string>

// Target interface
class Target {
public:
     virtual void request() const {
          std::cout << "Target: The default target's behavior." << std::endl;
     }
};

// Adaptee class with a different interface
class Adaptee {
public:
     void specificRequest() const {
          std::cout << "Adaptee: Specific request." << std::endl;
     }
};

// Adapter class makes the Adaptee's interface compatible with the Target's interface
class Adapter : public Target {
private:
     Adaptee* adaptee;

public:
     Adapter(Adaptee* a) : adaptee(a) {}

     void request() const override {
          adaptee->specificRequest();
     }
};

int main() {
     Adaptee* adaptee = new Adaptee();
     Target* target = new Adapter(adaptee);
     target->request();

     delete adaptee;
     delete target;
     return 0;
}
```

In this example, the `Adapter` class makes the `Adaptee`'s interface compatible with the `Target`'s interface, allowing them to work together.
