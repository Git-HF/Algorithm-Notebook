class LRUCache {
public:
    struct node
    {
        int val, key;
        struct node *next, *pre;
        node()
        {
            next = pre = NULL;
        }

        node(int tmp_val, int tmp_key)
        {
            next = pre = NULL;
            val = tmp_val;
            key = tmp_key;
        }
    };

    

    int m_size, m_capacity;
    node dummy;
    node *m_front, *m_tail;
    unordered_map<int, node*> help;
    LRUCache(int capacity) {
        m_size = 0;
        m_capacity = capacity;
        m_front = &dummy;
        m_tail = &dummy;
    }
    
    int get(int key) {
        if(help.count(key) == 1)
        {
            delete_node(help[key]);
            insert(help[key]);
            //cout << "get: " << key << " " << help[key]->val << endl;
            return help[key]->val;
            
        }
        else
            return -1;
    }
    
    void put(int key, int value) {
        if(help.count(key) == 1)
        {
            delete_node(help[key]);
            insert(help[key]);
            help[key]->val = value;
            return;
        }

        if(m_size == m_capacity)
        {
            node* dn = m_front->next;
            delete_node(dn);
            
            auto iter = help.find(dn->key);
            help.erase(iter);
            delete dn;
        }
        else
            ++m_size;
        
        node* new_node = new node(value, key);
        insert(new_node);
        
        help[key] = new_node;
    }

    void insert(node* cur_node)
    {
        m_tail->next = cur_node;
        cur_node->pre = m_tail;
        m_tail = cur_node;
    }

    void delete_node(node* dn)
    {
        // 注意更新m_tail节点
        if(dn == m_tail)
            m_tail = dn->pre;

        node* pre_node = dn->pre;
        dn->pre = NULL;
        pre_node->next = dn->next;
        dn->next = NULL;
        if(pre_node->next)
            pre_node->next->pre = pre_node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */