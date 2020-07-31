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

    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        process(root, vector<int>(), sum);
        return res;
    }

    bool process(TreeNode* root, vector<int> help, int sum)
    {
        if(!root)
            return true;
        
        help.push_back(root->val);
        bool left = process(root->left, help, sum - root->val);
        bool right = process(root->right, help, sum - root->val);
        if(left && right && (sum == root->val))
            res.push_back(help);
        help.pop_back();
        return false;
    }
};