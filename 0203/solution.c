struct ListNode* removeElements(struct ListNode*h,int val){struct ListNode d={0,h},*p=&d;while(p->next){if(p->next->val==val)p->next=p->next->next;else p=p->next;}return d.next;}
