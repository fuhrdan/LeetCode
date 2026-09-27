#include <stdlib.h>
int largestRectangleArea(int*h,int n){int*st=malloc((n+1)*sizeof(int)),top=-1,b=0;for(int i=0;i<=n;i++){int cur=i==n?0:h[i];while(top>=0&&h[st[top]]>cur){int ht=h[st[top--]],l=top>=0?st[top]:-1,a=ht*(i-l-1);if(a>b)b=a;}st[++top]=i;}free(st);return b;}
