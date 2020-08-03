class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1)
            return 0;

        vector<vector<int>> dp = vector<vector<int>>(prices.size(), vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]+prices[i]);
            // 注意这里是std::max(dp[i-1][1], dp[i-1][0]-prices[i]),因为交易次数没有上限，
            //所以之前可能已经购买了股票，并且卖出了。
            //注意和第一天的区别
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[prices.size()-1][0];
    }
};