#include "common.hpp"
#include <iostream>
#include <memory>
#include "smartptr.hpp"

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

//Using own implementation of smartpointer to check destructor called after out of scope
void scopetester_bst()
{
    SmartPtr<BST<int>> bst_tree1(new BST<int>());
    //BST<int> bst_tree1;
    bst_tree1->insert_node(new BSTNode<int>{5}); 
    bst_tree1->insert_node(new BSTNode<int>{3});
    bst_tree1->insert_node(new BSTNode<int>{2});
    bst_tree1->insert_node(new BSTNode<int>{4});
    bst_tree1->insert_node(new BSTNode<int>{10});
    bst_tree1->insert_node(new BSTNode<int>{8});
    bst_tree1->insert_node(new BSTNode<int>{6});
    bst_tree1->insert_node(new BSTNode<int>{12});
    bst_tree1->insert_node(new BSTNode<int>{14});

    print_bst_pre_order(*bst_tree1);
    int key = 8;

    cout << "searching key " << key << endl; 
    BSTNode<int>* node = bst_tree1->search_key(key);
    if (node){
        cout << "Node for key "<< key <<" found at : " << node;
    } else {
        cout << "Search failed for key : " << key << endl;
    }

    key = 7;

    cout << "searching key " << key << endl; 
    node = bst_tree1->search_key(key);
    if (node){
        cout << "Node for key "<< key <<" found at : " << node;
    } else {
        cout << "Search failed for key : " << key << endl;
    }
}

void tester_bst() 
{
    vector<string> names = {"sundar", "hamsu", "meera", "lalit", "zoan", "karthik", "marco"};
    SmartPtr<BST<string>> name_tree(new BST<string>());
    for (auto name : names) {
        name_tree->insert_node(new BSTNode<string>{name});
    }
    cout << "\n\n" << "Name tree is : " << endl; 
    print_bst_pre_order(*name_tree);

    string name_key = "meera";
    cout << "searching key " << name_key << endl; 
    BSTNode<string>*name_node = name_tree->search_key(name_key);
    if (name_node){
        cout << "Node for name_key "<< name_key <<" found at : " << name_node;
    } else {
        cout << "Search failed for name_key : " << name_key << endl;
    }

    string name_del_key = "lalit";
    name_tree->delete_node(name_del_key);
    print_bst_pre_order(*name_tree);   
}

//Using own implementation of smartpointer to check destructor called after out of scope
void scopetester_using_unique_ptr()
{
    unique_ptr<BST<int>> bst_tree1(new BST<int>());
    //BST<int> bst_tree1;
    bst_tree1->insert_node(new BSTNode<int>{5}); 
    bst_tree1->insert_node(new BSTNode<int>{3});
    bst_tree1->insert_node(new BSTNode<int>{2});
    bst_tree1->insert_node(new BSTNode<int>{4});
    bst_tree1->insert_node(new BSTNode<int>{10});
    bst_tree1->insert_node(new BSTNode<int>{8});
    bst_tree1->insert_node(new BSTNode<int>{6});
    bst_tree1->insert_node(new BSTNode<int>{12});
    bst_tree1->insert_node(new BSTNode<int>{14});

    print_bst_pre_order(*bst_tree1);
    int key = 8;

    cout << "searching key " << key << endl; 
    BSTNode<int>* node = bst_tree1->search_key(key);
    if (node){
        cout << "Node for key "<< key <<" found at : " << node;
    } else {
        cout << "Search failed for key : " << key << endl;
    }

    key = 7;

    cout << "searching key " << key << endl; 
    node = bst_tree1->search_key(key);
    if (node){
        cout << "Node for key "<< key <<" found at : " << node;
    } else {
        cout << "Search failed for key : " << key << endl;
    }
}

void test_bst_all() {
    scopetester_bst();
    scopetester_using_unique_ptr();
    tester_bst();
}

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



