#pragma once
#include <atomic>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <memory>

using namespace std;

template <typename T>
class thread_safe_queue {
private:
    mutex m;
    condition_variable cv;
    std::queue<shared_ptr<T>> q;

public:
    thread_safe_queue() {

    }
    thread_safe_queue(thread_safe_queue const &other) {

    }
    void push(T data) {
        lock_guard<mutex> lg{m};
        q.push(make_shared<T>(data));
        cv.notify_one();
    }
    bool pop(T &ref)
    {
        lock_guard<mutex> lg{m};
        if (q.empty()) {
            return shared_ptr<T>();
        } else {
            shared_ptr<T> ref(q.front());
            q.pop();
            return ref;
        }
    }
    shared_ptr<T> pop()
    {
    }
    
    shared_ptr<T> wait_pop()
    {
        unique_lock<mutex> lg{m};
        cv.wait(lg, [this]
        {
            return !q.empty();
        });
        shared_ptr<T> ref = q.front();
        q.pop();
        return ref;
    }

    size_t size()
    {
        lock_guard<mutex> lg{m};
        return q.size();
    }
    bool empty()
    {
        lock_guard<mutex> lg{m};
        return q.empty();
    }
};