#include <stdlib.h>
#include <string.h>
static void qbt(int n,int row,int cols,int d1,int d2,char***board,char****out,int*cnt,int*cap){
    if(row==n){if(*cnt==*cap){*cap*=2;*out=realloc(*out,*cap*sizeof(char**));}char**b=malloc(n*sizeof(char*));for(int i=0;i<n;i++){b[i]=malloc(n+1);memcpy(b[i],(*board)[i],n+1);}(*out)[(*cnt)++]=b;return;}
    int avail=((1<<n)-1)&~(cols|d1|d2);
    while(avail){int bit=avail&-avail, col=0;while((1<<col)!=bit)col++;avail-=bit;(*board)[row][col]='Q';qbt(n,row+1,cols|bit,(d1|bit)<<1,(d2|bit)>>1,board,out,cnt,cap);(*board)[row][col]='.';}
}
char*** solveNQueens(int n,int*returnSize,int**returnColumnSizes){int cap=16,c=0;char***o=malloc(cap*sizeof(char**));char**b=malloc(n*sizeof(char*));for(int i=0;i<n;i++){b[i]=malloc(n+1);memset(b[i],'.',n);b[i][n]=0;}qbt(n,0,0,0,0,&b,&o,&c,&cap);for(int i=0;i<n;i++)free(b[i]);free(b);int*cols=malloc(c*sizeof(int));for(int i=0;i<c;i++)cols[i]=n;*returnSize=c;*returnColumnSizes=cols;return o;}
