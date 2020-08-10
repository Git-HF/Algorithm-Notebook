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
                if(tmp)
                {
                    if(flag)
                        return false;
                    help.push(tmp->left);
                    help.push(tmp->right);
                }
                else
                    flag = true;
                
            }
        }
        return true;
    }
};