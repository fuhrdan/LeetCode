struct ListNode* plusOne(struct ListNode*h){struct ListNode d={0,h},*last=&d,*p=h;while(p){if(p->val!=9)last=p;p=p->next;}last->val++;p=last->next;while(p){p->val=0;p=p->next;}return d.val?&d:h;}
