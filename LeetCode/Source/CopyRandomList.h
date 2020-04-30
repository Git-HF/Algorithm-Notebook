/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;

        unordered_map<Node*, Node*> table;
        Node* current = head;
        while(current)
        {
            table[current] = new Node(current->val);
            current = current->next;
        }

        current = head;
        while(current)
        {
            table[current]->next = table[current->next];
            table[current]->random = table[current->random];
            current = current->next;
        }

        return table[head];
    }
};