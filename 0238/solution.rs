impl Solution{pub fn product_except_self(a:Vec<i32>)->Vec<i32>{let mut r=vec![1;a.len()];let mut p=1;for i in 0..a.len(){r[i]=p;p*=a[i];}p=1;for i in (0..a.len()).rev(){r[i]*=p;p*=a[i];}r}}
