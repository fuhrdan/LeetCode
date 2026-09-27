#include <stdlib.h>
#include <stdbool.h>
typedef struct{int*a,*b,na,nb;}MyQueue;MyQueue* myQueueCreate(){MyQueue*q=malloc(sizeof(*q));q->a=malloc(1000*sizeof(int));q->b=malloc(1000*sizeof(int));q->na=q->nb=0;return q;}void myQueuePush(MyQueue*q,int x){q->a[q->na++]=x;}static void mv(MyQueue*q){if(!q->nb)while(q->na)q->b[q->nb++]=q->a[--q->na];}int myQueuePop(MyQueue*q){mv(q);return q->b[--q->nb];}int myQueuePeek(MyQueue*q){mv(q);return q->b[q->nb-1];}bool myQueueEmpty(MyQueue*q){return q->na+q->nb==0;}void myQueueFree(MyQueue*q){free(q->a);free(q->b);free(q);}
