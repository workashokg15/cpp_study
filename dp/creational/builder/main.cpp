// C++ Program to Implement Reflection Using Run Time Type
// Information (RTTI)

#include <cxxabi.h>
#include <iostream>
#include <typeinfo>

using namespace std;

void run_tests();
void check_rtti();
int main()
{
    run_tests();
}


// Base class with a virtual destructor
class Base {
public:
    virtual ~Base() {}
};

// Derived class inheriting from Base
class Derived : public Base {
};

void check_rtti()
{
  // Creating a Derived object through Base pointer
    Base* basePtr
        = new Base(); 
                       

    // Get type information of the object pointed to by
    // basePtr
    const type_info& typeInfo = typeid(*basePtr);
    cout << "Type name: " << typeInfo.name() << endl;

    // Demangle the type name (if needed)
    int status;
    char* demangled = abi::__cxa_demangle(
        typeInfo.name(), nullptr, nullptr, &status);
    string typeName
        = (status == 0) ? demangled : typeInfo.name();
    cout << "Demangled type name: " << typeName << endl;
    free(demangled);

    // Compare types using typeid
    if (typeid(*basePtr) == typeid(Derived)) {
        cout << "Object is of type Derived" << endl;
    }

    // Safe casting using dynamic_cast
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr) {
        cout << "Successfully cast to Derived" << endl;
    }
    else {
        cout << "Casting failed" << endl;
    }
  // Freeing the allocated memory

    delete basePtr; 
}

