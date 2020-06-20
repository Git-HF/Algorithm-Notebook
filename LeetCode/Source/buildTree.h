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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        if(preorder.size() == 0)
            return NULL;
        
        return process(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }

    TreeNode* process(vector<int>& preorder, vector<int>& inorder, int pre_start, int pre_end, int in_start, int in_end)
    {
        if(pre_start == pre_end)
        {
            TreeNode* n = new TreeNode(preorder[pre_start]);
            return n;
        }

        int i;
        for(i = in_start; i <= in_end; ++i)
        {
            if(preorder[pre_start] == inorder[i])
                break;
        }

        TreeNode* left = NULL;
        if(in_start < i)
        {
            left = process(preorder, inorder, pre_start+1, pre_start+i-in_start, in_start, i - 1);   
        }

        TreeNode* right = NULL;
        
        if(in_end > i)
        {
            right = process(preorder, inorder, pre_start+i-in_start+1, pre_end, i+1, in_end);
        }

        TreeNode* newNode = new TreeNode(preorder[pre_start]);
        newNode->left =  left;
        newNode->right = right;
        return newNode;
    }
};