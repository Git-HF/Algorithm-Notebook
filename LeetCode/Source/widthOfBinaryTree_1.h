/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 可以将mynode用pair来代替
    struct mynode
    {
        TreeNode* node;
        // 必须为long long否则会溢出
        long long index;
        mynode(TreeNode* t, int num)
        {
            node = t;
            index = num;
        }
    };

    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<mynode*> help;
        help.push(new mynode(root, 1));
        int max = 0;
        while(!help.empty())
        {
            long long left = help.front()->index;
            int len = help.size();
            for(int i = 0; i < len; ++i)
            {
                mynode* tmp = help.front();
                help.pop();
                int cur = tmp->index - left + 1;
                max = max > cur ? max : cur;
                if(tmp->node->left)
                    help.push(new mynode(tmp->node->left, tmp->index*2));
                if(tmp->node->right)
                    help.push(new mynode(tmp->node->right, tmp->index*2+1));
            }
        }
        return max;
    }
};