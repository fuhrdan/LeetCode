struct ListNode* reverseList(struct ListNode*h){struct ListNode*p=0;while(h){struct ListNode*n=h->next;h->next=p;p=h;h=n;}return p;}
