#pragma once
#include <map>
#include <string>
#include <functional>

void test_basic_builder();
void test_fluent_builder();
void test_build_with_static_build();
void run_tests();

std::map<int, std::pair<std::string, std::function<void()>>> g_test_mp = {
    {1, {"test_basic_builder", test_basic_builder}},
    {2, {"test_fluent_builder", test_fluent_builder}},
    {3, {"test_build_with_static_build", test_build_with_static_build}},
};


