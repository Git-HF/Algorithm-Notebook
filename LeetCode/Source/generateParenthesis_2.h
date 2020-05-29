class Solution {
public:
    vector<string> generateParenthesis(int n) {

        if(n == 0)
            return vector<string>();

        vector<vector<string>> dp(n + 1, vector<string>());
        dp[0].push_back("");
        dp[1].push_back("()");

        vector<string> tmp;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 0; j < i; ++j)
            {
                string s1 = "(";
                for(auto item : dp[j])
                {
                    string s2 = s1 + item + ")";
                    for(auto end : dp[i - j - 1])
                    {
                        string s3 = s2 + end;
                        dp[i].push_back(s3);

                    }
                }
            }
        }

        return dp[n];
    }
};