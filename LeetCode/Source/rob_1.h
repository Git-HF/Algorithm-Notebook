class Solution {
public:
    int rob(vector<int>& nums) {

        if(nums.size() == 0)
            return 0;

        if(nums.size() == 1)
            return nums[0];
        
        int pre_pre = 0, pre = nums[0];

        for(int i = 1; i < nums.size(); ++i)
        {
            int tmp = pre_pre;
            pre_pre = pre;
            pre= std::max(pre_pre, tmp + nums[i]);
        }
        return pre;
    }
};