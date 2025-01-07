#include "common.hpp"
#include <iostream>

using namespace std;
using namespace common::ds_algo;

//Compile with 
// g++ -g -fsanitize=address -o bst bst.cpp
//to find memory leaks

template <typename T>
class BST {
public:
    BST() : root(nullptr) {}
    void insert_node(BSTNode<T> *bstnode)
    {
        insert_node(root, bstnode);
    }
    void delete_node(T key)
    {
        delete_node(root, key);
    }
    BSTNode<T>* search_key(T key)
    {
        return search_key(root, key);    
    }

    ~BST() {
        //do post order traversal and delete all leaf nodes.
        delete_all_nodes(root);        
    }

    void delete_all_nodes(BSTNode<T>* node)
    {
        if(node == nullptr)
            return;
        delete_all_nodes(node->left);
        delete_all_nodes(node->right);
        cout << "deleting node : " << node->data << endl;
        delete(node);
    }
    template <typename U>
    friend void print_bst_pre_order(const BST<U> &bst);
private:
    BSTNode<T> *root;

    BSTNode<T>* mininum_node(BSTNode<T> *node)
    {
        while(node->left) {
            node = node->left;
        }
        return node;
    }

    BSTNode<T>* delete_node(BSTNode<T> *node,  T key)
    {
        if(node == nullptr) {
            return node;
        }
        if(key < node->data)
            node->left = delete_node(node->left, key);
        else if(key > node->data)
            node->right = delete_node(node->right, key);
        else {
            BSTNode<T>*temp;
            if(node->left == nullptr) {
                temp = node->right;
                delete node;
                return temp;

            }
            if(node->right == nullptr){
                temp = node->left;
                delete node;
                return temp;
            }
            temp = mininum_node(node->right);
            node->data = temp->data;
            node->right = delete_node(node->right, temp->data);
            return node;
        }
        return node;
    }

    BSTNode<T>* search_key(BSTNode<T> *node,  T key)
    {
        if(node == nullptr) {
            return nullptr;
        }
        if(key < node->data) {
            return search_key(node->left, key);
        } else if (key > node->data) {
            return search_key(node->right, key);
        } else {
            return node;
        }
    }


    void insert_node(BSTNode<T> *current, BSTNode<T> *bstnode)
    {
        if(root == nullptr) {
            root = bstnode;
            return;
        }
        if(current->data > bstnode->data) {
            if(current->left != nullptr) {
                return insert_node(current->left, bstnode);
            }
            cout << "inserting to left of : " << current->data << " <<== " << bstnode->data << endl;
            current->left = bstnode;
            return;
        } else {
            if(current->right != nullptr) {
                return insert_node(current->right, bstnode);
            }
            cout << "inserting to right of : " << current->data << " ==>> " << bstnode->data << endl;
            current->right = bstnode;
            return;
        }
        return insert_node(current->right, bstnode);
    }
};

template <typename T>
void print_bst_pre_order(const BSTNode<T> *bstnode)
{
    if(bstnode == nullptr) {
        return;
    }
    cout << bstnode->data << " ";
    print_bst_pre_order(bstnode->left);
    print_bst_pre_order(bstnode->right);
}


template <typename T>
void print_bst_pre_order(const BST<T> &bst)
{   
    const BSTNode<T>* bstnode = bst.root;
    print_bst_pre_order(bstnode);
}



