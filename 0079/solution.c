#include <stdbool.h>
#include <string.h>
static bool dfs(char**b,int m,int n,int i,int j,char*w,int k){if(!w[k])return true;if(i<0||i>=m||j<0||j>=n||b[i][j]!=w[k])return false;char c=b[i][j];b[i][j]=0;bool ok=dfs(b,m,n,i+1,j,w,k+1)||dfs(b,m,n,i-1,j,w,k+1)||dfs(b,m,n,i,j+1,w,k+1)||dfs(b,m,n,i,j-1,w,k+1);b[i][j]=c;return ok;}bool exist(char**b,int m,int*cols,char*w){int n=cols[0];for(int i=0;i<m;i++)for(int j=0;j<n;j++)if(dfs(b,m,n,i,j,w,0))return true;return false;}
