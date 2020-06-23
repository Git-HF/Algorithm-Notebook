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
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        int length = 0;
        ListNode* tmp = head;
        while(tmp)
        {
            ++length;
            tmp = tmp->next;
        }
        //cout << length << endl;

        int current_L = 1;
        
        ListNode tmp_node = ListNode(-1);
        tmp_node.next = head;
        
        // 这里不需要等于
        while(current_L < length)
        {
            ListNode* p = tmp_node.next;
            ListNode* sort_l = &tmp_node;
            while(p)
            {
                ListNode* left = p;
                p = cut_list(left, current_L);

                ListNode* right = p;
                p = cut_list(right, current_L);
                
                pair<ListNode*, ListNode*> res = merge(left, right);
                sort_l->next = res.first;
                sort_l = res.second;

            }
            current_L *= 2;
        }

        return tmp_node.next;
    }


    ListNode* cut_list(ListNode* L, int n )
    {
        if(L == NULL)
            return NULL;
        /*
        --n;
        while(n > 0)
        {
            if(L)
            {
                L = L->next;
                --n;
            }
            else
                break;    
        }
        */

        while(--n & L)
        {
            L = L->next
        }

        ListNode* left = NULL;
        if(L)
        {
            left = L->next;
            L->next = NULL;
        }

        return left;
    }

    // 该函数不能返回归并后链表的尾节点，否则找不到头节点了
    std::pair<ListNode*, ListNode*> merge(ListNode* L1, ListNode* L2)
    {
        ListNode tmp_node;
        ListNode* head = &tmp_node;

        while(L1 && L2)
        {
            if(L1->val < L2->val)
            {
                head->next = L1;
                L1 = L1->next;
                head = head->next;
            }
            else
            {
                head->next = L2;
                L2 = L2->next;
                head = head->next;
            } 
        }

        if(L1)
            head->next = L1;
        else
            head->next = L2;

        while(head->next)
            head = head->next;
        return pair<ListNode*, ListNode*>(tmp_node.next, head);
    }
};