impl Solution{pub fn search_insert(a:Vec<i32>,t:i32)->i32{let(mut l,mut r)=(0,a.len());while l<r{let m=(l+r)/2;if a[m]<t{l=m+1}else{r=m}}l as i32}}
