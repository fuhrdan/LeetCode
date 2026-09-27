impl Solution{pub fn my_sqrt(x:i32)->i32{let(mut l,mut r)=(0i64,x as i64);while l<=r{let m=(l+r)/2;if m*m<=x as i64{l=m+1}else{r=m-1}}r as i32}}
