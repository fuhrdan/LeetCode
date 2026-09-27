#include <stdbool.h>
bool searchMatrix(int**m,int rows,int*cols,int target){if(!rows)return false;int r=0,c=cols[0]-1;while(r<rows&&c>=0){int v=m[r][c];if(v==target)return true;if(v>target)c--;else r++;}return false;}
