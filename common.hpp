#pragma once
#include <vector>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

namespace AshokProgramming {
template <typename T>
void print_vector(vector<T>& vec)
{
    for(auto& i : vec){
        cout << i << " ";
    }
    cout << endl;
}

template <typename T>
void print_almost_any(T &v)
{
    for (auto& i : v) {
        cout << i << " " ;
    }
    cout << endl;
}

template <typename T>
void print_array(T a[], size_t size)
{
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}


function<vector<int>&(vector<int>&, int&)> vectorize_integer = [](vector<int>& in, int& n)->auto&{
    {};
    while(n>=1){
        in.push_back(n%10);
        n = n/10;
    }
    reverse(in.begin(), in.end());
    return in;
};




} //namespace AshokProgramming