#include <stdlib.h>
int* inorderTraversal(struct TreeNode*root,int*rs){int cap=32,c=0,top=0;int*o=malloc(cap*sizeof(int));struct TreeNode**st=malloc(1024*sizeof(*st)),*p=root;while(p||top){while(p){st[top++]=p;p=p->left;}p=st[--top];if(c==cap){cap*=2;o=realloc(o,cap*sizeof(int));}o[c++]=p->val;p=p->right;}free(st);*rs=c;return o;}
