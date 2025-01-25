#include "../common.hpp"
using namespace AshokProgramming;
#include <functional>

int main()
{
    const string arr[]={
        "hello",
        "how",
        "are",
        "you",
    };
    size_t size = sizeof(arr)/sizeof(string);
    print_array(arr, size);
    size_t size1 = size;
    function <void()> print_reverse_recursive = [&](){
        size1--;
        cout << arr[size1] << " ";
        if (size1 == 0){
            return;
        }
        print_reverse_recursive();
    };

    print_reverse_recursive();
    cout << endl;
    return 0;
}