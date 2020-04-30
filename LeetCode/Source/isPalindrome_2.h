class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        if(!head->next)
            return true;
        
        ListNode* fast = head;  //fast一次走两步，slow一次走一步
        ListNode* slow = head;
        ListNode* pre = NULL;    //作用：反转链表充当slow的前驱指针

        //反转前半部分，slow和pre作为判断回文链表的双指针
        while(fast && fast->next){    //奇数链：slow位于链表中点，pre位于待判断的前半部分的第一位
                                      //偶数链：slow位于待判断的后半部分的第一位，pre位于待判断的前半部分的第一位
            fast = fast->next->next;

            ListNode *nex = slow->next;
            //反转
            slow->next = pre;
            //更新
            pre = slow;
            slow = nex;
        }

        if(fast) //判断奇数链
            slow = slow->next;   //slow移动到待判断的后半部分的第一位
        
        //判断回文
        while(slow && pre){
            if(slow->val != pre->val)
                return false;
            slow = slow->next;
            pre = pre->next;
        }

        return true;
    }
};