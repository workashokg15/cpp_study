#include "merge_sort.hpp"
#include "bst.hpp"
#include "smartptr.hpp"
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <list>
#include "test.hpp"

using namespace std;
using namespace common::ds_algo;



int main()
{
    test_merge_sort();

    cout << "press any key for bst " << endl;
    //getchar();

    test_bst_all();

    cout << "press any key for vector test" << endl;
    //getchar();
    test_vector();

    cout << "press any key for list test" << endl;
    //getchar();
    test_list();

    cout << "press any key for map test" << endl;
    //getchar();
    test_map();

    test_map_person();
    cout << "MULTIMAP test"<< endl;
    test_multimap();

    cout << "STACK QUEUE TEST" << endl;
    test_stack();
    cout << endl;
    cout << endl;
    test_queue();

    cout << endl;
    test_vector_sort();
    cout << endl;
    return 0;
}