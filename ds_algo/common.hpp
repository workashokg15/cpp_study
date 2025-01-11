#pragma once
#include <vector>
#include <iostream>
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