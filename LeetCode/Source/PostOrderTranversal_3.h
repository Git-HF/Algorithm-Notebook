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
            TreeNode* current = root;
            TreeNode* pre = NULL;
            while(!dataStack.empty() || current)
            {
                while(current)
                {
                    dataStack.push(current);
                    current = current->left;
                }

                current = dataStack.top();
                if(current->right == NULL || current->right == pre)     //没有右孩子或者已经访问完右孩子。
                {
                    result.push_back(current->val);
                    dataStack.pop();
                    pre = current;
                    current = NULL;     //不能丢
                }
                else
                    current = current->right;           //右孩子还未访问
            }
            return result;
        }
    };