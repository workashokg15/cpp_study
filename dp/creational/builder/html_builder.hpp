#pragma once
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class HtmlBuilder;
class HtmlElement {
    std::string name;
    std::string text;
    const size_t indent_size{2};
    std::vector<HtmlElement> elements;
public:
    friend class HtmlBuilder;
    HtmlElement() {}
    HtmlElement(const std::string& name, const std::string& text):text(text), name(name) 
     {}
    std::string str(size_t indent=0) const {
        std::ostringstream oss;
        string i(indent_size * indent, ' ');
        oss << i << "<" << name << ">" << endl;
        if(text.size() > 0) {
            oss << string(indent_size * (indent+1), ' ') << text << endl;
        }
        for (auto e:elements) {
            oss << e.str(indent+1);
        }
        oss << i << "</" << name << ">" << endl;
        return oss.str();    
    }

    static HtmlBuilder build(string root_name)
    {
        return {root_name};
    }
};

class HtmlBuilder {
    HtmlElement root;
public:
    HtmlBuilder(string rootname){
        root.name = rootname;
    }
    HtmlBuilder& add_child(string&& child_name, string&& child_text) {
        HtmlElement e{child_name, child_text};
        root.elements.emplace_back(e);
        return *this;
    }
    std::string str()
    {
        return root.str();
    }
};


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
    HtmlBuilder hb = HtmlElement::build("ants").
                        add_child("ant1", "tom").
                        add_child("ant2","HARRY");
    cout << hb.str() << endl;    
}   