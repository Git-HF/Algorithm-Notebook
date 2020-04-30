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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        stack<TreeNode*> helpStack;
        TreeNode* current = root;
        while(!helpStack.empty() || current)
        {
            while(current)
            {
                result.push_back(current->val);
                helpStack.push(current);
                current = current->left;
            }

            current = helpStack.top();
            helpStack.pop();
            current = current->right;
        }
        return result;
    }
};