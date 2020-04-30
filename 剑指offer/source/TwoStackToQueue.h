class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    //未处理两个栈都为空的异常情况
    int pop() {
        assert((!stack1.empty()) || (!stack2.empty()));
        int value;
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        value = stack2.top();
        stack2.pop();
        return value;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};