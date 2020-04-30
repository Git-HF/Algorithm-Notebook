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
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> result;
            if(!root)
                return result;
            
            stack<TreeNode*> dataStack;
            stack<int> reverseStack;
            TreeNode* current = root;
            while(!dataStack.empty() || current)
            {
                while(current)
                {
                    reverseStack.push(current->val);
                    dataStack.push(current);
                    current = current->right;
                }

                current = dataStack.top();
                dataStack.pop();
                current = current->left;
            }

            while(!reverseStack.empty())
            {
                result.push_back(reverseStack.top());
                reverseStack.pop();
            }

            return result;
        }
    };