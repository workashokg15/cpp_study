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
    HtmlElement(const std::string& name, const std::string& text):text(text), name(name) {}
    std::string str(size_t indent=0) const;
    static HtmlBuilder build(string root_name);
};

