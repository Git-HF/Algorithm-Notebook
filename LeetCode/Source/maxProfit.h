class Solution {
public:
    int maxProfit(vector<int>& prices) {

        if(prices.size() < 2)
            return 0;
        
        int min = prices[0];
        int max = -1;
        for(int i = 0; i < prices.size(); ++i)
        {
            // 可以利用min和max函数。
            if(prices[i] < min)
                min = prices[i];
            prices[i] -= min;
            max = (max < prices[i]) ? prices[i] : max;
        }

        return max;
    }
};