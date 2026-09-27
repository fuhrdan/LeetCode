impl Solution { pub fn reverse(mut x:i32)->i32{ let mut r=0i32; while x!=0{let d=x%10;x/=10;match r.checked_mul(10).and_then(|v|v.checked_add(d)){Some(v)=>r=v,None=>return 0}} r } }
