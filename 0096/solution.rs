impl Solution{pub fn num_trees(n:i32)->i32{let n=n as usize;let mut d=vec![0i32;n+1];d[0]=1;if n>0{d[1]=1}for x in 2..=n{for r in 1..=x{d[x]+=d[r-1]*d[x-r];}}d[n]}}
