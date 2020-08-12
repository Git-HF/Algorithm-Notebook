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
        ListNode* front = head, *end = head;
        while((--n) >= 0 && end)
        {
            end = end->next;
        }

        // 删除第一个元素时要特殊对待。
        if(!end)
            return head->next;

        while(end->next)
        {
            end = end->next;
            front = front->next;
        }

        front->next = front->next->next;
        return head;
    }
};