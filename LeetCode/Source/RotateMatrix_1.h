class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m=matrix.size();
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++){
                matrix[i][j]^=matrix[j][i];
                matrix[j][i]^=matrix[i][j];
                matrix[i][j]^=matrix[j][i];
            }
        int left,right;
        for(int i=0;i<m;i++){
            left=0,right=m-1;
            while(left<right){
                matrix[i][left]^=matrix[i][right];
                matrix[i][right]^=matrix[i][left];
                matrix[i][left]^=matrix[i][right];
                left++;
                right--;
            }
        }
    }
};