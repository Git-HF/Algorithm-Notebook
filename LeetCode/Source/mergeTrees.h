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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {

        process(t1, t2);
        return t1;
    }

    void process(TreeNode* &t1, TreeNode* &t2)
    {
        if(!t1 && !t2)
        {
            return;
        }
        
        if(t1 && t2)
        {
            t1->val += t2->val;
            process(t1->left, t2->left);
            process(t1->right, t2->right);
        }
        else if(!t1 && t2)
        {
            t1 = t2;
        }
    }

};