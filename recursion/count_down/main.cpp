#include "../common.hpp"
using namespace AshokProgramming;
void count_down(size_t n)
{
    if(n <= 0) return;
    cout<<n<<endl;
    count_down(n-1);
}

int main()
{
    count_down(10);
    return 0;
}