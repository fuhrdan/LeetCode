impl Solution{pub fn unique_paths_with_obstacles(g:Vec<Vec<i32>>)->i32{let n=g[0].len();let mut d=vec![0;n];d[0]=1;for r in g{for j in 0..n{if r[j]==1{d[j]=0}else if j>0{d[j]+=d[j-1]}}}d[n-1]}}
