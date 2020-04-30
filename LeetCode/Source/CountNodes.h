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
        
        int height = get_height(root);

        TreeNode* parent = root;
        TreeNode* current = parent->right;
        int count = 0;
        int upHeight = 1;
        while(current)
        {
            int tmpHeight = get_height(current);

            if((tmpHeight + upHeight) == height)
            {
                count += pow(2, tmpHeight);
            }
            else
            {
                count += pow(2, tmpHeight);
                current = parent->left;
            }

            parent = current;
            current = parent->right;
            ++upHeight;

        }

        count += parent->left ? 2 : 1;

        return count;
    }

    int get_height(TreeNode* root)
    {
        int count = 0;
        while(root)
        {
            ++count;
            root = root->left;
        }
        return count;
    }
};