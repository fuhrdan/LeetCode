impl Solution{pub fn h_index(a:Vec<i32>)->i32{let n=a.len();let(mut l,mut r)=(0,n);while l<r{let m=(l+r)/2;if a[m]>=(n-m)as i32{r=m}else{l=m+1}}(n-l)as i32}}
