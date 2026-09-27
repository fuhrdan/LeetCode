struct ListNode* swapPairs(struct ListNode*h){struct ListNode d={0,h},*p=&d;while(p->next&&p->next->next){struct ListNode*a=p->next,*b=a->next;a->next=b->next;b->next=a;p->next=b;p=a;}return d.next;}
