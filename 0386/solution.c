#include <stdlib.h>
int* lexicalOrder(int n,int*rs){int*r=malloc(n*sizeof(int)),cur=1;for(int i=0;i<n;i++){r[i]=cur;if((long long)cur*10<=n)cur*=10;else{while(cur%10==9||cur+1>n)cur/=10;cur++;}}*rs=n;return r;}
