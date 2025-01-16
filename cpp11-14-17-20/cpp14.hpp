#pragma once
#include <bits/stdc++.h>
#include <initializer_list>
using namespace std;

namespace AshokProgramming {

} //namespace AshokProgramming 
using namespace AshokProgramming;


constexpr int product(int x, int y)
{
    return (x * y);
}

constexpr auto fib(unsigned int n, unsigned int a = 0, unsigned int b = 1)
{
    if (n == 0) return a;
    if (n == 1) return b;
    cout << n << "," << a << "," << b << endl;
    return fib(n - 1, b, a + b);
}

constexpr unsigned long int fib2(unsigned int n)
{
    return (n <= 1) ? n : fib2(n-1) + fib2(n-2); 
}

void test_cpp14()
{
    auto fn1 = [](auto a, auto b){
        return a + b;
    };

    auto x = product(10, 20);
    cout << x << endl;
    cout << fn1(10, 20) << endl;

    int arr[product(3, 2)]{1,2,3,4,5,6};
    cout << arr[2] << endl;

    constexpr unsigned long fib4 = fib2(4);
    cout << fib4 << endl;
    cout << fib2(0) << endl;
    cout << fib2(9) << endl;
    cout << fib2(2) << endl;

}

template <typename... Args>
bool all(Args... args)
{
    return (... && args);
}

template <typename... Args>
int sum_fold(Args&&... args)
{
    return (args + ...);
}

void test_cpp17()
{
    bool b = all(true, false, true, true);
    cout << "Result : " << boolalpha << b << endl;
    cout << sum_fold(1, 3, 5, 7) << endl;
}

class ThreadExecute
{
public:
    void operator()() 
    {
        cout << "hello from class with id : " << this_thread::get_id() << endl;
    }
};

void other_operations()
{
    throw runtime_error("this is a runtime error");
}

class thread_guard {
    thread &_t;
public:
    //thread_guard(){}
    explicit thread_guard(thread &t): _t(t) {}
    ~thread_guard()
    {
        if(_t.joinable()) {
            _t.join();
            cout << "join called from destructor" << endl;
        }
    }
    thread_guard(const thread_guard &) = delete;
    thread_guard& operator=(const thread_guard &) = delete;
};

//RAII - Resource acquisition is initialisation
void test_thread()
{
    thread t1([]{
        cout << "hello from lambda with id : " << this_thread::get_id() << endl; 
    });
    ThreadExecute te;
    thread t2(te);
    auto tfn = []{
        cout << "in tfn with id : " << this_thread::get_id();
    };
    thread t3(te);
    thread_guard tg(t3);
    
    //t1.detach();
    if (t1.joinable()) {
        cout << "t1 is joinable" << endl;
    } else {
        cout << "not joinable" << endl;
    }

    try {
        other_operations();
        if(t1.joinable()) {
            t1.join();
        }
        t2.join();
    } catch(exception &e) {
        cerr << e.what() << endl;
        t1.join();
        t2.join();
    }
    
    if (t1.joinable()) {
        cout << "t1 is joinable" << endl;
    } else {
        cout << "not joinable" << endl;
    }
}

void test_thread_example()
{   
    int input = 0;
    set<string> s{
        "Enter 1 for cleaning",
        "Enter 2 for full speed ahead",
        "Enter 3 to stop",
        "Enter 100 to exit program",
    };
    map<int, string> m = {
        {1, "Clean the ship"},
        {2, "Full speed the ship"},
        {3, "Stop the ship"},
    };
    do {
        for (auto it = s.begin(); it != s.end(); it++)
            cout << *it << endl;
        cin >> input; 
        if (m.find(input) != m.end()) {
            thread t(
            [input, &m] {
                cout << m[input] << endl;
            });
            cout << endl;
            thread_guard tg(t);
        } else {
            cout << "Invalid order" << endl;
        }
    } while (input != 100);
}

void test_lam() 
{
    auto f = "ashok";
    
    vector<string> str = {"ashok", "asha", "ashok", "asha"};
    if(auto it = any_of(str.begin(), str.end(), [f](const string a) -> bool {
        return a == f;
    })) {
        cout << "found " << it << endl;
    }
}

namespace constexpr_math {
    
}
void test_concepts()
{
//concept and requires   
}