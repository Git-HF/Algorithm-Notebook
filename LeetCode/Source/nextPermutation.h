class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)
            return;
        
        int back = nums.size() - 1;
        while(back > 0)
        {
            // 注意这个等于号不能丢
            // 因为一个单调非增的序列，也需要从头来
            if(nums[back - 1] >= nums[back])
            {
                --back;
            }
            else
                break;
        }

        if(back == 0)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            reverse(nums.begin() + back, nums.end());
            int index = back - 1;
            while(back < nums.size())
            {
                if(nums[back] <= nums[index])
                    ++back;
                else
                    break;
            }

            // 由于一开始已经判断了这个不是一个单调非增的序列，所back一定不可能等于nums.size();
            // 不用判断back是否越界
            swap(nums[back], nums[index]);
        }
        
    }
};