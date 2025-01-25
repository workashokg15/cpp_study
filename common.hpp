#pragma once
#include <vector>
#include <iostream>
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
void print_array(T a[], size_t size)
{
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

} //namespace AshokProgramming