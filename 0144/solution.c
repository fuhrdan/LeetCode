#include <stdlib.h>
int* preorderTraversal(struct TreeNode*r,int*rs){int cap=32,c=0,top=0,*o=malloc(cap*sizeof(int));struct TreeNode**st=malloc(2048*sizeof(*st));if(r)st[top++]=r;while(top){struct TreeNode*n=st[--top];if(c==cap){cap*=2;o=realloc(o,cap*sizeof(int));}o[c++]=n->val;if(n->right)st[top++]=n->right;if(n->left)st[top++]=n->left;}free(st);*rs=c;return o;}
