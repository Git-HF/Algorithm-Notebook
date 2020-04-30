/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct Result
 {
     int height = 1;
     bool isB = true;

 };
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        Result  r = isBalanced_process(root);
        return r.isB;
    }

    Result isBalanced_process(TreeNode* root)
    {
        if(!root)
            return Result();
        
        Result left = isBalanced_process(root->left);
        if(!left.isB)
            return left;
        
        Result right = isBalanced_process(root->right);
        if(!right.isB)
            return right;
        if(abs(left.height - right.height) < 2)
        {
            left.height = left.height > right.height ? left.height + 1 : right.height + 1;
            return left;
        }
        else
        {
            left.isB = false;
            return left;
        }
    }
};