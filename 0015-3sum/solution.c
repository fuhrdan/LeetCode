#include <stdlib.h>
static int cmpi(const void*a,const void*b){int x=*(int*)a,y=*(int*)b;return(x>y)-(x<y);}
int** threeSum(int* a,int n,int* returnSize,int** returnColumnSizes){
    qsort(a,n,sizeof(int),cmpi);int cap=16,cnt=0;int**out=malloc(cap*sizeof(int*));int*cols=malloc(cap*sizeof(int));
    for(int i=0;i<n-2;i++){if(i&&a[i]==a[i-1])continue;int l=i+1,r=n-1;while(l<r){long sum=(long)a[i]+a[l]+a[r];if(sum<0)l++;else if(sum>0)r--;else{if(cnt==cap){cap*=2;out=realloc(out,cap*sizeof(int*));cols=realloc(cols,cap*sizeof(int));}out[cnt]=malloc(3*sizeof(int));out[cnt][0]=a[i];out[cnt][1]=a[l];out[cnt][2]=a[r];cols[cnt++]=3;int x=a[l],y=a[r];while(l<r&&a[l]==x)l++;while(l<r&&a[r]==y)r--;}}}
    *returnSize=cnt;*returnColumnSizes=cols;return out;
}
