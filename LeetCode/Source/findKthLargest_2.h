class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 注意lambda表达式的使用
        sort(nums.begin(), nums.end(), [](int a, int b) -> bool {return a > b;});
        return nums[k-1];
    }
};