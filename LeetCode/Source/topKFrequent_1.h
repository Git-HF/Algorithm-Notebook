class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> help_map;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(help_map.count(nums[i]) == 1)
                help_map[nums[i]] += 1;
            else
                help_map[nums[i]] = 1;
        }

        auto iter = help_map.begin();

        vector<vector<int>> vec = vector<vector<int>>(nums.size() + 1, vector<int>());

        while(iter != help_map.end())
        {
            vec[iter->second].push_back(iter->first);
            ++iter;
        }

        vector<int> res;
        int count  = 0;
        for(int i = nums.size(); i >= 0; --i)
        {
            count += vec[i].size();
            for(auto item : vec[i])
                res.push_back(item);
            if(count >= k)
                break;
        }
        return res;
    }
};