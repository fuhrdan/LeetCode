#include <cstdlib>
class Solution{ListNode*h;public:Solution(ListNode*head):h(head){}int getRandom(){int ans=0,i=0;for(auto p=h;p;p=p->next)if(rand()%++i==0)ans=p->val;return ans;}};
