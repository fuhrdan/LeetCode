class Solution
{
    private static final long MOD=1_000_000_007L;
    private long[] sum,sq,lazy;

    private void apply(int node,int l,int r,long v)
    {
        long len=r-l+1L, old=sum[node];
        sq[node]=(sq[node]+(2L*v%MOD)*old+(v*v%MOD)*(len%MOD))%MOD;
        sum[node]=(old+v*(len%MOD))%MOD;
        lazy[node]=(lazy[node]+v)%MOD;
    }

    private void push(int node,int l,int r)
    {
        if(lazy[node]==0||l==r) return;
        int m=l+(r-l)/2; long v=lazy[node];
        apply(node*2,l,m,v); apply(node*2+1,m+1,r,v);
        lazy[node]=0;
    }

    private void add(int node,int l,int r,int ql,int qr,long v)
    {
        if(ql<=l&&r<=qr){ apply(node,l,r,v); return; }
        push(node,l,r); int m=l+(r-l)/2;
        if(ql<=m) add(node*2,l,m,ql,qr,v);
        if(qr>m) add(node*2+1,m+1,r,ql,qr,v);
        sum[node]=(sum[node*2]+sum[node*2+1])%MOD;
        sq[node]=(sq[node*2]+sq[node*2+1])%MOD;
    }

    public int sumCounts(java.util.List<Integer> nums)
    {
        int n=nums.size();
        sum=new long[n*4+8]; sq=new long[n*4+8]; lazy=new long[n*4+8];
        int[] last=new int[100001];
        java.util.Arrays.fill(last,-1);
        long retVal=0;
        for(int r=0;r<n;r++)
        {
            int value=nums.get(r), start=last[value]+1;
            add(1,0,n-1,start,r,1);
            retVal=(retVal+sq[1])%MOD;
            last[value]=r;
        }
        return (int)retVal;
    }
}
