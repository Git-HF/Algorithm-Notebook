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
    int max = INT_MIN;
    int maxPathSum(TreeNode* root)
    {
        process(root);
        return max;
    }

    int process(TreeNode* root) {

        if(!root)
            return 0;
        
        int left = process(root->left);
        int right = process(root->right);
        // 左子树+右子树
        int cur_max = left + right + root->val;
        // 左子树+自己
        cur_max = std::max(cur_max, left + root->val);
        // 右子树+自己
        cur_max = std::max(cur_max, right + root->val);
        // 自己
        cur_max = std::max(cur_max, root->val);
        max = std::max(cur_max, max);
        //注意这里也必须考虑单独的根节点，因为有可能两个子数值均为负值。
        int tmp = std::max(right + root->val, root->val);
        return std::max(left + root->val, tmp);

    }
};