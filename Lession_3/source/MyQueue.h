#ifndef MY_QUEUE_H
#define MY_QUEUE_H

#include <vector>
#include <cassert>

using std::vector;

class MyQueue
{
    private:
        vector<int> m_data;
        int m_size = 0;
        int m_front = 0;
        int m_rear = 0;
    
    public:
        explicit MyQueue(int capacity)
        {
            assert(capacity >= 0);
            m_data = vector<int>(capacity);
        }

        void push(int num)
        {
            assert(m_size < m_data.size());
            m_data[m_rear] = num;
            m_rear = (m_rear + 1) % m_data.size();
            ++m_size;
        }

        int pop()
        {
            assert(m_size > 0);
            int tmp = m_data[m_front];
            m_front = (m_front + 1) % m_data.size();
            --m_size;
            return tmp;
        }

        int peek() const
        {
            assert(m_size > 0);
            return m_data[m_front];
        }

};
#endif