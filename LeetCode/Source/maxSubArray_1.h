class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        return process(nums, 0, nums.size() - 1);
    }

    int process(const vector<int> &nums, int start, int end)
    {
        if(start == end)
            return nums[start];
        else 
        {
            int mid = (end - start) / 2 + start;
            int left = process(nums, start, mid);
            int right = process(nums, mid+1, end);

            int tmp_left_max = nums[mid];

            int tmp_sum = nums[mid];
            for(int i = mid - 1; i >= start; --i)
            {
                tmp_sum += nums[i];
                tmp_left_max = std::max(tmp_left_max, tmp_sum);
            }

            tmp_sum = nums[mid+1];
            int tmp_right_max = nums[mid+1];
            for(int i = mid + 2; i <= end; ++i)
            {
                tmp_sum += nums[i];
                tmp_right_max = std::max(tmp_right_max, tmp_sum);
            }

            return std::max(std::max(left, right), tmp_left_max+tmp_right_max);

        }
    }
};