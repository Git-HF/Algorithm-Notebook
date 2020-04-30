class Trie {
public:
        struct Node
    {
        bool is_end_;
        Node* next[26];

        Node()
        {
            is_end_ = false;
            for(int i = 0; i < 26; ++i)
                next[i] = NULL;
        }
    };

    Node* root;

    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
        
        // 根节点设为空集的结尾
        root->is_end_ = true;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        
        Node* current = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(current->next[word[i] - 'a'] == NULL)
            {
                Node* tmp = new Node();
                current->next[word[i] - 'a'] = tmp;
                current = tmp;
            }
            else
                current = current->next[word[i] - 'a'];
        }
        current->is_end_ = true;

    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* current = root;
        for(int i = 0; i < word.size(); ++i)
        {
            if(current->next[word[i] - 'a'] == NULL)
            {
                return false;
            }
            else
                current = current->next[word[i] - 'a'];
        }

        if(current->is_end_)
            return true;
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* current = root;
        for(int i = 0; i < prefix.size(); ++i)
        {
            if(current->next[prefix[i] - 'a'] == NULL)
            {
                return false;
            }
            else
                current = current->next[prefix[i] - 'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */