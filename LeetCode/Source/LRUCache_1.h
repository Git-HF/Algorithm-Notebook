class LRUCache {
public:
    struct node
    {
        int val, key;
        node *pre, *next;
        node() = default;
        node(int v, int k)
        {
            val = v;
            key = k;
            pre = next = NULL;
        }
    };

    int size = 0;
    int cap;
    map<int, node*> help;
    node dummy;
    node *head, *tail;

    LRUCache(int capacity) {
        cap = capacity;
        head = tail = &dummy;
    }
    
    void del(node* cur)
    {
        if(cur == tail)
        {
            tail = cur->pre;
        }

        node* pre = cur->pre;
        pre->next = cur->next;
        if(cur->next)
            cur->next->pre = pre;
        cur->next = cur->pre = NULL;
    }

    void ins(node* cur)
    {
        tail->next = cur;
        cur->pre = tail;
        tail = tail->next;
    }

    int get(int key) {
        if(help.count(key) == 0)
            return -1;
        
        del(help[key]);
        ins(help[key]);
        return help[key]->val;
    }
    
    void put(int key, int value) {
        if(help.count(key) == 1)
        {
            help[key]->val = value;
            del(help[key]);
            ins(help[key]);
            return;
        }

        node* tmp = new node(value, key);
        help[key] = tmp;
        ins(help[key]);
        
        
        if(size+1 > cap)
        {
            node* del_node = head->next;
            del(del_node);
            help.erase(del_node->key);
            delete del_node;
        }
        else
            ++size;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */