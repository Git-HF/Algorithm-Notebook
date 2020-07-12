class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp = vector<vector<bool>>(s.size(), vector<bool>(s.size(), false));

        int ans = 0;

        for(int i = 0; i < s.size(); ++i)
        {
            dp[i][i] = true;
        }

        ans += s.size();

        // 必须从最后一行开始判断，因为dp[i][j]依赖下一行的dp[i+1][j-1]，所以只能从最后一行开始。
        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i+1; j < s.size(); ++j)
            {
                if(s[i] == s[j])
                {
                    if(j == i + 1)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i+1][j-1];
                }
                else
                    dp[i][j] = false;

                if(dp[i][j])
                    ++ans;
            }
        }
        return ans;
    }
};