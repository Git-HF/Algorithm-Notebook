class Solution {
public:
    int res = INT_MAX;
    void dfs(int n, int cnt)
    {
        if (n == 0)
        {
            res = min(res, cnt);
            return;
        }
        if (n < 0)
        {
            return;
        }
        for (int i = sqrt(n); i > 0; --i)
        {
            //该循环很重要，有两个地方剪枝。j = n / (i*i)和 cnt + j。
            for (int j = n / (i*i); j > 0 && cnt + j < res; --j)
            {
                dfs(n - j*i*i, cnt + j);
            }    
        }
    }
    int numSquares(int n) {
        dfs(n, 0);
        return res;
    }
};