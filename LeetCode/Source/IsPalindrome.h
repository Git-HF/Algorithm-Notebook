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
        if(!head)
            return true;
        
        stack<ListNode> helpStack;
        ListNode* p = head;
        while(p)
        {
            helpStack.push(*p);
            p = p->next;
        }

        p = head;
        while(!helpStack.empty())
        {
            if(helpStack.top().val != p->val)
                return false;
            
            helpStack.pop();
            p = p->next;
        }

        return true;
    }
};