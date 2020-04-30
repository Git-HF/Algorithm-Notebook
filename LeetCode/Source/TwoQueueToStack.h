class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        dataQueue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(dataQueue.size() > 1)
        {
            helpQueue.push(dataQueue.front());
            dataQueue.pop();
        }

        int tmp = dataQueue.front();
        dataQueue.pop();

        std::swap(dataQueue, helpQueue);
        return tmp;
    }
    
    /** Get the top element. */
    int top() {
        while(dataQueue.size() > 1)
        {
            helpQueue.push(dataQueue.front());
            dataQueue.pop();
        }

        int tmp = dataQueue.front();
        dataQueue.pop();

        helpQueue.push(tmp);
        std::swap(dataQueue, helpQueue);
        return tmp;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return dataQueue.empty();
    }

private:
    queue<int> dataQueue;
    queue<int> helpQueue;
};