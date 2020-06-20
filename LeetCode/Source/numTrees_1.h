class Solution {
public:

    vector<vector<int>> dp;
    int numTrees(int n) {

        for(int i = 0; i < n+1; ++i)
        {
            dp.push_back(vector<int>(n+1, -1));
        }

        int sum = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(dp[n][i] == -1)
                dp[n][i] = process(n, i);
            sum += dp[n][i];
        }
        
        return sum;
    }

    int process(int n, int index)
    {
        if(n == 1 || n == 0)
            return 1;
        
        int left = 0;
        for(int i = 1; i < index; ++i)
        {
            if(dp[index-1][i] == -1)
                dp[index-1][i] = process(index-1, i);
            left += dp[index-1][i];
        }

        int right = 0;
        for(int j = 1; j <= (n - index); ++j)
        {
            if(dp[n-index][j] == -1)
                dp[n-index][j] = process(n-index, j);
            right += dp[n-index][j];
        }

        if(left == 0)
            return right;
        else if(right == 0)
            return left;
        else
            return left * right;
    }
};