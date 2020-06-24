class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int i = 0;
        while(i < nums.size())
        {
            if(nums[i] == (i+1))
                ++i;
            else
            {
                if(nums[nums[i] - 1] != nums[i])
                    swap(nums, i, nums[i] - 1);
                else
                    break;
            }
        }

        return nums[i];
    }

    void swap(vector<int>& nums, int a, int b)
    {
        int tmp = nums[a];
        nums[a] = nums[b];
        nums[b] = tmp;
    }
};