impl Solution{pub fn find_min(a:Vec<i32>)->i32{let(mut l,mut r)=(0usize,a.len()-1);while l<r{let m=(l+r)/2;if a[m]>a[r]{l=m+1}else if a[m]<a[r]{r=m}else{r-=1}}a[l]}}
