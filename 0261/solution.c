#include <stdlib.h>
#include <stdbool.h>
static void dfs(int u,int**e,int m,int*vis){vis[u]=1;for(int i=0;i<m;i++){int v=-1;if(e[i][0]==u)v=e[i][1];else if(e[i][1]==u)v=e[i][0];if(v>=0&&!vis[v])dfs(v,e,m,vis);}}bool validTree(int n,int**e,int m,int*cols){if(m!=n-1)return false;int*vis=calloc(n,sizeof(int));dfs(0,e,m,vis);for(int i=0;i<n;i++)if(!vis[i]){free(vis);return false;}free(vis);return true;}
