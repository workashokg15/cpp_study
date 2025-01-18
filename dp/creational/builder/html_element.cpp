#include "html_builder.hpp"
#include "html_element.hpp"

std::string HtmlElement::str(size_t indent) const {
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

HtmlBuilder HtmlElement::create(string root_name)
{
    return HtmlBuilder{root_name};
}

