class Solution{public:ListNode* removeNthFromEnd(ListNode*h,int n){ListNode d(0,h),*f=&d,*s=&d;while(n--)f=f->next;while(f->next){f=f->next;s=s->next;}s->next=s->next->next;return d.next;}};
