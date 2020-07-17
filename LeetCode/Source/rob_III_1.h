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

    int max = 0;
    int rob(TreeNode* root) {

        process(root);
        return max;

    }

    pair<int, int> process(TreeNode* root)
    {
        if(!root)
            return pair<int, int>(0, 0);

        pair<int, int> left = process(root->left);
        pair<int, int> right = process(root->right);

        int cur_max = left.second + right.second + root->val;
        cur_max = std::max(cur_max, left.first + right.first);

        max = std::max(max, cur_max);

        return pair<int, int>(cur_max, left.first + right.first);

    }
};