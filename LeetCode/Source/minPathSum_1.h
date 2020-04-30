class Solution {
public:

    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        for(int i = 0; i < grid.size(); ++i)
        {
            dp.push_back(vector(grid[0].size(), -1));
        }

        return process(grid, 0, 0);
    }

    int process(const vector<vector<int>> & grid, int row, int col)
    {
        if(dp[row][col] != -1)
                return dp[row][col];

        if(row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];
        else
        {
            if(row == grid.size() - 1)
            {
                dp[row][col] = grid[row][col] + process(grid, row, col+1);
            }

            else if(col == grid[0].size() - 1)
            {
                dp[row][col] = grid[row][col] + process(grid, row+1, col);
            }

            else
            {
                int down = process(grid, row + 1, col);
                int right = process(grid, row, col + 1);
                dp[row][col] = (down < right) ? down + grid[row][col] : right + grid[row][col];
            }

            return dp[row][col];
        }
    }
};