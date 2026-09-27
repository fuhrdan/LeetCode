#include <stdlib.h>
#include <string.h>
/* C implementation uses BFS distances and predecessor lists.
   Because LeetCode's C return signature is verbose, this implementation is intentionally compact. */
typedef struct P{int v;struct P*n;}P;
static int diff1(const char*a,const char*b){int d=0;for(;*a;a++,b++)d+=*a!=*b;return d==1;}
static void dfs126(int cur,int begin,char**words,P**pre,int*path,int len,char****out,int**cols,int*cnt,int*cap){
    path[len++]=cur;
    if(cur==begin){
        if(*cnt==*cap){*cap*=2;*out=realloc(*out,*cap*sizeof(char**));*cols=realloc(*cols,*cap*sizeof(int));}
        char**r=malloc(len*sizeof(char*));
        for(int i=0;i<len;i++)r[i]=strdup(words[path[len-1-i]]);
        (*out)[*cnt]=r;(*cols)[(*cnt)++]=len;return;
    }
    for(P*p=pre[cur];p;p=p->n)dfs126(p->v,begin,words,pre,path,len,out,cols,cnt,cap);
}
char*** findLadders(char*beginWord,char*endWord,char**wordList,int n,int*returnSize,int**returnColumnSizes){
    int end=-1,begin=n;char**w=malloc((n+1)*sizeof(char*));for(int i=0;i<n;i++){w[i]=wordList[i];if(strcmp(w[i],endWord)==0)end=i;}w[n]=beginWord;
    if(end<0){*returnSize=0;*returnColumnSizes=NULL;free(w);return NULL;}
    int*dist=malloc((n+1)*sizeof(int)),*q=malloc((n+1)*sizeof(int));P**pre=calloc(n+1,sizeof(P*));for(int i=0;i<=n;i++)dist[i]=-1;int h=0,t=0;q[t++]=begin;dist[begin]=0;
    while(h<t){int u=q[h++];for(int v=0;v<n;v++)if(diff1(w[u],w[v])){if(dist[v]<0){dist[v]=dist[u]+1;q[t++]=v;}if(dist[v]==dist[u]+1){P*p=malloc(sizeof(P));p->v=u;p->n=pre[v];pre[v]=p;}}}
    int cap=16,c=0,**cols=malloc(cap*sizeof(int)),*path=malloc((n+1)*sizeof(int));char***out=malloc(cap*sizeof(char**));
    if(dist[end]>=0)dfs126(end,begin,w,pre,path,0,&out,&cols,&c,&cap);
    for(int i=0;i<=n;i++){P*p=pre[i];while(p){P*x=p->n;free(p);p=x;}}free(pre);free(path);free(dist);free(q);free(w);*returnSize=c;*returnColumnSizes=cols;return out;
}
