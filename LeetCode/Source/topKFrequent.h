class Solution {
public:

    struct cmp
    {
        public:
            bool operator()(const pair<int, int> p1, const pair<int, int> p2)
            {
                if(p1.second > p2.second)
                    return true;
                else
                    return false;
            }
        
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> help_map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> help_queue;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(help_map.count(nums[i]) == 1)
                help_map[nums[i]] += 1;
            else
                help_map[nums[i]] = 1;
        }

        auto iter = help_map.begin();

        int count = 0;
        while(iter != help_map.end())
        {
            help_queue.push(*iter);
            ++iter;
            ++count;

            if(count > k)
            {
                help_queue.pop();
            }
        }

        vector<int> res;
        while(!help_queue.empty())
        {
            res.push_back(help_queue.top().first);
            help_queue.pop();
        }

        return res;
    }
};