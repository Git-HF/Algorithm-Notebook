class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int left = 1, right = nums.size()-1;
        while(left < right)
        {
            int mid = (left + right) / 2;
            
            int count = 0;
            for(int i = 0; i < nums.size(); ++i)
            {
                if((nums[i] >= left) && (nums[i] <= mid))
                    ++count;
            }

            if(count > (mid - left + 1))
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};