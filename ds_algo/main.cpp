#include "bst.hpp"
#include "smartptr.hpp"
#include <iostream>
#include <vector>

using namespace std;
using namespace common::ds_algo;

void scopetester()
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

int main()
{
    cout << "BST impl example" << endl;

    scopetester();

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
 
    return 0;
}