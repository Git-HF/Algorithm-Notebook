class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre_nums = vector<int>(nums.size());
        pre_nums[0] = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            pre_nums[i] = pre_nums[i - 1] * nums[i - 1];
        }

        
        vector<int> post_nums = vector<int>(nums.size());
        post_nums[nums.size() - 1] = 1;
        for(int i = nums.size() - 2; i >= 0; --i)
        {
            post_nums[i] = post_nums[i+1] * nums[i+1];
        }

        
        for(int i = 0; i < nums.size(); ++i)
        {
            nums[i] = pre_nums[i] * post_nums[i];
        }
        

        return nums;
    }
};