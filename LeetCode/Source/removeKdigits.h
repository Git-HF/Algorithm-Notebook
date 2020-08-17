class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> help;
        int index = 0;
        while(index < num.size())
        {
            if(help.empty() || help.back() <= num[index])
            {
                help.push_back(num[index++]);
            }
            else
            {
                while(!help.empty() && help.back() > num[index] && k > 0)
                {
                    help.pop_back();
                    --k;
                }
                help.push_back(num[index++]);
            }
            
        }

        while(k > 0)
        {
            help.pop_back();
            --k;
        }

        while(!help.empty() && help.front() == '0')
        {
            help.pop_front();
        }

        if(help.empty())
            return "0";
        else
            return string(help.begin(), help.end());

        // 注意，这里不能将string转换为整数，然后返回，因为数字会溢出
        //return to_string(stoi(res));
    }
};