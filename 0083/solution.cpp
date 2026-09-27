class Solution{public:ListNode* deleteDuplicates(ListNode*h){for(auto p=h;p&&p->next;)if(p->val==p->next->val)p->next=p->next->next;else p=p->next;return h;}};
