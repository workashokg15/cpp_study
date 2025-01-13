#pragma once

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

namespace AshokProgramming {

void test_fp()
{
    cout << "funtion pointer" << endl;
}

bool match(string test, int val=3)
{
    return test.size()==val; 
}

// bool match(string test)
// {
//     return test.size()==3; 
// }

int count_string_match(vector<string> &tests, bool (*match)(string, int), int matcher)
{
    int count = 0;
    for(auto test:tests) {
        match(test, matcher) ? count++:count=count;
    }
    return count;
}


class Parent {
    private:
    int one;
    public:
    Parent():one(1)
    {

    }
    virtual void print()
    {
        cout << "parent:" << one << endl;
    }
    Parent(const Parent& p): one(1)
    {
        one = p.one;
        cout << "parent copy constructor" << endl;
    }
    virtual ~Parent()
    {

    }
};

class Child : public Parent {
    public:
    void print()
    {
        cout << "child" << endl;
    }
};

}//namespace AshokProgramming


using namespace AshokProgramming;
void test_function_pointers()
{
    void(*fp)();
    fp = test_fp;

    fp();

    vector<string> tests;
    tests.push_back("one");
    tests.push_back("two");
    tests.push_back("three");
    tests.push_back("four");
    tests.push_back("five");
    tests.push_back("six");
    tests.push_back("sevem");
    tests.push_back("eogjt");
    tests.push_back("nine");

    cout << boolalpha << match("oned") << endl;

    //cout << count_if(tests.begin(), tests.end(), match) << endl;

    cout << count_string_match(tests, match, 5) << endl;
    return;
}

void test_object_slicing()
{
    Child c1;
    Parent &p1 = c1;
    p1.print();

    Parent p2 = Child();
    p2.print();
}

struct Test 
{
    virtual bool operator()(const string &text) const=0;
    virtual ~Test(){}
};

struct MatchTest : public Test{
    bool operator()(const string &text) const{
        return text == "lion";
    }
};

void check(string text, Test &test)
{
    if(test(text)) {
        cout << "Text matches " << endl;
    } else {
        cout << "No match" << endl;
    }
}

void test_functors()
{
    MatchTest pred;

    cout << boolalpha << pred("lion") << endl;
    cout << boolalpha << pred("lion1") << endl;
    cout << boolalpha << pred("tiger") << endl;

    MatchTest m;
    check("lion", pred);
}