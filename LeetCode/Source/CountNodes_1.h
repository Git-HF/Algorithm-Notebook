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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        return process(root, 1, most_left_level(root, 1));
    }

    int process(TreeNode* root, int level, int H)
    {
        if(level == H)
            return 1;
        
        if(most_left_level(root->right, level+1) == H)
        {
            return (1 << (H - level)) + process(root->right, level+1, H);
        }
        else 
            return (1 << (H - level - 1)) + process(root->left, level+1, H);
    }

    int most_left_level(TreeNode* root, int level)
    {
        while(root)
        {
            ++level;
            root = root->left;
        }
        return level - 1;
    }
};