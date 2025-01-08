Behavioral Design Pattern
=========================
Behavioral design patterns are concerned with algorithms and the assignment of responsibilities between objects. They help in improving communication between objects.

### Types of Behavioral Design Patterns

1. **Chain of Responsibility**: Passes a request along a chain of handlers.
2. **Command**: Encapsulates a request as an object.
3. **Interpreter**: Implements a specialized language.
4. **Iterator**: Provides a way to access elements of a collection sequentially.
5. **Mediator**: Defines an object that encapsulates how a set of objects interact.
6. **Memento**: Captures and restores an object's internal state.
7. **Observer**: Defines a dependency between objects so that one object changes state, all its dependents are notified.
8. **State**: Allows an object to alter its behavior when its internal state changes.
9. **Strategy**: Defines a family of algorithms and makes them interchangeable.
10. **Template Method**: Defines the skeleton of an algorithm, deferring some steps to subclasses.
11. **Visitor**: Represents an operation to be performed on elements of an object structure.

### Example

Here is an example of the Observer pattern in C++:

```cpp
#include <iostream>
#include <vector>
#include <string>

class Observer {
public:
    virtual void update(const std::string &message_from_subject) = 0;
};

class Subject {
public:
    void attach(Observer *observer) {
        list_observer.push_back(observer);
    }
    void notify(const std::string &message) {
        for (Observer *observer : list_observer) {
            observer->update(message);
        }
    }
    void createMessage(const std::string &message = "Empty") {
        notify(message);
    }

private:
    std::vector<Observer *> list_observer;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(const std::string &name) : name(name) {}
    void update(const std::string &message_from_subject) override {
        std::cout << "Observer " << name << " received message: " << message_from_subject << std::endl;
    }

private:
    std::string name;
};

int main() {
    Subject subject;
    ConcreteObserver observer1("Observer1");
    ConcreteObserver observer2("Observer2");

    subject.attach(&observer1);
    subject.attach(&observer2);

    subject.createMessage("Hello, World!");
    return 0;
}
```