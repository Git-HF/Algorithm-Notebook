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

    map<int, int> help_map;
    int target;

    int pathSum(TreeNode* root, int sum) {

        if(!root)
            return 0;
        
        target = sum;

        // 不能丢，用于当节点值等于目标值的时候。
        // ！！！注意
        help_map.insert(pair<int, int>(0, 1));
        return process(root, 0);
    }

    int process(TreeNode* root, int curSum)
    {
        curSum += root->val;
        int res = 0;
        if(help_map.count(curSum - target) != 0)
            res += help_map[curSum - target];
        
        if(help_map.count(curSum) != 0)
        {
            help_map[curSum] += 1;
        }
        else
        {
            help_map[curSum] = 1;
        }

        if(root->left)
            res += process(root->left, curSum);
        
        if(root->right)
            res += process(root->right, curSum);
        
        help_map[curSum] -= 1;
        
        return res;
    }
};