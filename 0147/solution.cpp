class Solution{public:ListNode* insertionSortList(ListNode*h){ListNode d;while(h){auto n=h->next,*p=&d;while(p->next&&p->next->val<h->val)p=p->next;h->next=p->next;p->next=h;h=n;}return d.next;}};
