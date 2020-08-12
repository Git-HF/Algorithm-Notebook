class Solution {
public:
    int missingNumber(vector<int>& nums) {

        for(int i = 0; i < nums.size();)
        {
            // 注意，只有未进行交换操作才能++i，否则不能++i。
            if(nums[i] != nums.size())
            {
                if(nums[i] != i)
                    std::swap(nums[i], nums[nums[i]]);
                else
                    ++i;
            }
            else
                ++i;
                
        }

        for(int i = 0;i < nums.size(); ++i)
        {
            if(nums[i] != i)
                return i;
        }
        return nums.size();
    }
};