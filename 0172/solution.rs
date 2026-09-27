impl Solution{pub fn trailing_zeroes(mut n:i32)->i32{let mut r=0;while n>0{n/=5;r+=n;}r}}
