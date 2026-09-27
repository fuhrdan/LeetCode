impl Solution{pub fn find_peak_element(a:Vec<i32>)->i32{let(mut l,mut r)=(0usize,a.len()-1);while l<r{let m=(l+r)/2;if a[m]<a[m+1]{l=m+1}else{r=m}}l as i32}}
