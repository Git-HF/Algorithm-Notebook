class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n+1, n);
        int max_index = (int)sqrt(n) + 1;
        vector<int> thres(max_index + 1);
        for(int i = 1; i <= max_index; ++i)
        {
            thres[i] = i * i;
        }
        dp[0] = 0;

        //这里必须从1开始计算，因为不使用递归的形式，无法知道应该计算之前的哪些数，所以只能全部都计算。
        for(int i = 1;i <= n; ++i)
        {
            for(int index = 1; index <= max_index; ++index)
            {
                if(i < thres[index])
                    break;
                dp[i] = std::min(dp[i], dp[i - thres[index]] + 1);
            }
        }

        return dp[n];
    }
};