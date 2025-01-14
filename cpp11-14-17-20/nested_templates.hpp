#pragma once
#include <bits/stdc++.h>
#include <initializer_list>
using namespace std;

namespace AshokProgramming {

template <class T>
class Ring {
    size_t m_pos;
    T *m_values;
    size_t m_size;
    public:
        Ring(size_t size): m_size(size), m_values(nullptr), m_pos(0) {
            m_values = new T[m_size];
        }
        class iterator;
        void add(T val) {
            m_values[m_pos++] = val;
            if(m_pos == m_size){
                m_pos = 0;
            }           
        }
        void add(initializer_list<T> l)
        {
            for(auto val:l) {
                add(val);
            }
        }

        auto get(size_t pos) -> decltype(m_values[pos])
        {
            return m_values[pos];
        }
        ~Ring()
        {
            delete [] m_values;
        }
        size_t size()
        {
            return m_size;
        }
        iterator begin()
        {
            return iterator(0, *this);
        }
        iterator end()
        {
            return iterator(m_size, *this);
        }
};

template <class T>
class Ring<T>::iterator {
private:
    size_t m_pos;
    Ring &m_ring;

public:
    iterator(size_t pos, Ring &aring) : m_pos(pos), m_ring(aring)
    {
    }
    bool operator!=(const iterator &other) const
    {
        return m_pos != other.m_pos;
    }
    iterator& operator++(int)
    {
        m_pos++;
        return *this;
    }
    iterator& operator++()
    {
        m_pos++;
        return *this;
    }
    T &operator*()
    {
        return m_ring.get(m_pos);
    }

};



}//namespace AshokProgramming 

using namespace AshokProgramming;

void test_nested_templates()
{
    Ring<string> textring(3);

    textring.add("one");
    textring.add("two");
    textring.add("three");
    textring.add("four");
    textring.add("five");
    textring.add("six");
    textring.add({"eight", "nine", "eleven"});

    for (Ring<string>::iterator it = textring.begin(); it != textring.end(); it++) {
        cout << *it << endl;        
    }

    cout << endl;
    for (auto text:textring) {
        cout << text << endl;
    }

}

