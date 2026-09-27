#include <stdbool.h>
bool canJump(int*a,int n){int far=0;for(int i=0;i<n;i++){if(i>far)return false;if(i+a[i]>far)far=i+a[i];}return true;}
