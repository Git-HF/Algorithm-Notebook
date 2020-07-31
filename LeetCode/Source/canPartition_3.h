// 自底向上的动态规划
class Solution {
public:
    vector<bool> dp;
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
        }
        if(sum % 2 == 1)
            return false;
        
        int target = sum / 2;
        dp = vector<bool>(target+1, false);

        //dp数组初始化
        dp[0] = true;
        if(nums[0] <= target)
            dp[nums[0]] = true;
        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = target; j >= 0; --j)
            {
                if(j >= nums[i])
                {   // 对于任意元素dp[i]其取决于上一层的上一个元素和左上角的元素，所以必须从右向左计算。
                    // 否则需要滚动数组
                    dp[j] = dp[j - nums[i]] || dp[j];
                }
            }
        }

        return dp[target];
    }
};