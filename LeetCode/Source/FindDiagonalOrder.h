class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return result;
        
        int leftBottomRow = 0, leftBottomCol = 0;
        int rightTopRow = 0, rightTopCol = 0;

        bool flag = false;
        while(leftBottomCol <= matrix[0].size())
        {
            if(flag)
            {
                int i = rightTopRow, j = rightTopCol;
                while(i <= leftBottomRow)
                {
                    result.push_back(matrix[i][j]);
                    ++i;
                    --j;
                }
            }
            else
            {
                int i = leftBottomRow, j = leftBottomCol;
                while(i >= rightTopRow)
                {
                    result.push_back(matrix[i][j]);
                    --i;
                    ++j;
                }
            }

            flag = !flag;
            if(rightTopCol < matrix[0].size() - 1)
                ++rightTopCol;
            else
                ++rightTopRow;
            
            if(leftBottomRow < matrix.size() - 1)
                ++leftBottomRow;
            else
                ++leftBottomCol;
        }

        return result;

    }
};