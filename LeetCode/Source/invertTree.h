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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* new_root = NULL;
        process(root, new_root);

        return new_root;
    }

    void process(TreeNode* root, TreeNode* &new_root)
    {
        if(root)
        {
            new_root = new TreeNode(root->val);
            process(root->left, new_root->right);
            process(root->right, new_root->left);
        }
    }
};