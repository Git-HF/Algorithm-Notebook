class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] > 0)
                break;
            
            //为了确保不重复，必须将i移动到下一个不同的位置
            if(i == 0 || nums[i] != nums[i-1])
            {
                int left = i + 1, right = nums.size() - 1;
                while(left < right)
                {
                    if(nums[i] + nums[left] + nums[right] == 0)
                    {
                        vector<int> tmp = {nums[i], nums[left], nums[right]};
                        res.push_back(tmp);
                        //为了确保不重复，必须将left, right移动到下一个不同的位置

                        left = move_to_right(nums, left);
                        right = move_to_left(nums, right);
                    }
                    else if(nums[i] + nums[left] + nums[right] < 0)
                    {
                        //这里可以直接使用++left
                        //++left;
                        left = move_to_right(nums, left);
                    }
                    else
                    {
                        //这里可以直接使用--right
                        //--right;
                        right = move_to_left(nums, right);
                    }
                }
            }
        }

        return res;
    }

    //将索引指针往右移动
    int move_to_right(vector<int>& nums, int index)
    {
        
        while(index < nums.size() - 1 && nums[index] == nums[index+1])
            ++index;
        return ++index;
    }

    //将索引指针往左移动
    int move_to_left(vector<int>& nums, int index)
    {   
        while(index > 0 && nums[index] == nums[index-1])
            --index;
        return --index;
    }
};