class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        for(int i = 0; i < nums.size(); ++i)
        {
            int target = nums[i];
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(target == nums[j])
                    return target;
            }
        }

        return nums[0];
    }
};