#include "../common.hpp"
using namespace AshokProgramming;

int main()
{
    int arr[] = {2, 4, 6, 9, 12, 15, 18, 20};
    size_t size = sizeof(arr)/sizeof(int);
    //cout << size << endl;

    //return position starting from 1, return 0 if not found.
    auto binary_search = [&](size_t start_index, size_t end_index, int& key, auto&& binary_search)->size_t{
        if(end_index < start_index) return 0;
        size_t mid = (end_index + start_index)/2;
        
        if(key == arr[mid]) {
            return mid+1;
        } else if (key < arr[mid]) {
            return binary_search(start_index, mid-1, key, binary_search);
        } else if (key > arr[mid]) {
            return binary_search(mid+1, end_index, key, binary_search);
        }
        return 0;
    };

    int key = 2;
    size_t pos = binary_search(0, size-1, key, binary_search);
    cout << "key position of "<< key <<  " is : " << pos << endl;
    key = 8;
    pos = binary_search(0, size-1, key, binary_search);
    cout << "key position of "<< key <<  " is : " << pos << endl;

    auto binary_search_templated = [&]<typename T>(size_t start_index, size_t end_index, T& key, T tarr[], auto&& binary_search_templated)->size_t{
        if(end_index < start_index) return 0;
        size_t mid = (end_index + start_index)/2;
        
        if(key == tarr[mid]) {
            return mid+1;
        } else if (key < tarr[mid]) {
            return binary_search_templated(start_index, mid-1, key, tarr, binary_search_templated);
        } else if (key > tarr[mid]) {
            return binary_search_templated(mid+1, end_index, key, tarr, binary_search_templated);
        }
        return 0;
    };
    key = 8;
    pos = binary_search_templated(0, size-1, key, arr, binary_search_templated);
    cout << "key position of "<< key <<  " is : " << pos << endl;

    double darr[] = {
        3.0, 6.4, 6.5, 7.6, 8.9, 14.0, 19.5, 
    };
    size = sizeof(darr)/sizeof(double);
    double dkey = 19.5;
    pos = binary_search_templated(0, size - 1, dkey, darr, binary_search_templated);
    cout << "key position of "<< dkey <<  " is : " << pos << endl;

    return 0;
}