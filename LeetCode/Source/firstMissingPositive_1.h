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
            // 将位置i上放置值为i+1的元素。
            if(nums[i] <= nums.size() && nums[i] > 0 && nums[i] != nums[nums[i]-1])
            {
                std::swap(nums[i], nums[nums[i]-1]);
            }
            else
            {
                ++i;
            }
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != i+1)
            {
                return i+1;
            }
        }

        return nums.size()+1;
    }
};