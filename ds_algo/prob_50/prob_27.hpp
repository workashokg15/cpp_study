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


template <typename T>
class TestHeap {
    int m_size{0};
    T* m_heap{nullptr};
    int m_heap_end{0};
public:
    TestHeap() = delete;
    TestHeap(int size) : m_size(size) {
        m_heap = new int[m_size]{};
        //fill(m_heap, m_heap + 19, -1);
    }
    TestHeap(const TestHeap &other) = delete;
    TestHeap(const TestHeap &&other) = delete;
    TestHeap& operator=(const TestHeap &other) = delete;
    TestHeap& operator=(const TestHeap &&other) = delete;
    ~TestHeap()
    {
        cout << "destructor called" << endl;
        delete [] m_heap;
        m_heap = nullptr;
    }

    int left_child(const int index) const{
        return index * 2;
    }

    int right_child(const int index) const{
        return (index * 2) + 1;
    }

    int parent(const int index) const
    {
        return (index - 1)/2;
    }

    void rearrange_heap(int index)
    {
        //print_heap("===>rearrange");
        if(index > 0) {
            int parent_index = parent(index);
             if(m_heap[index] > m_heap[parent_index]) {
                swap(m_heap[index], m_heap[parent_index]);    
            }
            rearrange_heap(index-1);
        }
        //print_heap("<===rearrange");
    }

    bool insert(T val) {
        if(m_heap_end == m_size)
            return false;
        m_heap[m_heap_end] = val;
        rearrange_heap(m_heap_end);
        m_heap_end += 1;
        return true;
    }

    int get() {
        if (m_heap_end == -1)
            return -1;
        int ret = m_heap[0];
        m_heap_end -= 1;
        m_heap[0] = m_heap[m_heap_end];
        rearrange_heap(m_heap_end);
        return ret;
    }    

    void print_heap(string prefix="")
    {
        if(prefix != "")
            cout << prefix << " : " << flush << endl;
        for (int i = 0; i < m_heap_end; i++) {
            cout << m_heap[i] << flush << " ";
        }
    }
};

void test_heap()
{
    const int heap_size{50};
    TestHeap<int> th{heap_size};
    for(int i = 0; i < heap_size + 3; i++) {
        if (th.insert(rand()%99)) {

        } else {
            cout << "breaking cannot insert more" << endl;
            break;
        }
    }
    th.print_heap();
    cout << "\ngetting : " << th.get() << endl;
    cout << "\ngetting : " << th.get() << endl;
    cout << "\ngetting : " << th.get() << endl;
    cout << "\ngetting : " << th.get() << endl;
    cout << "\ngetting : " << th.get() << endl;
    th.print_heap();
}

void permute_helper(char *arr, int index, int size, int j)
{
    if(index == size) {
//        cout << "("<< j << ":" << index << ":" << size << ")" << endl;

        cout << arr << endl;
    } else {
        for (int i = index; i < size; i++) {
            swap(arr[index], arr[i]);
            //cout << "B("<< i << ":" << index << ":" << size << ")" << endl;
            permute_helper(arr, index + 1, size, i);
            //backtrack
            //cout << "A("<< i << ":" << index << ":" << size << ")" << endl;
            swap(arr[index], arr[i]);
        }
    }
}

void test_permute()
{
    char arr[4] = {'a', 'b', 'c', 0};
    permute_helper(arr, 0, (sizeof(arr)/sizeof(arr[0])-1), 0);
}

int pivot(vector<int>& v, int pivot_index, int end_index)
{
    int swap_index = pivot_index;
    for (int i = pivot_index + 1; i < end_index; i++) {
        if(v[i] < v[pivot_index]) {
            swap_index++;
            swap(v[swap_index], v[i]);
        }
    }
    swap(v[pivot_index], v[swap_index]);
    return swap_index;
}

void quick_sort(vector<int> &v, int left_index, int right_index)
{
    if(left_index >= right_index)
        return;
    int pivot_index = pivot(v, left_index, right_index);
    cout << "Q_after_P(" << pivot_index << "," << 
    left_index << "," << right_index << endl;
    getchar();
    quick_sort(v, left_index, pivot_index);
    quick_sort(v, pivot_index + 1, right_index);
}


void test_quick_sort()
{
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(rand()%99);
    }    
    cout << "before sort" << endl;
    for (auto val:v) {
        cout << val << " ";
    }
    cout << endl;
    
    quick_sort(v, 0, v.size());
    cout << "after sort" << endl;
    for (auto val:v) {
        cout << val << " ";
    }
    cout << endl;
}



void test_dynamic_programming()
{

}