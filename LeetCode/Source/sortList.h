/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* fast = head->next, *low = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            low = low->next;
        }

        fast = low->next;
        low->next = NULL;

        // 注意这里不是sortList(low)
        low = sortList(head);
        fast = sortList(fast);

        return merge(low, fast);
    }

    ListNode* merge(ListNode* L1, ListNode* L2)
    {
        if(L1 == NULL)
            return L2;
        else if (L2 == NULL)
            return L1;
        
        ListNode tmp_node;
        ListNode* head = &tmp_node;
        while(L1 && L2)
        {
            if(L1->val < L2->val)
            {
                head->next = L1;
                L1 = L1->next;
                head = head->next;
            }
            else
            {
                head->next = L2;
                L2 = L2->next;
                head = head->next;
            } 
        }

        if(L1)
            head->next = L1;
        else
            head->next = L2; 
        return tmp_node.next;
    }
};