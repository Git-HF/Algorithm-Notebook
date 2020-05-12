class Solution {
public:
    int helper(TreeNode* root, int sum, vector<int>& path) {
        if (root == NULL) return 0;
        path.push_back(root->val);
        int sum_cur = 0;
        int res = 0;
        for (int i= path.size()-1; i>=0; i--) {
            // 以当前为终点，起点一直向上选取，直到到达根节点。
            sum_cur+= path[i];
            if (sum_cur == sum) ++res;
        }
        res += helper(root->left, sum, path) + helper(root->right, sum, path);
        path.pop_back();
        return res;
    }
    int pathSum(TreeNode* root, int sum) {
        vector<int> path;
        return helper(root, sum, path);
    }
};