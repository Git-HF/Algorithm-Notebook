class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> help;
        help.push(-1);
        int max = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
                help.push(i);
            else
            {
                help.pop();
                if(help.empty())
                {
                    help.push(i);
                }
                else
                {
                    max = std::max(max, i - help.top());
                }
            }
        }

        return max;
    }
};