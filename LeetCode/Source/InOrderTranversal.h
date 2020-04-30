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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(!root)
            return result;
        
        TreeNode* current = root;
        stack<TreeNode*> helpStack;
        while(!helpStack.empty() || current)
        {
            while(current)
            {
                helpStack.push(current);
                current = current->left;
            }
            
            
                current = helpStack.top();
                helpStack.pop();
                result.push_back(current->val);
                current = current->right;
        }

        return result;
    }
};