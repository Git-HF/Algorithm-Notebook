class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        set<int> help_set;

        for(int element : nums)
            help_set.insert(element);
        
        vector<int> res;
        for(int i = 1; i <= nums.size(); ++i)
            if(help_set.count(i) == 0)
                res.push_back(i);
        
        return res;
    }
};