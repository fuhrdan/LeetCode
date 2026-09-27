class Solution{public:ListNode* swapPairs(ListNode*h){ListNode d(0,h),*p=&d;while(p->next&&p->next->next){auto a=p->next,b=a->next;a->next=b->next;b->next=a;p->next=b;p=a;}return d.next;}};
