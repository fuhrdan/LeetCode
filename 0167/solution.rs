impl Solution{pub fn two_sum(a:Vec<i32>,t:i32)->Vec<i32>{let(mut l,mut r)=(0usize,a.len()-1);while l<r{let s=a[l]+a[r];if s==t{return vec![l as i32+1,r as i32+1]}if s<t{l+=1}else{r-=1}}vec![]}}
