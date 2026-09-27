#include <stdbool.h>
bool isPalindrome(struct ListNode*h){if(!h||!h->next)return true;struct ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;}struct ListNode*p=0;while(s){struct ListNode*n=s->next;s->next=p;p=s;s=n;}while(p){if(h->val!=p->val)return false;h=h->next;p=p->next;}return true;}
