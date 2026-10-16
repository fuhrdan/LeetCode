class Solution
{
    static constexpr long long MOD=1000000007LL;
    struct Node { long long sum=0,sq=0,lazy=0; };
    vector<Node> tree;

    void apply(int node,int l,int r,long long v)
    {
        long long len=r-l+1LL, old=tree[node].sum;
        tree[node].sq=(tree[node].sq+2LL*v%MOD*old+v*v%MOD*(len%MOD))%MOD;
        tree[node].sum=(old+v*(len%MOD))%MOD;
        tree[node].lazy=(tree[node].lazy+v)%MOD;
    }

    void push(int node,int l,int r)
    {
        if(tree[node].lazy==0||l==r) return;
        int m=l+(r-l)/2; long long v=tree[node].lazy;
        apply(node*2,l,m,v); apply(node*2+1,m+1,r,v);
        tree[node].lazy=0;
    }

    void add(int node,int l,int r,int ql,int qr,long long v)
    {
        if(ql<=l&&r<=qr){ apply(node,l,r,v); return; }
        push(node,l,r); int m=l+(r-l)/2;
        if(ql<=m) add(node*2,l,m,ql,qr,v);
        if(qr>m) add(node*2+1,m+1,r,ql,qr,v);
        tree[node].sum=(tree[node*2].sum+tree[node*2+1].sum)%MOD;
        tree[node].sq=(tree[node*2].sq+tree[node*2+1].sq)%MOD;
    }

public:
    int sumCounts(vector<int>& nums)
    {
        int n=static_cast<int>(nums.size());
        tree.assign(n*4+8,Node());
        vector<int> last(100001,-1);
        long long retVal=0;
        for(int r=0;r<n;r++)
        {
            int start=last[nums[r]]+1;
            add(1,0,n-1,start,r,1);
            retVal=(retVal+tree[1].sq)%MOD;
            last[nums[r]]=r;
        }
        return static_cast<int>(retVal);
    }
};
