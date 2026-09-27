impl Solution{pub fn max_sub_array(a:Vec<i32>)->i32{let(mut c,mut b)=(a[0],a[0]);for &x in a.iter().skip(1){c=x.max(c+x);b=b.max(c);}b}}
