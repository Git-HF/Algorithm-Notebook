class Solution {
public:
    string decodeString(string s) {

        // 栈的元素使用string，而不是char
        stack<string> sta;
        // 次数栈
        stack<int> int_sta;

        for(int i = 0; i < s.size(); ++i)
        {
            if(s[i] == ']')
            {
                // 统计需要重复的字符串
                string str = "";
                while(sta.top() != "[")
                {
                    str = sta.top() + str;
                    sta.pop();
                }
                sta.pop();

                //解码完毕，重新放回栈中，因为外层可能还有括号
                string cur_str = str;
                for(int i = 1; i < int_sta.top(); ++i)
                {
                    cur_str += str;
                }
                sta.push(cur_str);
                int_sta.pop();
            }
            else if(s[i] >= '0' && s[i] <= '9')
            {
                int j = i + 1;
                while(s[j] >= '0' && s[j] <= '9')
                {
                    ++j;
                }

                int_sta.push(stoi(string(s.begin() + i, s.begin() + j)));
                i = j-1;
            }
            else
            {
                //为了将char转化为string
                sta.push(string() + s[i]);
            }
        }

        string ans;
        while(!sta.empty())
        {
            ans = sta.top() + ans;
            sta.pop();
        }

        return ans;
    }


};