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
        string res;
        process(root, res);
        return res;
    }

    void process(TreeNode* root, string &cur)
    {
        if(!root)
        {
            cur += "#?";
            return;
        }

        cur += to_string(root->val) + "?";
        process(root->left, cur);
        process(root->right, cur);
        
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start = 0;
        return de_process(data, start);
    }

    TreeNode* de_process(string data, int& index)
    {
        if(data[index] == '#')
        {
            index += 2;
            return NULL;
        }
        int end = index;
        while(data[end] != '?')
        {
            ++end;
        }
        
        TreeNode* N = new TreeNode(stoi(string(data.begin()+index, data.begin()+end)));
        index = end+1;

        N->left = de_process(data, index);
        N->right = de_process(data, index);
        return N;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));