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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if(!root)
            return res;

        queue<TreeNode*> help;
        help.push(root);
        bool flag = true;
        while(!help.empty())
        {
            int len = help.size();
            vector<int> tmp;
            TreeNode* cur;
            for(int i = 0;  i < len; ++i)
            {
                cur = help.front();
                help.pop();
                tmp.push_back(cur->val);
                if(cur->left)
                    help.push(cur->left);
                if(cur->right)
                    help.push(cur->right);
            }

            if(!flag)
                std::reverse(tmp.begin(), tmp.end());
            res.push_back(tmp);
            flag = !flag;
        }

        return res;
    }
};