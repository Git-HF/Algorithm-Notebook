class Solution {
public:
    void sortColors(vector<int>& nums) {
        int less = 0, more = nums.size() - 1;
        
        int i = 0;
        while(i <= more)
        {
            if(nums[i] == 0)
            {
                std::swap(nums[i++], nums[less++]);
            }
            else if(nums[i] == 2)
            {
                std::swap(nums[i], nums[more--]);
                continue;
            }
            else
                ++i;
        }

    }
};