class Solution{public:ListNode* reverseList(ListNode*h){ListNode*p=nullptr;while(h){auto n=h->next;h->next=p;p=h;h=n;}return p;}};
