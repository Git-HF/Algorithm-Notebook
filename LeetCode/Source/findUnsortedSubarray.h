class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {

        vector<int> tmp = nums;
        std::sort(tmp.begin(), tmp.end());

        int start = 0;
        while((start < nums.size())&&(nums[start] == tmp[start]))
        {
            ++start;
        }

        if(nums.size() == start)
            return 0;

        int end = nums.size() - 1;
        while(nums[end] == tmp[end])
        {
            --end;
        }

        return end - start + 1;
    }
};