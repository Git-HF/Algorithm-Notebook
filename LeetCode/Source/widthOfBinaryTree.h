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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        deque<TreeNode*> help;
        help.push_back(root);
        int max = 0;
        while(!help.empty())
        {
            while(!isempty(help) && !help.front())
                help.pop_front();
            
            while(!isempty(help) && !help.back())
                help.pop_back();
            
            int len = help.size();
            max = std::max(max, len);
            for(int i = 0; i < len; ++i)
            {
                TreeNode* tmp = help.front();
                help.pop_front();
                if(!tmp)
                    continue;
                else
                {
                    help.push_back(tmp->left);
                    help.push_back(tmp->right);
                }
            }
        }

        return max;
    }
};