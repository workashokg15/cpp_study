#include <bits/stdc++.h>
void run_prob_27();
//K-Sorted linked list

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {head = this;}
    ListNode(int x) : val(x), next(nullptr) {head = this;}
    ListNode(int x, ListNode *next) : val(x), next(next) {head = this;}
private:
    ListNode *head;
};

void print_list_node(ListNode *head, string prefix)
{
    if (prefix != "")
        cout << prefix << endl;
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode * merge_two_lists(ListNode *head1, ListNode *head2)
    {
        ListNode *dummy = new ListNode(-1);
        ListNode *curr = dummy;
        //print_list_node(dummy, "recurse print: ");
        while(head1 != nullptr && head2 != nullptr) {
            if(head1->val <= head2->val) {
                curr->next = head1;
                head1 = head1->next;                                                                                                                                                                                                                                                                                                                                                                                                                       
            } else  {
                curr->next = head2;
                head2 = head2->next;                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
            }
            curr = curr->next;    
        }    
        if(head1 != nullptr) {
            curr->next = head1;
        } else {
            curr->next = head2;
        }
        curr = dummy->next;
        //print_list_node(curr,"press key to recurse");
        //getchar();
        delete(dummy);
        dummy = nullptr;
        return curr;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode *res = nullptr;
        for(auto node : lists) 
        {
            res = merge_two_lists(res, node);
        }   
        return res;
    }
};

void run_prob_27()
{
    Solution s;
    ListNode * n1 = new ListNode{1, nullptr};
    n1->next = new ListNode{3, nullptr};
    n1->next->next = new ListNode{5, nullptr};
    ListNode *n2 = new ListNode();
    ListNode *n3 = new ListNode{1, nullptr};
    n3->next = new ListNode{8, nullptr};
    n3->next->next = new ListNode{18, nullptr};
    vector<ListNode *> vln= {n1, n2, n3};
    ListNode* mr = s.mergeKLists(vln);
    //print_list_node(mr, "sorted list is : ");
    print_list_node(mr, "");
    ListNode *temp = mr;
    while(mr) {
        temp = mr->next;
        delete(mr);
        mr = temp;
    }
}