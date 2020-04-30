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
    vector<TreeNode* > IO;
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        //中序遍历后，返回p的下一个节点
        Inorder(root);
        for (int i=0; i<IO.size(); i++){
            if (IO[i] == p && i<IO.size()-1) return IO[i+1];
            if (IO[i] == p && i==IO.size()-1) return NULL;
        }
        return NULL;
    }
    void Inorder(TreeNode* root){//中序遍历
        if (root==NULL) return;
        Inorder(root->left);
        IO.push_back(root);
        Inorder(root->right);
    }
};