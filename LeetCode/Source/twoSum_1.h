class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int> help_map;
        vector<int> res;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(help_map.count(target - nums[i]) == 1)
            {
                res.push_back(help_map[target - nums[i]]);
                res.push_back(i);
                break;
            }
            help_map[nums[i]] = i;
        }

        return res;
    }
};