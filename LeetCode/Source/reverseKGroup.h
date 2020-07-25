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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int cur = 1;
        ListNode* pre = head;
        ListNode dummy_head;
        ListNode* tail = &dummy_head;
        while(head)
        {
            if(cur == k)
            {
                ListNode* tmp = head->next;
                head->next = NULL;
                pair<ListNode*, ListNode*> res = reverse(pre);
                tail->next = res.first;
                tail = res.second;
                head = tmp;
                cur = 1;
                pre = head;
            }
            else
            {
                head = head->next;
                ++cur;
            }
        }

        if(cur != 1)
            tail->next = pre;

        
        return dummy_head.next;
    }

    pair<ListNode*, ListNode*> reverse(ListNode* head)
    {
        if(head->next == NULL)
            return pair<ListNode*, ListNode*>(head, head);
        ListNode dummy_head;
        ListNode* current = head;

        while(current != NULL)
        {
            ListNode* tmp = current->next;
            current->next = dummy_head.next;
            dummy_head.next = current;
            current = tmp;
        }

        return pair<ListNode*, ListNode*>(dummy_head.next, head);
    }
};