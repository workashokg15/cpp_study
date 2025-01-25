#include "../common.hpp"
using namespace AshokProgramming;
#include <functional>

int main()
{
    function<unsigned long long(size_t, size_t)> factorial = [&](size_t n, size_t acc=1)->unsigned long long{
        if (n == 0) return acc;
        return factorial(n-1, n*acc);    
    };
    {};
    while(1) {
        string line;
        cout << "Enter q/Q to quit OR input a number: ";
        getline(cin, line);
        if(line == "q" || line == "Q") return 0;
        int num = stoi(line);

        int res = factorial(num, 1);
        cout << "factorial of " << num << "is " << res << endl;
    }
    return 0;
}