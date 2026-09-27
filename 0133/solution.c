#include <stdlib.h>
/* LeetCode C graph Node layouts vary. This version assumes:
struct Node { int val; int numNeighbors; struct Node** neighbors; };
*/
typedef struct Map{struct Node*old,*copy;struct Map*next;}Map;static struct Node*cl(struct Node*n,Map**m){if(!n)return NULL;for(Map*p=*m;p;p=p->next)if(p->old==n)return p->copy;struct Node*c=malloc(sizeof(*c));c->val=n->val;c->numNeighbors=n->numNeighbors;c->neighbors=malloc(c->numNeighbors*sizeof(struct Node*));Map*x=malloc(sizeof(Map));x->old=n;x->copy=c;x->next=*m;*m=x;for(int i=0;i<c->numNeighbors;i++)c->neighbors[i]=cl(n->neighbors[i],m);return c;}struct Node* cloneGraph(struct Node*node){Map*m=NULL;struct Node*r=cl(node,&m);while(m){Map*x=m->next;free(m);m=x;}return r;}
