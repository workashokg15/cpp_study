#pragma once
#include <vector>
#include <iostream>
#include <list>
#include <map>
using namespace std;

namespace common {
    namespace ds_algo {
        class DLLNode {
            public:
            DLLNode(int data): data(data) {
                pre = nullptr;
                next = nullptr;
            }
            DLLNode *pre;
            DLLNode *next;
            int data;
        };

        template <typename T>
        class BSTNode {
            public:
            BSTNode(T data): data(data) {
                left = nullptr;
                right = nullptr;
            }
            BSTNode *left;
            BSTNode *right;
            T data;
        };
    }
    template <typename T>
    void print_vec(vector<T>& vec, string prefix="") {
        if (prefix != "")
            cout << prefix << endl;
        for( auto elem : vec ) {
            cout << elem << " " ;
        }
        cout << endl;
    }
}

template <typename T>
void print_vector(const T &vec, string prefix="")
{
    if (prefix != "")
        cout << prefix << endl;
    for(auto v : vec) {
        cout << v << " ";
    }
    cout << flush << endl;
}

template <typename T>
void print_arr(const T &arr, size_t s, string prefix="")
{
    if (prefix != "")
        cout << prefix << endl;
    for(size_t i = 0; i < s; i++) {
        cout << arr[i] << " ";
    }
    cout << flush << endl;
}

template <typename T>
void print_list(const T &l, string prefix = "")
{
    if (prefix != "")
        cout << prefix << endl;
    for (auto it = l.begin(); it != l.end();it++)
    {
        cout << *it << " " ;
    }
    cout << endl;
}

template<typename T>
void print_map(const T& m, string map_name="map", string prefix="")
{
    if (prefix != "")
        cout << prefix << endl;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << map_name << "[" << it->first<< "] = " << it->second << endl;
    }
}
template<typename T>
void print_map2(const T& m, string map_name="map", string prefix="")
{
    if (prefix != "")
        cout << prefix << endl;
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout << map_name << "[" << it->first << "] = ";
        it->second.print();
    }
}

