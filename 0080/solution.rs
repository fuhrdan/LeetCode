impl Solution{pub fn remove_duplicates(a:&mut Vec<i32>)->i32{let mut w=0;for i in 0..a.len(){if w<2||a[i]!=a[w-2]{a[w]=a[i];w+=1;}}w as i32}}
