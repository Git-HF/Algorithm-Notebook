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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root || !p)
            return NULL;
        
        if(p->right)
        {
            TreeNode* current = p->right;
            while(current->left)
            {
                current = current->left;
            }
            return current;
        }
    
        TreeNode* parent = get_parent(root, p);
        while(parent)
        {
            if(parent->left == p)
                return parent;
            p = parent;
            parent = get_parent(root, p);
        }

        return NULL;
    }

    TreeNode* get_parent(TreeNode* root, TreeNode* p)
    {
        if(root == p)
            return NULL;

        TreeNode* pre = NULL;
        while(root != p)
        {
            pre = root;
            if(root->val < p->val)
                root = root->right;
            else if(root->val > p->val)
                root = root->left;
            
        }

        return pre;
    }
};