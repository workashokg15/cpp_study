#include "html_builder.hpp"
#include "html_element.hpp"

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
    HtmlBuilder hb = HtmlElement::build("ants");
    hb.add_child("ant1", "tom").
       add_child("ant2","HARRY");
    cout << hb.str() << endl;    
}   