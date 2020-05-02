class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* out = NULL;
        while(head){
            ListNode* tmp = out;
            out = head;
            head = head->next;
            out->next = tmp;
        }
        return out;
    }
};
