class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() == 0)
            return 0;
        
        vector<vector<int>> dp = vector<vector<int>>(prices.size() + 1, vector<int>(3, 0));

        dp[0][0] = -prices[0];

        for(int i = 0; i < prices.size(); ++i)
        {
            dp[i+1][0] = std::max(dp[i][0], dp[i][2] - prices[i]);
            dp[i+1][1] = dp[i][0] + prices[i];
            dp[i+1][2] = std::max(dp[i][1], dp[i][2]);
        }

        return std::max(dp[prices.size()][1], dp[prices.size()][2]);
    }
};