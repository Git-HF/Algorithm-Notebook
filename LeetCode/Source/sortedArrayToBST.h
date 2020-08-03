/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return NULL;

        return process(nums, 0, nums.size() - 1);
    }

    TreeNode* process(vector<int>& nums, int left, int right)
    {
        if(left == right)
        {
            return new TreeNode(nums[left]);
        }

        int mid = (left + right) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        if(left <= mid - 1)
        {
            cur->left = process(nums, left, mid-1);
        }
        if(mid+1 <= right)
        {
            cur->right = process(nums, mid+1, right);
        }

        return cur;
    }
};