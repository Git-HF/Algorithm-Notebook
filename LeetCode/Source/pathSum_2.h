class Solution {
public:
    int helper(TreeNode* root, int sum) {
        if (root== NULL) return 0;
        sum -= root->val;
        return (sum==0?1:0) + helper(root->left, sum) + helper(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if (root == NULL) return 0;
        return helper(root, sum)+pathSum(root->left, sum)+pathSum(root->right, sum);
    }
};

作者：ts13go
链接：https://leetcode-cn.com/problems/path-sum-iii/solution/c-xian-xu-bian-li-di-gui-fang-fa-yu-fei-di-gui-fan/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。