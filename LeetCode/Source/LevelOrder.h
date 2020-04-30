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
        
        int level = -1;
        int count = 0;
        int nextCount = 1;
        queue<TreeNode*> helpQueue;
        helpQueue.push(root);
        TreeNode* current;
        while(!helpQueue.empty())
        {
            if(count == 0)
            {
                count = nextCount;
                nextCount = 0;
                result.push_back(vector<int>());
            }

            int level = result.size() - 1;
            current = helpQueue.front();
            helpQueue.pop();
            --count;
            result[level].push_back(current->val);
            if(current->left)
            {
                helpQueue.push(current->left);
                ++nextCount;
            }

            if(current->right)
            {
                helpQueue.push(current->right);
                ++nextCount;
            }
        }
        
        return result;
    }
};