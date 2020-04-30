
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //如果有右孩子，则后继节点一定在右子树中。
        if (p->right) {
            p = p->right;
            while (p->left) p = p->left;
            return p;
        }
        //没有右孩子，则后继节点一定在父节点中。
        TreeNode* res = NULL;
        while (root != p) {
            if (root->val < p->val) {
                root = root->right;
            } else {
                res = root;
                root = root->left;
            }
        }
        return res;
    }
};