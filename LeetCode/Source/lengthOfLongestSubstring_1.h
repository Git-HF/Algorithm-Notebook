class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() <= 1)
            return s.size();

        unordered_set<char> help;
        int left = 0, right = 0;
        int max = 1;
        while(left < s.size() && right < s.size())
        {
            help.insert(s[left]);
            while(right < s.size())
            {
                // left == right条件不能丢，否则两个相邻的字符无法判断出来
                if(left == right ||help.count(s[right]) == 0)
                {
                    help.insert(s[right]);
                    max = std::max(max, right - left + 1);
                    ++right;
                }
                else
                {
                    break;
                }
            }
            
            auto iter = help.find(s[left]);
            help.erase(iter);
            ++left;
        }

        return max;
    }
};