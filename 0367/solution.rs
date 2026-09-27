impl Solution{pub fn is_perfect_square(n:i32)->bool{let(mut l,mut r)=(1i64,n as i64);while l<=r{let m=(l+r)/2;let v=m*m;if v==n as i64{return true}if v<n as i64{l=m+1}else{r=m-1}}false}}
