#include <stdbool.h>
#include <limits.h>
bool verifyPreorder(int*a,int n){int st[10000],top=0,low=INT_MIN;for(int i=0;i<n;i++){if(a[i]<low)return false;while(top&&a[i]>st[top-1])low=st[--top];st[top++]=a[i];}return true;}
