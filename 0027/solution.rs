impl Solution{pub fn remove_element(a:&mut Vec<i32>,v:i32)->i32{let mut w=0;for i in 0..a.len(){if a[i]!=v{a[w]=a[i];w+=1;}}w as i32}}
