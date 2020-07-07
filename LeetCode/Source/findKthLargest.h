class Solution {
public:
    struct cmp
    {
        bool operator()(int a, int b)
        {
            return a < b;
        }
    };

    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, cmp> pq;

        for(int i = 0; i < nums.size(); ++i)
        {
            pq.push(nums[i]);
        }

        int max_k;
        for(int i = 0; i < k; ++i)
        {

            max_k = pq.top();
            pq.pop();

        }

        return max_k;
    }
};