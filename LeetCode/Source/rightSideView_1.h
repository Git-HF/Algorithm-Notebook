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
    set<int> help;
    vector<int> ans;

    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return vector<int>();

        process(root, 0);

        return ans;
    }

    void process(TreeNode* root, int level)
    {
        if(!root)
            return;
        if(help.count(level) == 0)
        {
            help.insert(level);
            ans.push_back(root->val);
        }
        process(root->right, level+1);
        process(root->left, level+1);
    }
};