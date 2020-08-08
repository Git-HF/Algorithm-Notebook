class Solution {
public:
    bool isStraight(vector<int>& nums) {

        std::sort(nums.begin(), nums.end());
        int count = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == 0)
                ++count;
            else if(i > 0 && nums[i-1] != 0)
            {
                int dif = nums[i] - nums[i-1];
                if(dif == 0)
                    return false;
                else
                {
                    count -= dif-1;
                    if(count < 0)
                        return false;
                }
            }
        }

        return true;
    }
};