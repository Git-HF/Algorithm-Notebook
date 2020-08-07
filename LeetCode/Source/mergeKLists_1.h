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
    struct cmp
    {
        bool operator()(ListNode* n1, ListNode* n2)
        {
            return n1->val > n2->val;
        } 
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;

        // 注意优先队列的定义方法
        priority_queue<ListNode*, vector<ListNode*>, cmp> help;

        for(int i = 0; i <lists.size(); ++i)
        {
            if(lists[i])
                help.push(lists[i]);
        }

        ListNode dummy;
        ListNode* head = &dummy;

        while(!help.empty())
        {
            ListNode* tmp = help.top();
            help.pop();

            head->next = tmp;
            head = head->next;
            if(tmp->next)
                help.push(tmp->next);
        }

        return dummy.next;

    }
};