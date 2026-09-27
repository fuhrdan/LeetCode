impl Solution{pub fn range_bitwise_and(mut left:i32,mut right:i32)->i32{let mut s=0;while left<right{left>>=1;right>>=1;s+=1;}left<<s}}
