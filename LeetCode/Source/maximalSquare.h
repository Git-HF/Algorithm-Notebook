class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;

        vector<vector<int>> dp = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0));

        int max = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(matrix[i][j] == '1')
                {
                    if(i == 0 || j == 0)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        // 状态可以这样转移的原因。
                        dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                    }

                    max = std::max(max, dp[i][j]);
                }
            }
        }

        return max*max;
    }
};