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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB)
            return NULL;
        
        ListNode* endA = headA, *endB = headB;
        int count = 0;
        while(endA)
        {
            ++count;
            endA = endA->next;
        }
        while(endB)
        {
            --count;
            endB = endB->next;
        }

        if(endA != endB)
            return NULL;
        
        endA = headA, endB = headB;
        if(count > 0)
        {
            while(count > 0)
            {
                --count;
                endA = endA->next;
            }  
        }
        else if(count < 0)
        {
            while(count < 0)
            {
                ++count;
                endB = endB->next;
            } 
        }

        while(endA != endB)
        {
            endA = endA->next;
            endB = endB->next;
        }

        return endB;

    }
};