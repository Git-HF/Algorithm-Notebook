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
        help_func(result, root, 0);
        return result;
    }

    // 该方法实际上还是DFS,只不过用特殊的结构存储，从而区分了不同的层。
    void help_func(vector<vector<int>> &result, TreeNode* root, int level)
    {
        if(!root)
            return;
        
        if(level == result.size())
        {
            result.push_back(vector<int>());
        }

        result[level].push_back(root->val);
        help_func(result, root->left, level+1);
        help_func(result, root->right, level+1);
    }
};