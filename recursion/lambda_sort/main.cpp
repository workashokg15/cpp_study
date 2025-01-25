#include <vector>
#include <algorithm>
#include <unordered_map>
#include "../common.hpp"
using namespace AshokProgramming;
namespace AshokProgramming{
enum class Order{
    ASC,
    DEC,
};

unordered_map<Order, string> order_map = {
    {Order::ASC, "ascending"},
    {Order::DEC, "decending"},
};

void lambda_sort(vector<int>& vec, Order o)
{
    cout << order_map[o] << " order" << endl;  
    sort(vec.begin(), vec.end(), [o](int& a, int &b) {
        if(o == Order::ASC)
            return a < b;
        return a > b;
    });
}
} //namespace AshokProgramming

using namespace AshokProgramming;
int main()
{
    vector<int> vec{3,6,5,7,9,1};
    print_vector<int>(vec);
    lambda_sort(vec, Order::ASC);
    print_vector<int>(vec);
    lambda_sort(vec, Order::DEC);
    print_vector<int>(vec);
    return 0;
}