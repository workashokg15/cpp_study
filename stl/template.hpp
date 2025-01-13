#pragma once
#include <iostream>
using namespace std;

namespace AshokProgramming 
{
template <class T, class K>
class TestTemplate
{
    T obj;
public:
    TestTemplate(T obj):obj(obj) {}
    void print() 
    {
        cout << obj << endl;
    }
};

template <typename T>
void print_template(T n)
{
    cout << n << endl;
}
}//namespace AshokProgramming

using namespace AshokProgramming;
void test_templates()
{
    TestTemplate<string, int> test1("hello");
    test1.print();
    print_template<string>("hello1");
    print_template("me here");
    print_template<>(15);
}
