#ifndef MY_STACK_H
#define MY_STACK_H

#include <vector>
#include <cassert>

using std::vector;

class MyStack
{
    private:
        vector<int> m_data;
        int m_index = 0;
    
    public:
        explicit MyStack(int size)
        { 
            assert(size>=0);
            m_data = vector<int>(size);
        }

        void push(int num)
        {
            assert(m_index < m_data.size());
            m_data[m_index++] = num;
        }

        int pop()
        {
            assert(m_index > 0);
            return m_data[--m_index];
        }

        int peek()
        {
            assert(m_index > 0);
            return m_data[m_index-1];
        }
};
#endif