#include <map>
#include <string>
#include <functional>

void test_basic_builder();
void test_fluent_builder();
void test_build_with_static_build();

map<std::string, function<void()>> g_test_mp = {
    {"test_basic_builder", test_basic_builder},
    {"test_fluent_builder", test_fluent_builder},
    {"test_build_with_static_build", test_build_with_static_build},
};


