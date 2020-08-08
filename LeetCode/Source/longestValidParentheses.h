class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> help;
        int left = 0;
        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == '(')
            {
                help.push(0);
                ++left;
            }
            else
            {
                if(left == 0)
                {
                    help.push(1);
                }
                else
                {
                    int sum = 0;
                    while(help.top() != 0)
                    {
                        sum += help.top();
                        help.pop();
                    }
                    help.pop();
                    --left;
                    sum += 2;
                    help.push(sum);
                }
            }
        }

        int max = 0;
        int cur = 0;
        while(!help.empty())
        {
            if(help.top() >= 2)
            {
                cur += help.top();
                max = std::max(max, cur);
            }
            else
            {
                cur = 0;
            }

            help.pop();
        }
        return max;   
    }
};