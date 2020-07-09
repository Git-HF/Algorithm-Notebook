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
        // times主要是为了两个链表不相交时，及时终止。
        int times = 0;
        while(times < 2)
        {
            if(endA == endB && endA != NULL)
            {
                return endA;
            }

            if(!endA)
            {
                endA = headB;
                ++times;
            }
            else
                endA = endA->next;
            endB = endB ? endB->next : headA;
        }
        
        return NULL;

    }
};


//------------------下面的执行时间更长。
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
        while(endA != endB)
        {
            endA = endA ? endA->next : headB;
            endB = endB ? endB->next : headA;
        }
        
        return endA;

    }
};