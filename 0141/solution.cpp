class Solution{public:bool hasCycle(ListNode*h){auto s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;if(s==f)return true;}return false;}};
