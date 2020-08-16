class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        vector<int> dp(nums.size(), 0);
        dp[0] = 1;
        int max = dp[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            // 这里必须初始化位0，后面好处理
            int cur_max = 0;
            for(int j = 0; j < i; ++j)
            {
                // 这里是dp[i] > dp[index]，而不是arr[i] > arr[index]，注意
                if(nums[i] > nums[j])
                {
                    cur_max = std::max(cur_max, dp[j]);
                }
            }

            dp[i] = cur_max+1;
            
            max = std::max(max, dp[i]);
        }
        return max;
    }
};