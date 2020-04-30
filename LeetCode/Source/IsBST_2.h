bool isValidBST(TreeNode* root){
        return isValidBSTCore(root, LLONG_MIN, LLONG_MAX);
    }
    //使用long long类型，防止有的节点值就是int类型的最大值或者最小值。
    bool isValidBSTCore(TreeNode* root, long long lower, long long upper){
        if(root==nullptr) return true;
        long long curVal = root->val;
        if(curVal<=lower || curVal>=upper)
            return false;
        return isValidBSTCore(root->left, lower, curVal) && isValidBSTCore(root->right, curVal, upper);
    }