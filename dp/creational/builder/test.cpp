#include "html_builder.hpp"
#include "html_element.hpp"
#include "test.hpp"
#include <iostream>

using namespace std;
extern map<int, std::pair<std::string, function<void()>>> g_test_mp;

void run_tests()
{
    int i = 1;
    size_t mp_size = g_test_mp.size();
    //check_rtti();
    while(1) {
        i = 1;
        int j;
        for (auto& test:g_test_mp) {
            cout << test.first << " : " << test.second.first << endl;
            i++;
        }
        cout << i << ":" << "to run all tests" << endl;
        cout << 0 << ":" << "to exit" << endl;
        cin >> j;
        auto it = g_test_mp.find(j);
        if(it != g_test_mp.end()) {
            it->second.second();
        }
        if (j == i) {
            for (auto &test:g_test_mp) {
                test.second.second();
            }
        } else if (!j) break;
    }
}

void test_basic_builder()
{
    HtmlBuilder hb{"ul"};
    hb.add_child("li", "hello");
    hb.add_child("li", "world");
    cout << hb.str() << endl;
}

void test_fluent_builder()
{
    cout << endl;
    cout <<"fluent_builder" << endl;
    HtmlBuilder fhb{"lovely"};
    fhb.add_child("baby1", "nisha").
        add_child("baby2", "lakshar").
        add_child("baby3", "philomina");
    cout << fhb.str() << endl;
}

void test_build_with_static_build()
{
    cout << endl;
    cout << "building with fluent and static function in HtmlElement to build" << endl;
    HtmlElement hb = HtmlElement::create("ants").
       add_child("ant1", "tom").
       add_child("ant2","HARRY");
    cout << hb.str() << endl;    
}   