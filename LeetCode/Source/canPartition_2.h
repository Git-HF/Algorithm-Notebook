// 自底向上的动态规划
class Solution {
public:
    vector<vector<int>> dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }
        if(sum % 2 == 1)
            return false;
        
        int target = sum / 2;
        dp = vector<vector<int>>(nums.size(), vector<int>(target+1, 0));

        //dp数组初始化
        dp[0][0] = 1;
        if(nums[0] <= target)
            dp[0][nums[0]] = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j <= target; ++j)
            {
                // 注意dp状态转移方程为f(i, j) = f(i-1, j) || f(i-1, j - nums[i])，而不是
                // f(i, j) = f(i-1, j - nums[i])
                //将f(i, 0)都初始化为1.
                if(j > nums[i])
                    dp[i][j] = dp[i-1][j - nums[i]] || dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[nums.size() - 1][target] == 1;
    }
};