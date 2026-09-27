impl Solution{pub fn rob(a:Vec<i32>)->i32{fn f(a:&[i32])->i32{let(mut p2,mut p1)=(0,0);for &x in a{let c=p1.max(p2+x);p2=p1;p1=c;}p1}if a.len()==1{a[0]}else{f(&a[..a.len()-1]).max(f(&a[1..]))}}}
