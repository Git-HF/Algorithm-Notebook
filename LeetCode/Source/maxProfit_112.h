class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;

        vector<vector<int>> dp = vector<vector<int>>(prices.size(), vector<int>(2));
        // 注意初始化条件的原由
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]+prices[i]);
            // 注意这里不是std::max(dp[i-1][1], dp[i-1][0]-prices[i]),因为只允许购买一次股票，所以
            //如果上次不持有股票，则一定是未进行股票买卖，所以收益一定是0
            dp[i][1] = std::max(dp[i-1][1], -prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};