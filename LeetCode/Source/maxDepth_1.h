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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;

        queue<TreeNode*> help_queue;
        help_queue.push(root);
        TreeNode* tmp_node;
        int level = 0;
        int count = help_queue.size();
        while(!help_queue.empty())
        {
            tmp_node = help_queue.front();
            help_queue.pop();

            if(tmp_node->left)
                help_queue.push(tmp_node->left);

            if(tmp_node->right)
                help_queue.push(tmp_node->right);

            if(--count == 0)
            {
                count = help_queue.size();
                ++level;
            }
        }

        return level;
    }
};