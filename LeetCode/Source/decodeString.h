class Solution {
public:
    string decodeString(string s) {

        // 栈的元素使用string，而不是char
        stack<string> sta;

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

                //计算重复次数
                int count = 0;
                int times = 1;
                while((!sta.empty()) && (sta.top()[0] >= '0') && (sta.top()[0] <= '9'))
                {
                    count += (sta.top()[0] - '0') * times;
                    sta.pop();
                    times *= 10;
                }

                //解码完毕，重新放回栈中，因为外层可能还有括号
                string cur_str = str;
                for(int i = 1; i < count; ++i)
                {
                    cur_str += str;
                }
                sta.push(cur_str);
            }
            else
            {
                //为了将char转化为string
                //sta.push(string(1, s[i]));
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