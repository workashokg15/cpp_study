#pragma once
#include <bits/stdc++.h>
using namespace std;

namespace AshokProgramming {
template <class T>
auto testt1(T value)->decltype(value) {
    return value;
}

template <class T, class S>
auto testt2(T value1, S value2)->decltype(value1 + value2) {
    return value1 + value2;
}

auto testret() -> int {
    return 8;
}

}//namespace AshokProgramming {
using namespace AshokProgramming;

void type_information()
{
    string value;
    cout << typeid(value).name() << endl;
    decltype(value) name = "bobby";
    cout << name << endl;

    auto value7 = 7;
    cout << value7 << endl;
    cout << testret() << flush <<  endl;
    cout << testt1<>(9) << endl;
    auto dd = testt2<>(10,12.5);
    cout << dd << endl;
    cout << typeid(dd).name()<< endl;
}