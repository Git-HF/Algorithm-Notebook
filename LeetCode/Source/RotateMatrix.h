class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        int leftTop = 0, rightBottom = matrix.size() - 1;
        while(leftTop < rightBottom)
        {
            int i = 0;
            while(leftTop + i < rightBottom)
            {
                int tmp = matrix[leftTop][leftTop+i];
                matrix[leftTop][leftTop+i] = matrix[rightBottom-i][leftTop];
                matrix[rightBottom-i][leftTop] = matrix[rightBottom][rightBottom-i];
                matrix[rightBottom][rightBottom-i] = matrix[leftTop+i][rightBottom];
                matrix[leftTop+i][rightBottom] = tmp;
                ++i;
            }

            ++leftTop;
            --rightBottom;
        }
    }
};