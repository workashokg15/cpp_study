#include "html_builder.hpp"
#include "html_element.hpp"

HtmlBuilder::HtmlBuilder(string rootname){
    root = unique_ptr<HtmlElement>(new HtmlElement());
    root->name = rootname;
    //cout << "reached " << __FILE__ << ":" << __LINE__ << flush << endl;
    //getchar();
}
std::string HtmlBuilder::str()
{
    return root->str();
}
HtmlBuilder& HtmlBuilder::add_child(string &&child_name, string &&child_text)
{
    HtmlElement e{child_name, child_text};
    root->elements.emplace_back(e);
    return *this;
}

// HtmlBuilder& HtmlBuilder::add_child(string child_name, string child_text)
// {
//     HtmlElement e{child_name, child_text};
//     root->elements.emplace_back(e);
//     return *this;
// }

HtmlElement HtmlBuilder::build() const
{
    return HtmlElement();
}

HtmlBuilder::operator HtmlElement() const
{
    return *root;
}
