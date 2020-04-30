class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<int> current;
        process(nums, current, 0);
        return result;
    }

    void process(const vector<int> &nums, vector<int>& current, int index)
    {
        if(index == nums.size())
        {
            result.push_back(current);
            return;
        }

        process(nums, current, index+1);

        current.push_back(nums[index]);
        process(nums, current, index+1);
        current.pop_back();
    }
};