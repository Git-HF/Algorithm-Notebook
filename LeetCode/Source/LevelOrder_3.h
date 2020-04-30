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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q1;
        queue<TreeNode*> q2;
        vector<int> vec;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        TreeNode* p = root;
        q1.push(root);
        while((!q1.empty()) || (!q2.empty())) //队列q1或者q2不空的时候执行循环
        {
            while(!q1.empty())
            {
                p = q1.front();
                if(p != NULL) vec.push_back(p -> val);
                q1.pop();
                if(p -> left != NULL) q2.push(p -> left); //将子结点都放入q2中
                if(p -> right != NULL) q2.push(p -> right);
            }
            if(vec.size() > 0) ans.push_back(vec);
            vec.clear();
            while(!q2.empty())
            {
                p = q2.front();
                if(p != NULL) vec.push_back(p -> val);
                q2.pop();
                if(p -> left != NULL) q1.push(p -> left); //同上
                if(p -> right != NULL) q1.push(p -> right);
            }
            if(vec.size() > 0) ans.push_back(vec); //注意if循环一定要有，否则当q2是空而不执行循环时，将会把clear过的空vec放入ans中
            vec.clear();
        }
        return ans;
    }
};