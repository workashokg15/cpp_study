#include "common.hpp"
#include "range_based_loop.hpp"
#include "nested_templates.hpp"

int main()
{
    type_information();
    range_based_loop();
    test_nested_templates();
    //Initialisation
    //Initialiser list
    initialiser_list();
    test_lambda();
    test_mutable_lambda();

    test_delegating_constructors();
    return 0;
}