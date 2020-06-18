class Solution {
public:

    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp_arr;
        proceess(candidates, 0, tmp_arr, target);
        return res;
    }

    void proceess(vector<int>&  candidates, int start, vector<int> current_arr, int target)
    {
        if(target < 0)
            return;
        else if(target == 0)
        {
            res.push_back(current_arr);
            return;
        }

        if(start >= candidates.size())
            return;

        current_arr.push_back(candidates[start]);
        proceess(candidates, start, current_arr, target - candidates[start]);
        current_arr.pop_back();

        proceess(candidates, start + 1, current_arr, target);
    }
};