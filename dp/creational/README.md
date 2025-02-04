# Creational Design Patterns

Creational design patterns are design patterns that deal with object creation mechanisms, trying to create objects in a manner suitable to the situation. The basic form of object creation could result in design problems or added complexity to the design. Creational design patterns solve this problem by controlling the object creation process.

## Types of Creational Design Patterns

1. **Singleton Pattern**
    - Ensures a class has only one instance and provides a global point of access to it.

2. **Factory Method Pattern**
    - Defines an interface for creating an object, but lets subclasses alter the type of objects that will be created.

3. **Abstract Factory Pattern**
    - Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

4. **Builder Pattern**
    - Separates the construction of a complex object from its representation so that the same construction process can create different representations.
    - Builder is seperate component for building an object
    - Can either give builder a constructor or return via static function
    - Fluent builder - Return this
    - Different Facets -->Use multiple inheritance via a base class to build an object with different attributes build via different derived classes.

5. **Prototype Pattern**
    - Specifies the kinds of objects to create using a prototypical instance, and creates new objects by copying this prototype.

## Examples

### Singleton Pattern

```cpp
class Singleton {
private:
     static Singleton* instance;
     Singleton() {}

public:
     static Singleton* getInstance() {
          if (instance == nullptr) {
                instance = new Singleton();
          }
          return instance;
     }
};

Singleton* Singleton::instance = nullptr;
```

### Factory Method Pattern

```cpp
class Product {
public:
     virtual void use() = 0;
};

class ConcreteProductA : public Product {
public:
     void use() override {
          // Implementation for ConcreteProductA
     }
};

class ConcreteProductB : public Product {
public:
     void use() override {
          // Implementation for ConcreteProductB
     }
};

class Creator {
public:
     virtual Product* factoryMethod() = 0;
};

class ConcreteCreatorA : public Creator {
public:
     Product* factoryMethod() override {
          return new ConcreteProductA();
     }
};

class ConcreteCreatorB : public Creator {
public:
     Product* factoryMethod() override {
          return new ConcreteProductB();
     }
};
```

### Abstract Factory Pattern

```cpp
class AbstractProductA {
public:
     virtual void use() = 0;
};

class AbstractProductB {
public:
     virtual void use() = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
     void use() override {
          // Implementation for ConcreteProductA1
     }
};

class ConcreteProductA2 : public AbstractProductA {
public:
     void use() override {
          // Implementation for ConcreteProductA2
     }
};

class ConcreteProductB1 : public AbstractProductB {
public:
     void use() override {
          // Implementation for ConcreteProductB1
     }
};

class ConcreteProductB2 : public AbstractProductB {
public:
     void use() override {
          // Implementation for ConcreteProductB2
     }
};

class AbstractFactory {
public:
     virtual AbstractProductA* createProductA() = 0;
     virtual AbstractProductB* createProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
     AbstractProductA* createProductA() override {
          return new ConcreteProductA1();
     }
     AbstractProductB* createProductB() override {
          return new ConcreteProductB1();
     }
};

class ConcreteFactory2 : public AbstractFactory {
public:
     AbstractProductA* createProductA() override {
          return new ConcreteProductA2();
     }
     AbstractProductB* createProductB() override {
          return new ConcreteProductB2();
     }
};
```

### Builder Pattern

```cpp
class Product {
public:
     void setPartA(const std::string& part) { /* ... */ }
     void setPartB(const std::string& part) { /* ... */ }
};

class Builder {
public:
     virtual void buildPartA() = 0;
     virtual void buildPartB() = 0;
     virtual Product* getResult() = 0;
};

class ConcreteBuilder : public Builder {
private:
     Product* product;

public:
     ConcreteBuilder() { product = new Product(); }
     void buildPartA() override { product->setPartA("PartA"); }
     void buildPartB() override { product->setPartB("PartB"); }
     Product* getResult() override { return product; }
};

class Director {
private:
     Builder* builder;

public:
     void setBuilder(Builder* b) { builder = b; }
     void construct() {
          builder->buildPartA();
          builder->buildPartB();
     }
};
```

### Prototype Pattern

```cpp
class Prototype {
public:
     virtual Prototype* clone() = 0;
};

class ConcretePrototype : public Prototype {
private:
     int field;

public:
     ConcretePrototype(int value) : field(value) {}
     Prototype* clone() override {
          return new ConcretePrototype(*this);
     }
};
```

These patterns provide various ways to create objects, helping to make your code more flexible and reusable.
