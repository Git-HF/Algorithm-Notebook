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
        
        set<ListNode*> helpSet;
        ListNode* current = headA;
        while(current)
        {
            helpSet.insert(current);
            current = current->next;
        }

        current = headB;
        while(current)
        {
            if(helpSet.count(current) == 1)
                return current;
            current = current->next;
        }
        return NULL;
    }
};