class Solution {
public:
    string convert(string s, int numRows) {
        

        // 注意numRows == 1时的特判。
        if(numRows == 1)
            return s;

        vector<string> res = vector<string>(numRows, "");
        int cur = 0;
        // flag 初始化为false,而不是true
        bool flag = false;
        for(int i = 0; i < s.size(); ++i)
        {
            res[cur].push_back(s[i]);
            if(cur == 0 || cur == numRows-1)
            {
                flag = !flag;
            } 

            if(flag)
                ++cur;
            else 
                --cur;
        }

        string ans = "";
        for(int i = 0; i < numRows; ++i)
        {
            ans +=  res[i];
        }
        return ans;
    }
};