#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <map>
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

void test_map_person() 
{
    map<int, Person> people;
    people[0] = Person{"Haier", 35};
    people[1] = Person{"Mayou", 37};
    people[2] = Person{"silken", 32};

    print_map(people, "People map : ");

}