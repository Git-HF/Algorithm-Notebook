class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag_nums(nums.size(), false);

        vector<int> current_nums;
        vector<vector<int>> result;

        process(nums, flag_nums, current_nums, result);
        
        return result;
    }

    void process(const vector<int>& nums, vector<bool>& flag_nums, vector<int>& current_nums, vector<vector<int>> &result)
    {
        for(int i = 0; i < flag_nums.size(); ++i)
        {
            if(!flag_nums[i])
            {
                flag_nums[i] = true;
                current_nums.push_back(nums[i]);

                if(current_nums.size() == flag_nums.size())
                    result.push_back(current_nums);
                else
                    process(nums, flag_nums, current_nums, result);

                current_nums.pop_back();
                flag_nums[i] = false;
            }
        }
    }
};