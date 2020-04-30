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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        
        stack<TreeNode*> helpStack;
        TreeNode* current = root;

        TreeNode* pre = NULL;
        while(!helpStack.empty() || current)
        {
            while(current)
            {
                helpStack.push(current);
                current = current->left;
            }

            current = helpStack.top();
            helpStack.pop();

            if(pre)
            {
                if(pre->val >= current->val)
                    return false;
            }

            pre = current;
            current = current->right;
        }

        return true;
    }
};