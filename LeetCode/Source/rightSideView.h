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
    map<int, int> help;

    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL)
            return vector<int>();

        process(root, 0);

        vector<int> ans;

        for(auto item : help)
        {
            ans.push_back(item.second);
        }
        return ans;
    }

    void process(TreeNode* root, int level)
    {
        if(!root)
            return;
        if(help.count(level) == 0)
        {
            help[level] = root->val;
        }
        process(root->right, level+1);
        process(root->left, level+1);
    }
};