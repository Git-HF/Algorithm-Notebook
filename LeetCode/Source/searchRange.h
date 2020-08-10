class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0, right = nums.size()-1;
        int pos_left = -1;
        int pos_right = -1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] < target)
            {
                left = mid+1;
            }
            else if(nums[mid] > target)
            {
                right = mid-1;
            }
            else
            {
                pos_left = mid;
                right = mid-1;

            }
        }

        if(pos_left == -1)
            return {-1, -1};

        left = 0, right = nums.size()-1;
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] < target)
            {
                left = mid+1;
            }
            else if(nums[mid] > target)
            {
                right = mid-1;
            }
            else
            {
                pos_right = mid;
                left = mid+1;
                
            }
        }

        return {pos_left, pos_right};

    }
};