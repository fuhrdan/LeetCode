impl Solution{pub fn rotate(m:&mut Vec<Vec<i32>>){let n=m.len();for i in 0..n{for j in i+1..n{let t=m[i][j];m[i][j]=m[j][i];m[j][i]=t;}}for r in m{r.reverse();}}}
