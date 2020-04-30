/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return string("#_");

        string result;
        result = to_string(root->val) + "_";
        result += serialize(root->left);
        result += serialize(root->right);
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0] == '#')
            return NULL;
        
        TreeNode* root = NULL;
        deserialize_process(root, data, 0);
        return root;
        
    }

    // 返回值表示已经处理到第几个字符了，接下来从该处判断字符串
    // 注意参数root为指向指针的引用，不能错
    //重建二叉树时左树和右树的区分是通过递归函数来完成的。
    int deserialize_process(TreeNode* &root, string data, int index)
    {
        if(data[index] == '#')
            return index + 2;
        else
        {
            auto p = find(data.begin() + index, data.end(), '_');
            string tmpString(data.begin()+index, p);
            root = new TreeNode(stoi(tmpString));
            index = p - data.begin() + 1;
            if(index < data.size())
                index = deserialize_process(root->left, data, index);
            if(index < data.size())
                index = deserialize_process(root->right, data, index);
            
            return index;
        }
    }


};