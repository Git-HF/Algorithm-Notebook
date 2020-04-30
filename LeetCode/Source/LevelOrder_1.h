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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root)
            return vector<vector<int>>();
        
        queue<TreeNode*> helpQueue;
        helpQueue.push(root);
        TreeNode* current;
        while(!helpQueue.empty())
        {
            //result.push_back(vector<int>());
            vector<int> currentLevel;

            int len = helpQueue.size();
            for(int i = 0; i < len; ++i)
            {
                current = helpQueue.front();
                helpQueue.pop();
                currentLevel.push_back(current->val);

                if(current->left)
                {
                    helpQueue.push(current->left);
                }

                if(current->right)
                {
                    helpQueue.push(current->right);
                }
            }
            result.push_back(currentLevel);
        }
        
        return result;
    }
};