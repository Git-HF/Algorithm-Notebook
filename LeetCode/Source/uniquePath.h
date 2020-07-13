class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> res = vector<vector<int>>(m, vector<int>(n));

        for(int i = m-1; i >= 0; --i)
            for(int j = n-1; j >= 0; --j)
            {
                if(i == m-1 || j == n-1)
                    res[i][j] = 1;
                else
                    res[i][j] = res[i+1][j] + res[i][j+1];
            }
        
        return res[0][0];
    }
};