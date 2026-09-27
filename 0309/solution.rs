impl Solution{pub fn max_profit(a:Vec<i32>)->i32{if a.is_empty(){return 0}let(mut h,mut s,mut r)=(-a[0],0,0);for &x in a.iter().skip(1){let(ph,ps)=(h,s);h=h.max(r-x);s=ph+x;r=r.max(ps);}s.max(r)}}
