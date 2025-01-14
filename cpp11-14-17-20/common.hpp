#pragma once
#include <bits/stdc++.h>
#include <initializer_list>
#include <functional>

using namespace std;

namespace AshokProgramming {
template <class T>
auto testt1(T value)->decltype(value) {
    return value;
}

template <class T, class S>
auto testt2(T value1, S value2)->decltype(value1 + value2) {
    return value1 + value2;
}

auto testret() -> int {
    return 8;
}

class TestI {
public:
    TestI(initializer_list<string> texts)
    {
        for (auto value:texts) {
            cout << value << endl;
        }
    }

    void print(initializer_list<string> texts)
    {
        for(auto value:texts){
            cout << value << endl;
        }
    }
};


}//namespace AshokProgramming {
using namespace AshokProgramming;

void type_information()
{
    string value;
    cout << typeid(value).name() << endl;
    decltype(value) name = "bobby";
    cout << name << endl;

    auto value7 = 7;
    cout << value7 << endl;
    cout << testret() << flush <<  endl;
    cout << testt1<>(9) << endl;
    auto dd = testt2<>(10,12.5);
    cout << dd << endl;
    cout << typeid(dd).name()<< endl;
}



void initialiser_list()
{
    vector<int> v{1, 4, 5};
    cout << v[1] << endl;
    TestI test{"one", "TWO", "three"};

    test.print({"fie", "si", "eig"});
}

void testl(void (*pfunc)()){
    pfunc();
}
void testl1(void (*pfunc)(string), string name){
    pfunc(name);
}

double testl2(double(*pfunc)(double, double), double a, double b)
{
    return pfunc(a, b);
}

class TestLambdaThis
{
private:
    int one{1};
    int two{2};
public:
    void run() {
        int three{3};
        int four{4};

        auto pLambda = [this, three, four]()
        {
            one = 3;
            cout << one << endl;
            cout << four << endl;
        };
        pLambda();
    }
};

bool check(string &test)
{
    return test.size() == 5;
}

struct Check {
    Check(size_t chk): check_size{chk} {}
    bool operator()(const string &test) const
    {
        return test.size() == check_size;
    }
private:
    size_t check_size = 3;
};

void run(function<bool(string&)> check)
{
    string test = "dog";
    cout << check(test) << endl;
}

void test_lambda()
{
    auto func = [](){cout << "hello lambda" << endl;};
    func();
    testl(func);

    auto pGreet = [](string name){cout << name << endl;};
    pGreet("my name");
    testl1(pGreet, "my name");

    auto pDivide = [](double a, double b)->double
    {
        if(b==0) {
            return 0;
        } else {
            return a/b;
        }
    };
    cout << pDivide(5.4, 6.7) << endl;

    cout << testl2(pDivide, 6.4, 4.3) << endl;


    int one = 1;
    int two = 2;
    int three = 3;

    //Capture one and two by value
    [one, two]()->void
    {
        cout << one << "," << two << endl;
    }();

    //Capture all variables by value
    [=]()->void
    {
        cout << one << "," << two << endl;
    }();
    //Capture all variables by value and three by reference
    [=, &three]()->void
    {
        cout << one << "," << two << "," << three << endl;
    }();

    //Capture all variables by reference
    [&]()->void
    {
        one = 5;
        cout << one << "," << two << "," << three << endl;
    }();

    //Capture all variables by reference and one by value
    [&, one]()->void
    {
        //one = 5; //this wont work since captured by value;
        cout << one << "," << two << "," << three << endl;
    }();

    //Capturing this in lambda
    TestLambdaThis tlt;
    tlt.run();

    int size = 3;

    auto lambda = [size](string text){return text.size()==size;};

    vector<string> vec {"one", "two", "three"};
    int count = count_if(vec.begin(), vec.end(), lambda);
    cout << count << endl;

    count = count_if(vec.begin(), vec.end(), check);
    cout << count << endl;

    Check chk{3};
    count = count_if(vec.begin(), vec.end(), chk);
    cout << count << endl;

    run(lambda);
    size = 5;
 //   run(lambda);


    function<int(int, int)> add = [](int a, int b){return a+b;};
    cout << add(5, 4) << endl;
}


void test_mutable_lambda()
{
    int cats = 5;
    function<void()> print = [cats]()mutable{
        cats = 8;
        cout << "no of cats : " << cats << endl;
    };
    print();
}

class Parent
{
private:
    int dogs{5};
    string text{"hello"};
public:
    Parent() : Parent("hello") {
        cout << "Parent no parameter constructur" << endl;
    }
    Parent(string text) { 
        this->text = text;
        cout << "Parent constructor with parameter" << endl;
    }
};

class Child : public Parent
{
    public:
    Child() = default;

    Child(string text) : Parent("text")
    {
        cout << "Child with parameter" << endl;
    }
};

void test_delegating_constructors()
{
    cout << "Delegating constructors" << endl;
    Parent p;
    Child c;
    Child("hello");
}