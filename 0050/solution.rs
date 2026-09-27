impl Solution{pub fn my_pow(mut x:f64,n:i32)->f64{let mut e=n as i64;if e<0{x=1.0/x;e=-e}let mut r=1.0;while e>0{if e&1==1{r*=x}x*=x;e>>=1;}r}}
