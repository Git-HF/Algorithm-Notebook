class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int dp = nums[0];
        int max = dp;

        for(int i = 1; i < nums.size(); ++i)
        {
            dp = std::max(dp + nums[i], nums[i]);
            max = std::max(max, dp);
        }
        return max;
    }
};