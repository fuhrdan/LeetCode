impl Solution{pub fn integer_break(mut n:i32)->i32{if n<=3{return n-1}let mut r=1;while n>4{r*=3;n-=3}r*n}}
