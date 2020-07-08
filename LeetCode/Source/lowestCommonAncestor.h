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
    vector<TreeNode*> parent_p;

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> parent_p, parent_q;
        post(root, parent_p, p->val);
        post(root, parent_q, q->val);

        TreeNode* res = NULL;
        for(int i = 0; i < parent_p.size() && i < parent_q.size(); ++i)
        {
            if(parent_p[i] == parent_q[i])
            {
                res = parent_p[i];
            }
            else
                break;
        }

        return res;
    }

    bool post(TreeNode* root, vector<TreeNode*> &parent, int target)
    {
        if(!root)
            return false;
        
        // 这一句话一定要放在if前面，否则当其中一个节点是另一个节点祖先时，检测不出来。
        parent.push_back(root);
        if(root->val == target)
            return true;
        
        if(post(root->left, parent, target))
            return true;

        if(post(root->right, parent, target))
            return true;
        
        parent.pop_back();
        return false;
        
    }
};