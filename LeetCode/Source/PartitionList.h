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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = head;
        ListNode* current = head;
        while(current)
        {
            if(current->val < x)
            {
                int tmp = less->val;
                less->val = current->val;
                current->val = tmp;
                less = less->next;
            }
            current = current->next;
        }

        return head;
    }
};