// 
class Solution {
public:
    int countNodes(TreeNode* root) {

        if(!root)
            return 0;
        
        int leftHeight = get_level(root->left);
        int rightHeight = get_level(root->right);

        if(leftHeight == rightHeight)
        {
            return countNodes(root->right) + (1 << leftHeight);
        }
        else
        {
            return countNodes(root->left) + (1 << rightHeight);
        }
    }

    int get_level(TreeNode* root)
    {
        int count = 0;
        while(root)
        {
            ++count;
            root = root->left;
        }
        return count;
    }

};