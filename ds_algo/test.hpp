#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include "common.hpp"
using namespace std;

void test_vector()
{
    vector<int> v{3, 9};
    vector<int>::iterator iter_begin = v.begin();
    vector<int>::iterator iter_end = v.end();
    print_vector(v);

    v.push_back(4444);
    v.emplace_back(5555);
    v.push_back(4444);
    v.push_back(4444);

    for(int i = 0; i < 10; i++)
        v.push_back(rand()%999);
    print_vector(v);
    v.erase(remove_if(v.begin(), v.end(), [&](int x){return x == 4444;}), v.end());
    print_vector(v);
    iter_begin = v.begin();
    iter_end = v.end();
    v.erase(v.begin() + 2);
    print_vector(v);

    int foo[10] = {10,10,20,20,30,30,20,20,10,10};
    int foo_size = sizeof(foo)/sizeof(foo[0]);
    print_arr(foo, foo_size);
    auto end = remove(foo, foo + foo_size, 20);
    //recalculate foo
    foo_size = end - foo;
    print_arr(foo, foo_size);
}

void test_list()
{
    list<int> ll = {22,33};
    print_list(ll);

    ll.push_front(11);
    ll.push_front(666);
    ll.push_front(11);
    ll.push_front(11);
    ll.push_back(33);
    ll.push_back(11);
    print_list(ll);

    auto it = ll.begin();
    it++;
    it++;
    ll.erase(it);
    print_list(ll);

    for (auto erase_it = ll.begin(); erase_it != ll.end(); erase_it++)
    {
        if(*erase_it == 11) {
            erase_it = ll.erase(erase_it);
        }
    }
    print_list(ll);
    for (auto erase_it = ll.begin(); erase_it != ll.end(); erase_it++) {
        if(*erase_it == 22) {
            ll.insert(erase_it, 444);
        }
    }
    print_list(ll);
}

void test_map()
{
    map<string, int> ages;
    ages["guru"] = 32;
    ages["guru1"] = 42;
    ages["guru2"] = 52;

    print_map(ages, "ages", "map contains :");

    if(ages.find("guru5") != ages.end()) {
        cout << "found guru in ages" << endl;
    } else {
        cout << "not found in ages" << endl;
    }

    //Update a value in key
    auto it = ages.begin();
    it = ages.find("guru1");
    if(it != ages.end()) {
        it->second = 65; 
    }
    print_map(ages, "ages", "map contains :");

    pair<string, int> add_to_map = {"student1", 23};
    ages.insert(add_to_map);
    add_to_map.first = "student2";
    ages.insert(add_to_map);
    auto rt = ages.emplace(add_to_map);
    auto stfun = [](const auto &rt)->string
    {
       string ret = "false";
       if(rt.second)  ret = "true" ;
       return ret;
    };
    string status = stfun(rt);
    cout << "emplace returns " << status << endl;
    print_map(ages, "ages", "map contains :");

    ages.erase("student1");
    print_map(ages, "ages", "map contains :");

}

class Person
{
    string name;
    unsigned int age;
public:
    Person():name(""), age(0) {}
    Person(string name, unsigned int age):name(name), age(age) {}
    void print() const
    {
        cout << "[" << name << "] : " << age << endl;
    }
};

class Person2
{
    string name;
    unsigned int age;
public:
    Person2():name(""), age(0) {}
    Person2(string name, unsigned int age):name(name), age(age) {}

    void print() const
    {
        cout << "[" << name << "] : " << age << endl;
    }
    bool operator<(const Person2 &other) const
    {
        if(name == other.name) {
            return age < other.age;
        } else {
            return name < other.name;
        }
    }

    string get_name() const
    {
        return name;
    }
    unsigned int get_age() const
    {
        return age;
    }
};


void test_map_person() 
{
    map<int, Person> people;
    people[0] = Person{"Haier", 35};
    people[1] = Person{"Mayou", 37};
    people[2] = Person{"silken", 32};

    print_map2(people, "people", "people map : ");

    map<Person2, int> people2;
    people2[Person2("Mike", 40)] = 40;
    people2[Person2("Mike", 42)] = 42;
    people2[Person2("Sue", 30)] = 30;
    people2[Person2("Raj", 20)] = 30;

    for(auto it = people2.begin(); it != people2.end(); it++) {
        cout << "["<< it->first.get_name() << "," << it->first.get_age()<< "]:" << it->second << endl;      
    }

}

void test_multimap()
{
    multimap<int, string> mm;
    mm.insert(make_pair(10, "lala1"));
    mm.insert(make_pair(30, "lala31"));
    mm.insert(make_pair(20, "lala2"));
    mm.insert(make_pair(30, "lala32"));

    for (auto it=mm.begin(); it != mm.end(); it++) {
        cout << it->first << ":" << it->second << endl;
    }
    cout << endl;

    pair<multimap<int, string>::iterator, multimap<int, string>::iterator> itr = mm.equal_range(30);
    for (auto it=itr.first; it != itr.second; it++) {
        cout << it->first << ":" << it->second << endl;
    }
    cout << endl;


}

class TestStack 
{
    string name;
public:
    TestStack():name("") {}
    TestStack(string name):name(name) {}
    void print() const
    {
        cout << name << endl;
    }
};

void test_stack()
{
    stack<TestStack> s;
    s.push(TestStack("jone"));
    s.push(TestStack("jone1"));
    s.push(TestStack("jone2"));
    s.push(TestStack("jone3"));

#if 0
    TestStack t1 = s.top();
    t1.print();
    s.pop();
    s.pop();
    t1 = s.top();
    t1.print();

    s.pop();
    s.pop();
    if(!s.empty())
        t1 = s.top();
    t1.print();
#endif
    TestStack t1;
    while(!s.empty()) {
        t1 = s.top();
        t1.print();
        s.pop();
    }
    cout << endl;
}

void test_queue()
{
    queue<TestStack> s;
    s.push(TestStack("jone"));
    s.push(TestStack("jone1"));
    s.push(TestStack("jone2"));
    s.push(TestStack("jone3"));

#if 0
    TestStack t1 = s.top();
    t1.print();
    s.pop();
    s.pop();
    t1 = s.top();
    t1.print();

    s.pop();
    s.pop();
    if(!s.empty())
        t1 = s.top();
    t1.print();
#endif
    TestStack t1;
    while(!s.empty()) {
        t1 = s.front();
        t1.print();
        s.pop();
    }
    cout << endl;

}

class TestSort {
    int id;
    string name;
public:
    void swap(TestSort &other)
    {
        std::swap(id, other.id);
        std::swap(name, other.name);
    }
    TestSort():id(0), name("") {}
    TestSort(int id, string name):id(id), name(name) {}
    TestSort(pair<int, string> p)
    {
        id = p.first;
        name = p.second;
    }
    void print() const
    {
        cout << id << ":"<< name << endl;
    }
    TestSort(const TestSort &other)
    {
        *this = other;
    }

    TestSort(TestSort &&other)
    {
        other.swap(*this);
    }

    const TestSort& operator=(const TestSort &other)
    {
        id = other.id;
        name = other.name;
        return *this;
    }

    const TestSort& operator=(TestSort &&other)
    {
        TestSort temp(move(other));
        temp.swap(*this);
        return *this;
    }

    bool operator<(const TestSort &other) const
    {
        if(id == other.id) {
            return name < other.name;
        } else {
            return id < other.id;
        }
    }
    void set_id(int id)
    {
        this->id = id;
    }
    void set_name(string name)
    {
        this->name = name;
    }
    friend bool comp_testsort(TestSort &t1, TestSort &t2);
    friend ostream& operator<<(ostream &out, const TestSort &ts);
};

 ostream& operator<<(ostream &out, const TestSort & ts)
 {
    out << ts.name << ":" << ts.id; 
    return out;
 }

void copy_test_copyconstructor(TestSort &other)
{
    TestSort ts(other);    
}

void move_test_moveconstructor(TestSort &&other)
{
    TestSort ts(move(other));
}

bool comp_testsort(TestSort &t1, TestSort &t2)
{
    if(t1.name == t2.name) {
        return t1.id < t2.id;
    } else {
        return t1.name < t2.name;
    }
}

void test_vector_sort()
{
    vector<TestSort> v;
    auto p1 = make_pair(5, "heman5");
    auto p2 = make_pair(6, "heman6");
    TestSort t1{p1};
    TestSort t2 = t1;
    t2.set_id(7);
    t2.set_name("heman7");
    TestSort ts(p2);
    TestSort t6 = move(ts);


    v.push_back(TestSort(1, "heman1"));
    v.push_back(TestSort(4, "heman4"));
    v.push_back(TestSort(2, "heman2"));
    v.push_back(TestSort(3, "heman3"));
    v.push_back(t2);
    v.push_back(move(t1));
    v.push_back(t6);
    //v.push_back(TestSort(make_pair<int, string>(5, "heman5"));
    for (auto ids : v) {
        cout << ids << endl;
    }
    cout << "before sort" << endl;

    //sort(v.begin(), v.end());
    sort(v.begin(), v.end(), comp_testsort);
    for (auto ids : v) {
        ids.print();
    }
    cout << endl;
}