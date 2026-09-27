#include <stdbool.h>
bool hasCycle(struct ListNode*h){struct ListNode*s=h,*f=h;while(f&&f->next){s=s->next;f=f->next->next;if(s==f)return true;}return false;}
