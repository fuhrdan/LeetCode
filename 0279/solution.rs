impl Solution{pub fn num_squares(n:i32)->i32{let n=n as usize;let mut d=vec![0;n+1];for i in 1..=n{d[i]=i as i32;let mut j=1;while j*j<=i{d[i]=d[i].min(d[i-j*j]+1);j+=1;}}d[n]}}
