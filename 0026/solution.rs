impl Solution{pub fn remove_duplicates(a:&mut Vec<i32>)->i32{if a.is_empty(){return 0}let mut w=1;for i in 1..a.len(){if a[i]!=a[w-1]{a[w]=a[i];w+=1;}}w as i32}}
