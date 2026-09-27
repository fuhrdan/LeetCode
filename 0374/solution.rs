impl Solution{pub unsafe fn guess_number(n:i32)->i32{let(mut l,mut r)=(1i64,n as i64);while l<=r{let m=(l+(r-l)/2)as i32;let g=guess(m);if g==0{return m}if g<0{r=m as i64-1}else{l=m as i64+1}}-1}}
