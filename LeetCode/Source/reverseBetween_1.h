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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        int count = 0;
        ListNode dummy;
        dummy.next = head;
        ListNode* cur = &dummy;
        while(count != (m-1))
        {
            cur = cur->next;
            ++count;
            cout << cur->val << endl;
        }

        ListNode* tail = cur;
        
        // 记录尾节点，不能丢
        ListNode* tail_other = cur->next;
        cur = cur->next;
        // 不能丢，并且不能放在cur = cur->next之前。
        tail->next = NULL;
        //不能丢
        ++count;
        while(count <= n)
        {
            cout << cur->val << endl;

            ListNode* tmp = cur->next;
            cur->next = tail->next;
            tail->next = cur;
            cur = tmp;
            ++count;
        }

        tail_other->next = cur;
        return dummy.next;
    }
};