class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0;
        int not_zero = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] != 0)
                continue;
            else
            {
                not_zero = not_zero > i ? not_zero : i;
                not_zero = FindNotZero(not_zero+1, nums);
                if(not_zero == nums.size())
                    break;
                else
                {
                    swap(nums[i], nums[not_zero]);
                }
            }
        }
    }

    int FindNotZero(int count, const vector<int> & nums)
    {
        while(count < nums.size())
        {
            if(nums[count] != 0)
                break;
            ++count;
        }
        return count;
    }
};