#include <stdlib.h>
typedef struct{struct ListNode*h;}Solution;Solution* solutionCreate(struct ListNode*h){Solution*x=malloc(sizeof(*x));x->h=h;return x;}int solutionGetRandom(Solution*x){int ans=0,i=0;for(struct ListNode*p=x->h;p;p=p->next){i++;if(rand()%i==0)ans=p->val;}return ans;}void solutionFree(Solution*x){free(x);}
