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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy;
        dummy.next = head;
        ListNode* front = &dummy, *end = &dummy;
        while((--n) >= 0)
        {
            end = end->next;
        }
        while(end->next)
        {
            end = end->next;
            front = front->next;
        }

        front->next = front->next->next;
        // 返回dummy.next，不是head
        return dummy.next;
    }
};