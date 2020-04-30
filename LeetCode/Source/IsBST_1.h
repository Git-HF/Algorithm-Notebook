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
    bool isValidBST(TreeNode* root) {
        
        TreeNode* pre = NULL;

        return process(root, pre);
    }

    //注意pre是一个引用
    bool process(TreeNode* root, TreeNode* &pre)
    {
        if(!root)
            return true;

        if(!process(root->left, pre))
            return false;
        
        if(pre)
        {
            if(root->val <= pre->val)
                return false;
        }
        
        pre = root;
        return process(root->right, pre);
    }
};