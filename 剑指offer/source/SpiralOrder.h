class Solution {
public:
    //leftTopRow, leftTopCol分别表示左上角的行和列；
    //rightBottomRow, rightBottomCol分别表示右下角的行和列。
    vector<int> process(const vector<vector<int> > &matrix, int leftTopRow, int leftTopCol, int rightBottomRow, int rightBottomCol)
    {
        vector<int> result;
        if((leftTopRow > rightBottomRow) || (leftTopCol > rightBottomCol))
            return result;
        int row = leftTopRow, col = leftTopCol;
        
        if(row == rightBottomRow)
        {
            while(col <= rightBottomCol)
            {
                result.push_back(matrix[row][col++]);
            }
            return result;
        }
        else if(col == rightBottomCol)
        {
            while(row <= rightBottomRow)
                result.push_back(matrix[row++][col]);
            return result;
        }
        
        while(col < rightBottomCol)
        {
            result.push_back(matrix[row][col++]);
        }
        
        while(row < rightBottomRow)
        {
            result.push_back(matrix[row++][col]);
        }
        
        while(col > leftTopCol)
        {
            result.push_back(matrix[row][col--]);
        }
        
        while(row > leftTopRow)
        {
            result.push_back(matrix[row--][col]);
        }
        
        vector<int> tmp = process(matrix, leftTopRow+1, leftTopCol+1, rightBottomRow-1, rightBottomCol-1);
        std::copy(tmp.begin(), tmp.end(), std::back_inserter(result));
        return result;
    }
    
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
              return vector<int>();
        return process(matrix, 0, 0, matrix.size() - 1, matrix[0].size() - 1);
    }
    
    
};