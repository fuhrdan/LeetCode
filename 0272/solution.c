#include <stdlib.h>
#include <math.h>
static void ino(struct TreeNode*n,int*a,int*c){if(!n)return;ino(n->left,a,c);a[(*c)++]=n->val;ino(n->right,a,c);}int* closestKValues(struct TreeNode*r,double t,int k,int*rs){int*a=malloc(10000*sizeof(int)),n=0;ino(r,a,&n);int best=0;for(int i=1;i+k<=n;i++)if(fabs(a[i+k-1]-t)<fabs(a[best]-t))best=i;int*o=malloc(k*sizeof(int));for(int i=0;i<k;i++)o[i]=a[best+i];free(a);*rs=k;return o;}
