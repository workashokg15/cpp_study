#include "thread_safe_queue.hpp"
#include <iostream>
#include <vector>
#include <thread>
#include <atomic>
#include <functional>
using namespace std;


class thread_pool {
private:
    atomic_bool done;
    vector<thread> threads;
    thread_safe_queue<function<void()>> work_queue;
    //join_threads joiner;

    void worker_thread()
    {
        while(!done) {
            shared_ptr<function<void()>> task = work_queue.wait_pop();
            if (task) {
                task();
            } else {
                this_thread.yield();
            }
        }
    }
public:
    thread_pool():done{false} {
        int const thread_count = thread::hardware_concurrency();

    template <typename function>
    void submit()
    {

    }
    
};

int main()
{
    return 0;
}


