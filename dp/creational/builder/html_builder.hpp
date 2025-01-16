#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include <memory>
using namespace std;

class HtmlElement;
class HtmlBuilder {
    unique_ptr<HtmlElement> root;
public:
    HtmlBuilder(string rootname);
    HtmlBuilder& add_child(string&& child_name, string&& child_text);
    std::string str();
};


