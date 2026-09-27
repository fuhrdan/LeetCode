struct ListNode* deleteDuplicates(struct ListNode*h){struct ListNode*p=h;while(p&&p->next){if(p->val==p->next->val)p->next=p->next->next;else p=p->next;}return h;}
