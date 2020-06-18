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
        stack<TreeNode* > help_stack;

        TreeNode temp_node;
        TreeNode* list_head = &temp_node;

        help_stack.push(root);

        while(!help_stack.empty())
        {
            TreeNode* tmp = help_stack.top();
            help_stack.pop();

            if(tmp->right)
                help_stack.push(tmp->right);
            
            if(tmp->left)
                help_stack.push(tmp->left);
            
            list_head->right = tmp;
            list_head = list_head->right;
            list_head->left = nullptr;
        }
    }
};