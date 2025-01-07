#pragma once

template <typename T>
class SmartPtr {
    T* ptr; //Actual pointer
public:
    explicit SmartPtr(T *p = nullptr) {ptr = p;}

    //Destructor
    ~SmartPtr() {delete (ptr);}

    //Overloading deferencing pointer
    T& operator*() {return *ptr;}

    //Overloading arrow operator so that members of
    //T can be accessed like a pointer(useful if T represents
    //a class or struct or union type)
    T* operator->() {return ptr;}
};