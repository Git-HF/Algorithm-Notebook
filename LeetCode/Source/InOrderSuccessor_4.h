class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)
            return NULL;
        

        if(p->val >= root->val)
            return inorderSuccessor(root->right, p);
        else
        {
            TreeNode* result;
            result = inorderSuccessor(root->left, p);
            return result ? result : root;
        }
    }
};