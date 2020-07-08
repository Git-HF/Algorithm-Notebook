class Solution {
public:

    int findKthLargest(vector<int>& nums, int k) {

        int start = 0;
        int end = nums.size();
        while(1)
        {
            int mid = partition(nums, start, end);
            if((mid+1) == k)
                return nums[mid];
            else if((mid+1) < k)
            {
                start = mid+1;
            }
            else
                end = mid;
        }
    }

/*
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
*/

    int partition(vector<int>& nums, int start, int end)
    {
        // 最好使用随机快排，大大加快算法的速度。
        // int random_index = (rand() % (end - start)) + start;
        // std::swap(nums[start], nums[random_index]);
        if(start == end)
            return start;
            
        int less = start+1;
        for(int i = start+1; i < end; ++i)
        {
            // 这里等于是把大于N的数放左边，小于N的数放右边（不是一般的情况）
            if(nums[i] > nums[start])
                std::swap(nums[i], nums[less++]);
        }

        // 注意这里必须要--less。
        std::swap(nums[--less], nums[start]);
        return less;
    }
};