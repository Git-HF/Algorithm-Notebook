class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int target = (nums1.size() + nums2.size())/2 + 1;
        
        int left = 0, right = 0;
        int cur = -1, pre = -1;
        for(int i = 1; i<= target; ++i)
        {
            pre = cur;
            if(left == nums1.size())
            {
                cur = nums2[right++];
            }
            else if(right == nums2.size())
            {
                cur = nums1[left++];
            }
            else if(nums1[left] < nums2[right])
            {
                cur = nums1[left++];
            }
            else
            {
                cur = nums2[right++];
            }
        }

        if((nums1.size() + nums2.size()) % 2 == 0)
            return double(cur + pre)/2.0;
        else
            return cur;
    }
};