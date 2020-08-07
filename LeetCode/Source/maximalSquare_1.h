class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int max_length = 0;
        for(int i = 0; i < matrix.size(); ++i)
        {
            for(int j = 0; j < matrix[0].size(); ++j)
            {
                if(matrix[i][j] == '1')
                {
                    int lenght = 2;
                    while(isSquare(matrix, i, j, lenght))
                    {
                        ++lenght;
                    }
                    max_length = std::max(max_length, lenght-1);
                }
            }
        }
        return max_length*max_length;
    }

    // 注意参数传递不要出错，top和left位置不要错了
    bool isSquare(vector<vector<char>>& matrix, int top, int left, int lenght)
    {
        int right = left + lenght -1;
        int bottom = top+lenght-1;

        if(bottom >= matrix.size())
            return false;
        if(right >= matrix[0].size())
            return false;

        for(int i = top; i <= bottom; ++i)
        {
            if(matrix[i][right] == '0')
                return false;
        }

        for(int i = left; i <= right; ++i)
        {
            if(matrix[bottom][i] == '0')
                return false;
        }
        return true;
    }
};