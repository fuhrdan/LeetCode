impl Solution{pub fn jump(a:Vec<i32>)->i32{let(mut j,mut e,mut f)=(0,0usize,0usize);for i in 0..a.len()-1{f=f.max(i+a[i]as usize);if i==e{j+=1;e=f;}}j}}
