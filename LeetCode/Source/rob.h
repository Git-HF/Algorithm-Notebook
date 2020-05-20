class Solution {
public:
    int rob(vector<int>& nums) {

        return maxProfit(nums, 0);
    }

    int maxProfit(vector<int>& nums, int index)
    {
        if(index >= nums.size())
            return 0;
        if(index == nums.size() - 1)
            return nums[index];
        
        return std::max(nums[index] + maxProfit(nums, index + 2), maxProfit(nums, index + 1));
    }
};