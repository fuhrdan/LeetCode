#include <stdbool.h>
bool searchMatrix(int**m,int rows,int*cols,int t){int c=cols[0],l=0,r=rows*c-1;while(l<=r){int x=(l+r)/2,v=m[x/c][x%c];if(v==t)return true;if(v<t)l=x+1;else r=x-1;}return false;}
