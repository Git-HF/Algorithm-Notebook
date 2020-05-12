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
    
    int source_sum;

    int pathSum(TreeNode* root, int sum) {
        source_sum = sum;

        return  process(root, sum);
    }

int process(TreeNode* root, int sum) {

        if(!root)
        {
            return 0;
        }

        int left_include_self = process(root->left, sum - root->val);
        int left_no_include_self = process(root->left, source_sum);
        int right_include_self = process(root->right, sum - root->val);
        int right_no_include_self = process(root->right, source_sum);

        return ((sum == root->val) ? 1 : 0) + left_include_self + left_no_include_self + right_include_self + right_no_include_self;
    }

    


};