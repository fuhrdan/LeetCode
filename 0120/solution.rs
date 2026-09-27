impl Solution{pub fn minimum_total(t:Vec<Vec<i32>>)->i32{let mut d=t.last().unwrap().clone();for i in (0..t.len()-1).rev(){for j in 0..=i{d[j]=t[i][j]+d[j].min(d[j+1]);}}d[0]}}
