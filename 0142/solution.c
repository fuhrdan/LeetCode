struct ListNode* detectCycle(struct ListNode*h){struct ListNode*s=h,*f=h;do{if(!f||!f->next)return 0;s=s->next;f=f->next->next;}while(s!=f);s=h;while(s!=f){s=s->next;f=f->next;}return s;}
