class Solution {
public:
    bool isValid(string s) {
        
        stack<char> help_stack;

        char c;
        for(int i = 0; i < s.size(); ++i)
        {
            switch(s[i])
            {
                case '(':
                case '{':
                case '[':
                    help_stack.push(s[i]);
                    break;

                case '}':
                    if(help_stack.empty())
                        return false;
                    c = help_stack.top();
                    help_stack.pop();
                    if(c != '{')
                        return false;
                    break;

                case ')':
                    if(help_stack.empty())
                        return false;
                    c = help_stack.top();
                    help_stack.pop();
                    if(c != '(')
                        return false;
                    break;

                case ']':
                    if(help_stack.empty())
                        return false;
                    c = help_stack.top();
                    help_stack.pop();
                    if(c != '[')
                        return false;
                    break;         
            }
        }

        if(help_stack.empty())
            return true;
        else
            return false;
    }
};