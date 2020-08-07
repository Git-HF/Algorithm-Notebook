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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return process(lists, 0, lists.size()-1);
    }

    ListNode* process(vector<ListNode*>&lists, int left, int right)
    {
        if(left > right)
            return NULL;
        else if(left == right)
            return lists[left];
        
        int mid = (left + right) / 2;
        
        return merge(process(lists, left, mid), process(lists, mid+1, right));
    }

    ListNode* merge(ListNode* head1, ListNode* head2)
    {
        if(!head1)
            return head2;
        else if(!head2)
            return head1;
        
        ListNode dummy;
        ListNode* res = &dummy;
        while(head1 && head2)
        {
            if(head1->val < head2->val)
            {
                ListNode* tmp = head1->next;
                res->next = head1;
                res = res->next;
                head1 = tmp;
            }
            else
            {
                ListNode* tmp = head2->next;
                res->next = head2;
                res = res->next;
                head2 = tmp;
            }
        }

        if(head1)
        {
            res->next = head1;
        }

        if(head2)
        {
            res->next = head2;
        }

        return dummy.next;
    }

};