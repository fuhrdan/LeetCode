#include <stdlib.h>
int kthSmallest(struct TreeNode*r,int k){struct TreeNode**st=malloc(10000*sizeof(*st));int top=0;while(r||top){while(r){st[top++]=r;r=r->left;}r=st[--top];if(--k==0){int v=r->val;free(st);return v;}r=r->right;}free(st);return-1;}
