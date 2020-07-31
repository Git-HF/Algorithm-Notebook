vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> ans; vector<int> curr; //分别记录所有满足条件的路径、一条满足条件的路径
	if (!root) return ans;
	stack<TreeNode*> stk; TreeNode *prev = nullptr;
	while (root || !stk.empty()) { //模拟系统递归栈
		while (root) {
			stk.push(root); sum -= root->val; curr.push_back(root->val); //入栈、更新剩余和、路径
			root = root->left;
		}//递归访问左结点

		root = stk.top(); //不能再左了，取得右拐点（根结点）
		if (!root->left && !root->right && (sum == 0)) { //条件：是叶子结点且剩余和为0
			ans.push_back(curr); //满足条件，保存路径
		}

		if (!root->right || root->right == prev) { //右结点不存在或已经访问 回溯
			stk.pop(); sum += root->val; curr.pop_back(); //出栈、更新剩余和、路径
			prev = root; //标记已访问
			root = nullptr; //用于回溯到上一级
		}
		else { //递归访问右结点
			root = root->right;
		}
	}
	return ans;
}