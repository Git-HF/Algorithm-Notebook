class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        int left = 1, right = 1;
        for (int i = 0, j = nums.size() - 1; i < nums.size(); i ++, j --) {
            res[i] *= left; res[j] *= right;
            left *= nums[i]; right *= nums[j];
        }
        return res;
    }
};