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
    
    int max;
    int diameterOfBinaryTree(TreeNode* root) {
        max = 0;
        if(!root)
            return 0;

        process(root);
        return max;
    }

    int process(TreeNode* root)
    {
        int left = 0, right = 0;

        if(!root->left && !root->right)
            return 0;
        else if(!root->left)
            right = process(root->right) + 1;
        else if(!root->right)
            left = process(root->left) + 1;
        else
        {
            right = process(root->right) + 1;
            left = process(root->left) + 1;
        }
        
        max  = std::max(max, left + right);
        // 注意，这里是返回左右子树的最大高度，而不是高度和。
        return std::max(left, right);
    }


};