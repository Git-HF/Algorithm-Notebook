class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        if (root != nullptr) q.push(root);
        while (!q.empty()) {
            for (int i = q.size() - 1; i >= 0; --i) {
                TreeNode* cur = q.front();
                q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            ++ans;
        }
        return ans;
    }
};