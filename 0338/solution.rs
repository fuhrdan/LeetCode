impl Solution{pub fn count_bits(n:i32)->Vec<i32>{let mut r=vec![0;n as usize+1];for i in 1..=n as usize{r[i]=r[i>>1]+(i&1)as i32;}r}}
