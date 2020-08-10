class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0)
        {
            return 1;
        }

        for(int i = 0; i < nums.size();)
        {
            // 注意异常情况的判断。
            if(nums[i] < nums.size() && nums[i] >= 0 && nums[i] != nums[nums[i]])
            {
                std::swap(nums[i], nums[nums[i]]);
            }
            else
            {
                ++i;
            }
        }

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }

        // 注意边界条件的判断
        if(nums.size() == nums[0])
            return nums.size()+1;
        else
            return nums.size();
    }
};