class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        map<char, int> help;
        int pre = -1;
        int cur = 0;
        int max = 0;
        while(cur < s.size())
        {
            auto iter = help.find(s[cur]);
            if(iter == help.end())
            {
                help[s[cur]] = cur;
                max = std::max(max, cur - pre);
                ++cur;
            }
            else
            {
                int new_pre = help[s[cur]];
                // 判断条件里必须使用new_pre，不能使用help[s[cur]]，否则最后一个元素删除后会出错
                for(int i = pre + 1; i <= new_pre; ++i)
                {
                    auto tmp_ite = help.find(s[i]);
                    help.erase(tmp_ite);
                }
                pre = new_pre;
                help[s[cur]] = cur;
                ++cur;
            }
        }

        return max;
    }
};