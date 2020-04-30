class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        if(grid.size() == 0)
            return 0;

        vector<vector<int>> help_grid;
        for(int i = 0; i < grid.size(); ++i)
        {
            help_grid.push_back(vector<int>(grid[0].size(), -1));
        }

        int width = grid[0].size();
        int heigh = grid.size();
        int count = 0;
        for(int i = 0; i < grid.size(); ++i)
            for(int j = 0; j < grid[0].size(); ++j)
            {
                if(help_grid[i][j] == -1 && grid[i][j] == '1')
                {
                    ++count;
                    process(grid, help_grid, width, heigh, i, j, i*width+j);
                }
            }
        return count;
    }

    void process(const vector<vector<char>>& grid, vector<vector<int>>& help_grid, int width, int hight, int row, int col, int father)
    {
        if(grid[row][col] == '0' || help_grid[row][col] != -1)
            return;
        else
        {
            help_grid[row][col] = father;
            if(row + 1 < hight)
                process(grid, help_grid, width, hight, row+1, col, father);
            if(col + 1 < width)
                process(grid, help_grid, width, hight, row, col+1, father);
            
            // 必须四个方向都判断，否则会有少判的情况
            // 比如测试案例{ {'1', '1', '1'}, {'0', '1', '0'}, {'1', '1', '1'}}，元素grid[2][0]将会误判
            if(col - 1 >= 0)
                process(grid, help_grid, width, hight, row, col-1, father);
            if(row - 1 >= 0)
                process(grid, help_grid, width, hight, row-1, col, father);
        }
    }
};