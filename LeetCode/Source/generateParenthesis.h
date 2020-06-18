class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        if(n == 0)
            return result;
        
        process(n, n, 0, string());
        return result;
    }

    void process(int leftn, int rightn, int current_left, string current_str)
    {
        if(leftn == 0 && rightn == 0)
        {
            result.push_back(current_str);
            return;
        }

        if(current_left == 0)
        {
            current_str.push_back('(');
            process(leftn - 1, rightn, current_left + 1, current_str);
            current_str.pop_back();
        }
        else
        {
            if(leftn == 0)
            {
                current_str.push_back(')');
                process(leftn, rightn - 1, current_left - 1, current_str);
                current_str.pop_back();
            }
            else
            {
                current_str.push_back(')');
                process(leftn, rightn - 1, current_left - 1, current_str);
                current_str.pop_back();

                current_str.push_back('(');
                process(leftn - 1, rightn, current_left + 1, current_str);
                current_str.pop_back();
            }
        }

    }
};