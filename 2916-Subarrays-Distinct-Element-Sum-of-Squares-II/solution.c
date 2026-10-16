#include <stdlib.h>
#define MOD 1000000007LL

typedef struct { long long sum, squareSum, lazy; } Node;
static Node* tree;

static void applyAdd(int node,int left,int right,long long v)
{
    long long len=right-left+1LL, old=tree[node].sum;
    tree[node].squareSum=(tree[node].squareSum+2LL*v%MOD*old+v*v%MOD*(len%MOD))%MOD;
    tree[node].sum=(old+v*(len%MOD))%MOD;
    tree[node].lazy=(tree[node].lazy+v)%MOD;
}

static void push(int node,int left,int right)
{
    if(tree[node].lazy==0||left==right) return;
    int mid=left+(right-left)/2;
    long long v=tree[node].lazy;
    applyAdd(node*2,left,mid,v);
    applyAdd(node*2+1,mid+1,right,v);
    tree[node].lazy=0;
}

static void add(int node,int left,int right,int ql,int qr,long long v)
{
    if(ql<=left&&right<=qr){ applyAdd(node,left,right,v); return; }
    push(node,left,right);
    int mid=left+(right-left)/2;
    if(ql<=mid) add(node*2,left,mid,ql,qr,v);
    if(qr>mid) add(node*2+1,mid+1,right,ql,qr,v);
    tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
    tree[node].squareSum=(tree[node*2].squareSum+tree[node*2+1].squareSum)%MOD;
}

int sumCounts(int* nums,int numsSize)
{
    tree=(Node*)calloc((size_t)numsSize*4+8,sizeof(Node));
    int* last=(int*)malloc(100001*sizeof(int));
    for(int i=0;i<=100000;i++) last[i]=-1;
    long long retVal=0;
    for(int r=0;r<numsSize;r++)
    {
        int start=last[nums[r]]+1;
        add(1,0,numsSize-1,start,r,1);
        retVal=(retVal+tree[1].squareSum)%MOD;
        last[nums[r]]=r;
    }
    free(last); free(tree);
    return (int)retVal;
}
