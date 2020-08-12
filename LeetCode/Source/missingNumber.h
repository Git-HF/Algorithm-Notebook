class Solution {
public:
    int missingNumber(vector<int>& nums) {

        for(int i = 0;i < nums.size(); ++i)
        {
            nums[i] += 1;
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            int target = std::abs(nums[i])-1;
            if(target != nums.size())
                nums[target] = nums[target] < 0 ? nums[target] : -nums[target];
        }

        for(int i = 0;i < nums.size(); ++i)
        {
            if(nums[i] > 0)
                return i;
        }
        return nums.size();
    }
};