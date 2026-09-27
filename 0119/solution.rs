impl Solution{pub fn get_row(n:i32)->Vec<i32>{let mut r=vec![0;n as usize+1];r[0]=1;for i in 1..=n as usize{for j in (1..=i).rev(){r[j]+=r[j-1];}}r}}
