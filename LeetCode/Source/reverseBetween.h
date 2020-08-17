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
    pair<ListNode*, ListNode*> myreverse(ListNode* head)
    {
        ListNode dummy;
        ListNode* tail = head;
        cout << tail->val << endl;

        while(head)
        {
            cout << head->val << endl;
            ListNode* tmp = head->next;
            head->next = dummy.next;
            dummy.next = head;
            head = tmp;
        }
        
        return {dummy.next, tail};
    }
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode dummy;
        dummy.next = head;
        ListNode* cur = &dummy;
        int count = 0;
        ListNode* pre_ptr_m = &dummy;
        ListNode* ptr_n = &dummy;

        while(cur != NULL)
        {
            // 如果将cur = cur->next, ++count放在前面，则需要注意pre_ptr_m的初始化，否则不需要
            if(count == m-1)
                pre_ptr_m = cur;
            if(count == n)
            {
                ptr_n = cur;
                cur = cur->next;
                ptr_n->next = NULL;
                pair<ListNode*, ListNode*> res = myreverse(pre_ptr_m->next);
                pre_ptr_m->next = res.first;
                res.second->next = cur;
                break;
            }

            cur = cur->next;
            ++count;
        }
        
        // 对于使用dummy的链表问题，最后都应该返回dummy.next，而不是head。
        // 因为head可能会被改变连接关系。
        return dummy.next;
    }
};