class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); ++i)
        {
            heap_insert(nums, i);
        }

        for(int i = 0;i < k; ++i)
        {
            // 交换操作最好不要放进heap_ify中
            std::swap(nums[0], nums[nums.size() - 1 - i]);
            heap_ify(nums, nums.size() - i - 1);
        }

        return nums[nums.size() - k];
    }

    void heap_insert(vector<int>& nums, int index)
    {
        int parent;

        while(index != 0)
        {
            parent = (index - 1) / 2;
            if(nums[index] > nums[parent])
                std::swap(nums[index], nums[parent]);
            else
                break;
            index = parent;
        }
    }

    void heap_ify(vector<int>& nums, int heap_size)
    {

        if(heap_size <= 1)
            return;

        int i = 0;
        int left_child = 2 * i + 1;
        // 注意边界条件的判断格式。
        while(left_child < heap_size)
        {
            int max_child = (left_child + 1 < heap_size) && (nums[left_child] < nums[left_child + 1]) ? left_child + 1 : left_child;
            if(nums[i] < nums[max_child])
                std::swap(nums[i], nums[max_child]);
            else
                break;
        
            i = max_child;
            left_child = 2 * i + 1;
        }
    }
};