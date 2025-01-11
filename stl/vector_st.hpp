#pragma once
#include <vector>
#include <iostream>

using namespace std;

namespace stl_study {
template <typename T>
void print_vec(vector<T>& my_vec)
{
    cout << "my vec size : " << my_vec.size()<< endl;
    for (auto vec : my_vec) {
        cout << vec << endl;
    }
    cout << endl;
}

void test_vector()
{
    vector<int> my_vec{2, 3, 5, 8, 12, 3};
    
    print_vec(my_vec);
    my_vec.push_back(34);
    print_vec(my_vec);
    my_vec.insert(my_vec.begin()+2, 3, 22);
    print_vec(my_vec);

    vector<int>::iterator it = my_vec.begin();

    my_vec.insert(it + 3, 2, 55);
    print_vec(my_vec);

    for (;it != my_vec.end(); it++) {
        cout << "iterator print : " << *it << endl;
    }
}

} //namespace stl_study {