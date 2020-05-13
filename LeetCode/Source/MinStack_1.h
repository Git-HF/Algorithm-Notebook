class Solution {
public:
    void push(int value) {
        s.push(value);
        if(sMin.empty())
            sMin.push(value);
        else if(value <= sMin.top())
            sMin.push(value);
    }
    void pop() {
        if(s.top() == sMin.top())
            sMin.pop();
        s.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return sMin.top();
    }
private:
    stack<int> s;
    stack<int> sMin;
};