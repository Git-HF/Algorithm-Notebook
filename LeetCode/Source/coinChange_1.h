class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp = vector<int>(amount+1, -2);
        dp[0] = 0;
        process(coins, amount);
        return dp[amount];
    }

    int process(vector<int> & coins, int amount)
    {
        if(amount < 0)
            return -1;
        else if(amount == 0)
            return 0;
        
        // 官方代码中，这种dp数组的标志只使用三种，-1，0，>=0，因为dp[0]的时候不使用dp数组的结果，直接返回。
        if(dp[amount] >= -1)
            return dp[amount];

        int min = -1;
        for(int i = 0; i < coins.size(); ++i)
        {
            int cur = process(coins, amount - coins[i]);
            if(cur != -1)
            {
                if(min == -1 || min > cur+1)
                    min = cur+1;
            }
        }

        dp[amount] = min;
        return min;
    }
};