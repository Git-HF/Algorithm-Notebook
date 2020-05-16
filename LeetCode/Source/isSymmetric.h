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
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        
        return process(root->left, root->right);
    }

    bool process(TreeNode* left, TreeNode* right)
    {
        if(!left && !right)
            return true;
        else if(!left && right)
            return false;
        else if(left && !right)
            return false;

        if(left->val != right->val)
            return false;
        bool first = process(left->left, right->right);
        if(!first)
            return false;
        bool second = process(left->right, right->left);
        if(!second)
            return false;
        
        return true;
    }
};