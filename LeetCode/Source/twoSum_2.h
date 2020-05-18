class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        multimap<int, int> help_map;
        for(int i = 0; i < nums.size(); ++i)
        {
            // 不支持索引访问元素
            // help_map[nums[i]] = i;
            help_map.insert({nums[i], i});
        }
        
        auto start = help_map.begin();
        auto end = help_map.end();
        --end;

        while(start != end)
        {
            if((start->first + end->first) == target)
                break;
            else if((start->first + end->first) < target)
                ++start;
            else 
                --end;
        }

        return {start->second, end->second};
    }
};