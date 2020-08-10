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
    bool isCompleteTree(TreeNode* root) {
        if(!root)
            return true;

        queue<TreeNode*> help;
        help.push(root);

        bool flag = false;
        while(!help.empty())
        {
            int len = help.size();
            for(int i = 0; i < len; ++i)
            {
                TreeNode* tmp = help.front();
                help.pop();

                if(tmp->left)
                {
                    if(flag)
                        return false;
                    else
                        help.push(tmp->left);
                }
                else
                    flag = true;

                if(tmp->right)
                {
                    if(flag)
                        return false;
                    else
                        help.push(tmp->right);
                }
                else
                    flag = true;
            }
        }
        return true;
    }
};