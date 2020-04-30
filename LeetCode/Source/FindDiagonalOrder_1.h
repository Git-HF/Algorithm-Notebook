class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return {};
        int M = matrix.size();
        int N = matrix[0].size();
        vector <int> result;
        for (int curve_line = 0 ; curve_line < (M + N - 1) ; curve_line ++){
            int row_begin = curve_line + 1 <= N ? 0 : curve_line + 1 - N;
            int row_end =  curve_line + 1 >= M ? M - 1 : curve_line;
            if (curve_line % 2 == 1){
                for (int i = row_begin ; i <= row_end ; i++)
                    result.push_back(matrix[i][curve_line - i]);
            }
            else{
                for (int i = row_end ; i >= row_begin ; i--)
                    result.push_back(matrix[i][curve_line - i]);
            }
        }
        return result;
    };
};