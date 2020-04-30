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
    bool hasCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;

        bool isFirst = true;
        while(fast && fast->next)
        {
            if(fast == slow)
            {
                if(isFirst)
                    isFirst = !isFirst;
                else
                    return true;
            }
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};