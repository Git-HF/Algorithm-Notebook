class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<int> res = vector<int>(n, 0);

        for(int i = m-1; i >= 0; --i)
            for(int j = n-1; j >= 0; --j)
            {
                if(i == m-1 || j == n-1)
                    res[j] = 1;
                else
                    res[j] += res[j+1];
            }
        
        return res[0];
    }
};