class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
                SetFlag(nums, nums[i]);
        }

        vector<int> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
                res.push_back(i + 1);
        }

        return res;
    }

    void SetFlag(vector<int>& nums, int index)
        {
            while(index != 0)
            {
                int tmp = nums[index - 1];
                nums[index - 1] = 0;
                index = tmp;
            }
        }
};