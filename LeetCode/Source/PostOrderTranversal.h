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
            // 用来表示dataStack中每一个元素是否已经访问了右孩子，如果是false则没有，如果是true则访问过。
            stack<bool> flagStack;
            TreeNode* current = root;
            while(!dataStack.empty() || current)
            {
                while(current)
                {
                    dataStack.push(current);
                    flagStack.push(false);
                    current = current->left;
                }
                    if(!flagStack.top())
                    {
                        flagStack.pop();
                        flagStack.push(true);
                        current = dataStack.top()->right;
                    }
                    else
                    {
                        current = dataStack.top();
                        dataStack.pop();
                        flagStack.pop();
                        result.push_back(current->val);
                        current = NULL;
                    }
            }

            return result;
        }
    };