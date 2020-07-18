class Solution {
public:

    int max = 0;
    unordered_map<TreeNode*, int> help;

    int rob(TreeNode* root) {

        if(!root)
            return 0;
        
        if(help.count(root) == 1)
            return help[root];
        
        int sum = root->val;
        if(root->left)
        {
            sum += rob(root->left->left) + rob(root->left->right);
        }

        if(root->right)
        {
            sum += rob(root->right->left) + rob(root->right->right);
        }

        int cur_max = std::max(sum, rob(root->left) + rob(root->right));
        //max = max > cur_max ? max : cur_max;
        help[root] = cur_max;
        return cur_max;

    }
};