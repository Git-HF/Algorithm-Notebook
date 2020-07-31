class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <= 1)
            return nums.size();
        
        int min = nums[0], max = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            min = min < nums[i] ? min : nums[i];
            max = max > nums[i] ? max : nums[i];
        }
        vector<bool> help(max - min + 1, false);
        for(int i = 0; i < nums.size(); ++i)
        {
            help[nums[i] - min] = true;
        }

        int max_len = 0;
        int cur_len = 0;
        for(int i = 0; i < help.size(); ++i)
        {
            if(help[i])
            {
                ++cur_len;
                max_len = cur_len > max_len ? cur_len : max_len;
            }
            else
                cur_len = 0;
        }
        return max_len;
    }
};