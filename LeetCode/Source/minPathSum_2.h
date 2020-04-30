class Solution {
public:

    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        dp = vector<vector<int>>(grid.size(), vector<int>(grid[0].size(), -1));

        for(int i = dp.size() - 1; i >= 0; --i)
            for(int j = dp[0].size() - 1; j >= 0; --j)
            {
                if(i == dp.size() - 1 && j == dp[0].size() - 1)
                    dp[i][j] = grid[i][j];
                else if(i == dp.size() - 1)
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                else if(j == dp[0].size() - 1)
                    dp[i][j] = grid[i][j] + dp[i+1][j];
                else
                    dp[i][j] = grid[i][j] + (dp[i+1][j] < dp[i][j+1] ? dp[i+1][j] : dp[i][j+1]);
            }
        
        return dp[0][0];

        return 0;
    }
};