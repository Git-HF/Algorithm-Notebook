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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;

        ListNode* fast = head, *slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = inverse_list(slow);
        ListNode* help = head;
        while(fast)
        {
            if(fast->val != help->val)
            {
                inverse_list(slow);
                return false;
            }
            fast = fast->next;
            help = help->next;
        }
        inverse_list(slow);
        return true;
    }

    ListNode* inverse_list(ListNode* head)
    {
        if(!head)
            return NULL;

        ListNode* current = head->next;
        head->next = NULL;
        ListNode* next;
        while(current)
        {
            next = current->next;
            current->next = head;
            head = current;
            current = next;
        }

        return head;
    }
};