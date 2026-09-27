#include <stdlib.h>
typedef struct E{int k,v;struct E*prev,*next;struct E*hnext;}E;typedef struct{int cap,size,buckets;E**tab;E head,tail;}LRUCache;
static unsigned hh(int k){unsigned x=k;x^=x>>16;x*=0x7feb352dU;return x;}
static void detach(E*x){x->prev->next=x->next;x->next->prev=x->prev;}static void front(LRUCache*c,E*x){x->next=c->head.next;x->prev=&c->head;c->head.next->prev=x;c->head.next=x;}
LRUCache* lRUCacheCreate(int capacity){LRUCache*c=calloc(1,sizeof(*c));c->cap=capacity;c->buckets=2048;c->tab=calloc(c->buckets,sizeof(E*));c->head.next=&c->tail;c->tail.prev=&c->head;return c;}
static E*find(LRUCache*c,int k){for(E*x=c->tab[hh(k)%c->buckets];x;x=x->hnext)if(x->k==k)return x;return 0;}
int lRUCacheGet(LRUCache*c,int k){E*x=find(c,k);if(!x)return-1;detach(x);front(c,x);return x->v;}
void lRUCachePut(LRUCache*c,int k,int v){E*x=find(c,k);if(x){x->v=v;detach(x);front(c,x);return;}if(c->size==c->cap){x=c->tail.prev;detach(x);unsigned b=hh(x->k)%c->buckets;E**p=&c->tab[b];while(*p!=x)p=&(*p)->hnext;*p=x->hnext;free(x);c->size--;}x=malloc(sizeof(*x));x->k=k;x->v=v;unsigned b=hh(k)%c->buckets;x->hnext=c->tab[b];c->tab[b]=x;front(c,x);c->size++;}
void lRUCacheFree(LRUCache*c){E*x=c->head.next;while(x!=&c->tail){E*n=x->next;free(x);x=n;}free(c->tab);free(c);}
