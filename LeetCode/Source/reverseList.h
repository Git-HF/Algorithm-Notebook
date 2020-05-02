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
    ListNode reverse_head_;

    ListNode* reverseList(ListNode* head) {

        
        process(head);

        return reverse_head_.next;

    }

    ListNode* process(ListNode* head)
    {
        if(head == NULL)
            return &reverse_head_;
        else
        {
            ListNode* tail = process(head->next);
            tail->next = head;
            head->next = NULL;
            return head;
        }
    }
};