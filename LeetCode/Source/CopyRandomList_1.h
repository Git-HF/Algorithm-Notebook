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
        
        Node* current = head;
        Node* tmp;
        while(current)
        {
            tmp = new Node(current->val);
            tmp->next = current->next;
            current->next = tmp;
            current = tmp->next;
        }

        current = head;
        
        while(current)
        {
            //随机指针可能为空
            current->next->random = current->random ? current->random->next : NULL;
            current = current->next->next;
        }


        current = head->next;
        Node* newHead = current;
        Node* pre = head;
        //分离链表
        while(current)
        {
            //主要用来分离两个链表
            pre->next = current->next;
            current->next = pre->next ? pre->next->next : NULL;     //为了处理最后两个结点
            pre = pre->next;
            current = current->next;
        }

        return newHead;
    }
};