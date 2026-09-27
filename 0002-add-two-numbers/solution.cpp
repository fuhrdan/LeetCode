class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy, *tail=&dummy; int carry=0;
        while(l1||l2||carry){
            int sum=carry+(l1?l1->val:0)+(l2?l2->val:0);
            tail->next=new ListNode(sum%10); tail=tail->next; carry=sum/10;
            if(l1) l1=l1->next; if(l2) l2=l2->next;
        }
        return dummy.next;
    }
};
