class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> help;

        for(int i = 0; i < nums.size(); ++i)
        {
            help.insert(nums[i]);
        }

        int max = 0;
        int cur_len = 0;
        for(int item: nums)
        {
            if(!help.count(item - 1))
            {
                cur_len = 0;
                int cur = item;
                while(help.count(cur))
                {
                    ++cur_len;
                    ++cur;
                }
                max = max > cur_len ? max : cur_len;
            }
        }
        return max;
    }
};