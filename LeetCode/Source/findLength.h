class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {

        int len_A = A.size();
        int len_B = B.size();

        vector<vector<int>> dp(len_A, vector<int>(len_B, 0));
        int max = 0;
        for(int i = 0; i < len_A; ++i)
        {
            for(int j = 0; j < len_B; ++j)
            {
                if(A[i] == B[j])
                {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i-1][j-1]+1;
                    
                    max = std::max(dp[i][j], max);
                }
            }
        }

        return max;
    }
};