#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct{int*to,*next,*head,edgeCount;}Graph;
static int *segTree,*lazyTree;
static void addEdge(Graph*g,int u,int v){g->to[g->edgeCount]=v;g->next[g->edgeCount]=g->head[u];g->head[u]=g->edgeCount++;}
static void buildSeg(int node,int l,int r,int*base){if(l==r){segTree[node]=base[l];return;}int m=(l+r)/2;buildSeg(node*2,l,m,base);buildSeg(node*2+1,m+1,r,base);}static void applySeg(int node,int v){segTree[node]^=v;lazyTree[node]^=v;}static void pushSeg(int node){if(lazyTree[node]){applySeg(node*2,lazyTree[node]);applySeg(node*2+1,lazyTree[node]);lazyTree[node]=0;}}static void updateSeg(int node,int l,int r,int ql,int qr,int v){if(qr<l||r<ql)return;if(ql<=l&&r<=qr){applySeg(node,v);return;}pushSeg(node);int m=(l+r)/2;updateSeg(node*2,l,m,ql,qr,v);updateSeg(node*2+1,m+1,r,ql,qr,v);}static int pointSeg(int node,int l,int r,int idx){if(l==r)return segTree[node];pushSeg(node);int m=(l+r)/2;return idx<=m?pointSeg(node*2,l,m,idx):pointSeg(node*2+1,m+1,r,idx);}

bool* palindromePath(int n,int** edges,int edgesSize,int* edgesColSize,char* s,char** queries,int queriesSize,int* returnSize)
{
    (void)edgesColSize;int LOG=1;while((1<<LOG)<=n)LOG++;int ec=2*(n>1?n-1:1);Graph g={(int*)malloc(sizeof(int)*ec),(int*)malloc(sizeof(int)*ec),(int*)malloc(sizeof(int)*n),0};for(int i=0;i<n;i++)g.head[i]=-1;for(int i=0;i<edgesSize;i++){addEdge(&g,edges[i][0],edges[i][1]);addEdge(&g,edges[i][1],edges[i][0]);}
    int*depth=(int*)calloc(n,sizeof(int));int*tin=(int*)malloc(sizeof(int)*n);int*tout=(int*)malloc(sizeof(int)*n);int**up=(int**)malloc(sizeof(int*)*LOG);for(int j=0;j<LOG;j++)up[j]=(int*)malloc(sizeof(int)*n);typedef struct{int u,p,state;}Frame;Frame*st=(Frame*)malloc(sizeof(Frame)*(2*n+5));int top=0,timer=0;st[top++]=(Frame){0,0,0};while(top){Frame f=st[--top];int u=f.u,p=f.p;if(!f.state){tin[u]=timer++;up[0][u]=p;for(int j=1;j<LOG;j++)up[j][u]=up[j-1][up[j-1][u]];st[top++]=(Frame){u,p,1};for(int e=g.head[u];e!=-1;e=g.next[e]){int v=g.to[e];if(v==p)continue;depth[v]=depth[u]+1;st[top++]=(Frame){v,u,0};}}else tout[u]=timer-1;}
    int*label=(int*)malloc(sizeof(int)*n);int*order=(int*)malloc(sizeof(int)*n);int*rx=(int*)malloc(sizeof(int)*n);int*base=(int*)malloc(sizeof(int)*n);for(int i=0;i<n;i++){label[i]=1<<(s[i]-'a');order[tin[i]]=i;}for(int pos=0;pos<n;pos++){int u=order[pos];rx[u]=(u==0?label[u]:rx[up[0][u]]^label[u]);}for(int i=0;i<n;i++)base[tin[i]]=rx[i];segTree=(int*)calloc(4*n+5,sizeof(int));lazyTree=(int*)calloc(4*n+5,sizeof(int));buildSeg(1,0,n-1,base);
    int qc=0;for(int i=0;i<queriesSize;i++)if(queries[i][0]=='q')qc++;bool*ans=(bool*)malloc(sizeof(bool)*qc);int ai=0;
    for(int qi=0;qi<queriesSize;qi++){char type[8],third[16];int u;sscanf(queries[qi],"%7s %d %15s",type,&u,third);if(type[0]=='u'){int nm=1<<(third[0]-'a');int d=label[u]^nm;if(d){updateSeg(1,0,n-1,tin[u],tout[u],d);label[u]=nm;}}else{int v=atoi(third),a=u,b=v;if(depth[a]<depth[b]){int t=a;a=b;b=t;}int diff=depth[a]-depth[b];for(int j=0;j<LOG;j++)if(diff&(1<<j))a=up[j][a];int w;if(a==b)w=a;else{for(int j=LOG-1;j>=0;j--)if(up[j][a]!=up[j][b]){a=up[j][a];b=up[j][b];}w=up[0][a];}int mask=pointSeg(1,0,n-1,tin[u])^pointSeg(1,0,n-1,tin[v])^label[w];ans[ai++]=(mask==0||(mask&(mask-1))==0);}}
    *returnSize=qc;free(segTree);free(lazyTree);for(int j=0;j<LOG;j++)free(up[j]);free(up);free(base);free(rx);free(order);free(label);free(st);free(tout);free(tin);free(depth);free(g.head);free(g.next);free(g.to);return ans;
}
