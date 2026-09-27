impl Solution{pub fn generate(n:i32)->Vec<Vec<i32>>{let mut o=vec![];for i in 0..n as usize{let mut r=vec![1;i+1];for j in 1..i{r[j]=o[i-1][j-1]+o[i-1][j];}o.push(r);}o}}
