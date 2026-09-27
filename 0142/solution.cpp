class Solution{public:ListNode* detectCycle(ListNode*h){auto s=h,*f=h;do{if(!f||!f->next)return nullptr;s=s->next;f=f->next->next;}while(s!=f);s=h;while(s!=f){s=s->next;f=f->next;}return s;}};
