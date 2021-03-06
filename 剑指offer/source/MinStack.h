class Solution {
private:
    stack<int> dataStack;
    stack<int> minStack;
public:
    void push(int value) {
        dataStack.push(value);
        if(minStack.empty())
        {
            minStack.push(value);
        }else
        {
            minStack.push((value < minStack.top())? value : minStack.top());
        }
    }
    void pop() {
        dataStack.pop();
        minStack.pop();
        
    }
    int top() {
        return dataStack.top();
    }
    int min() {
        return minStack.top();
    }
};