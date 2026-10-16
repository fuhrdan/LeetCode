const MOD:i64=1_000_000_007;

struct SegTree { sum:Vec<i64>, sq:Vec<i64>, lazy:Vec<i64> }

impl SegTree
{
    fn new(n:usize)->Self
    {
        let size=n*4+8;
        Self{sum:vec![0;size],sq:vec![0;size],lazy:vec![0;size]}
    }

    fn apply(&mut self,node:usize,l:usize,r:usize,v:i64)
    {
        let len=(r-l+1) as i64;
        let old=self.sum[node];
        self.sq[node]=(self.sq[node]+(2*v%MOD)*old+(v*v%MOD)*(len%MOD))%MOD;
        self.sum[node]=(old+v*(len%MOD))%MOD;
        self.lazy[node]=(self.lazy[node]+v)%MOD;
    }

    fn push(&mut self,node:usize,l:usize,r:usize)
    {
        if self.lazy[node]==0||l==r { return; }
        let m=l+(r-l)/2; let v=self.lazy[node];
        self.apply(node*2,l,m,v); self.apply(node*2+1,m+1,r,v);
        self.lazy[node]=0;
    }

    fn add(&mut self,node:usize,l:usize,r:usize,ql:usize,qr:usize,v:i64)
    {
        if ql<=l&&r<=qr { self.apply(node,l,r,v); return; }
        self.push(node,l,r); let m=l+(r-l)/2;
        if ql<=m { self.add(node*2,l,m,ql,qr,v); }
        if qr>m { self.add(node*2+1,m+1,r,ql,qr,v); }
        self.sum[node]=(self.sum[node*2]+self.sum[node*2+1])%MOD;
        self.sq[node]=(self.sq[node*2]+self.sq[node*2+1])%MOD;
    }
}

impl Solution
{
    pub fn sum_counts(nums:Vec<i32>)->i32
    {
        let n=nums.len();
        let mut tree=SegTree::new(n);
        let mut last=vec![-1_i32;100001];
        let mut ret_val=0_i64;
        for r in 0..n
        {
            let value=nums[r] as usize;
            let start=(last[value]+1) as usize;
            tree.add(1,0,n-1,start,r,1);
            ret_val=(ret_val+tree.sq[1])%MOD;
            last[value]=r as i32;
        }
        ret_val as i32
    }
}
