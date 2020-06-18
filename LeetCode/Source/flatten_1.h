/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        
        if(root->left)
        {
            TreeNode* most_right = get_most_right(root->left);

            most_right->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        flatten(root->right);

    }

    TreeNode* get_most_right(TreeNode* root)
    {
        while(root->right)
        {
            root = root->right;
        }
        return root;
    }
};