class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        
        return process(grid, 0, 0);
    }

    int process(const vector<vector<int>> & grid, int row, int col)
    {
        if(row == grid.size() - 1 && col == grid[0].size() - 1)
            return grid[row][col];
        else
        {
            if(row == grid.size() - 1)
                return grid[row][col] + process(grid, row, col+1);
            else if(col == grid[0].size() - 1)
                return grid[row][col] + process(grid, row + 1, col);
            else
            {
                int down = process(grid, row + 1, col);
                int right = process(grid, row, col + 1);
                return (down < right) ? down + grid[row][col] : right + grid[row][col];
            }
        }
    }
};