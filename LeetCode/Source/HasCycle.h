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
        set<ListNode*> helpSet;
        ListNode* current = head;
        while(current)
        {
            if(helpSet.count(current) == 0)
                helpSet.insert(current);
            else
                return true;
            current = current->next;
        }
        return false;
    }
};