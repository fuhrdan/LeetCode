impl Solution{pub fn last_remaining(n:i32)->i32{let(mut h,mut s,mut left,mut lr)=(1,1,n,true);while left>1{if lr||left%2==1{h+=s}left/=2;s*=2;lr=!lr}h}}
