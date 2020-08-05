class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        if(amount == 0)
            return 0;

        vector<int> dp(amount+1, 0);
        for(int i = 1; i <= amount; ++i)
        {
            int cur = INT_MAX;
            for(int j = 0; j < coins.size(); ++j)
            {
                if(i >= coins[j] && dp[i - coins[j]] != -1)
                    cur = std::min(cur, dp[i - coins[j]]);
            }

            if(cur == INT_MAX)
                dp[i] = -1;
            else
            {
                dp[i] = cur + 1;
            }
        }

        return dp[amount];
    }
};