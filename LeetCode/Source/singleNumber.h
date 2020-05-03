class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_set<int> help_set;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(help_set.count(nums[i]) == 0)
                help_set.insert(nums[i]);
            else
            {
                help_set.erase(nums[i]);
            }
        }

        int i = 0;
        for(; i < nums.size(); ++i)
        {
            if(help_set.count(nums[i]) == 1)
                break;
        }

        return nums[i];
    }
};