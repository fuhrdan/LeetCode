impl Solution{pub fn unique_paths(m:i32,n:i32)->i32{let mut d=vec![1;n as usize];for _ in 1..m{for j in 1..n as usize{d[j]+=d[j-1];}}d[n as usize-1]}}
