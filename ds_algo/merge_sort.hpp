#include "common.hpp"
#include <memory>
int test_merge_sort();

template <typename T>
void merge(vector<T>& vec, size_t left, size_t mid, size_t right) 
{
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    // vector<T>* lvec = new vector<T>(n1);
    // vector<T>* rvec = new vector<T>(n2);
    unique_ptr<vector<T>> lvec = make_unique<vector<T>>(n1);
    unique_ptr<vector<T>> rvec = make_unique<vector<T>>(n2);

    cout << "left : " << left << " mid :"<< mid << " right : " << right << " n1 : " << n1 << " n2 : "<< n2 << endl;
    common::print_vec( vec, "vec is");

    for(int i = 0; i < n1; i++) {
        (*lvec)[i] = vec[left + i];
    }
    for(int i = 0; i < n2; i++) {
        (*rvec)[i] = vec[mid + 1 + i];
    }
    common::print_vec((*lvec), "(*lvec) is");
    common::print_vec((*rvec), "(*rvec) is");


    size_t i = 0, j = 0, k = left;
    while( i < n1 && j < n2) {
        if((*lvec)[i] > (*rvec)[j]) {
            vec[k] = (*rvec)[j];
            j++;
        } else {
            vec[k] = (*lvec)[i];
            i++;
        }
        k+=1;
    }
    for (;i < n1;i++,k++) {
        vec[k] = (*lvec)[i];
    }
    for (;j < n2;j++,k++) {
        vec[k] = (*rvec)[j];
    }
    
    common::print_vec(vec, "vec is");
}

template <typename T>
void merge_sort(vector<T> &arr, size_t left_index, size_t right_index) 
{
    if (left_index >= right_index) 
        return;

    size_t mid = left_index + (right_index - left_index)/2;
    merge_sort(arr, left_index, mid);
    merge_sort(arr, mid + 1, right_index);
    merge(arr, left_index, mid, right_index);
}


int test_merge_sort() 
{
    cout << "==============> test_merge_sort() " << endl;
    vector<string> names = {"f", "e", "d", "c", "a"};    
    merge_sort(names, 0, names.size()-1);

    common::print_vec(names, "sorted names is");

    vector<double> doubles = {3.5, 2.7655, 23.43, 77.1234, 98.234};    
    merge_sort(doubles, 0, doubles.size()-1);

    common::print_vec(doubles, "sorted doubles is");


    return 0;
}