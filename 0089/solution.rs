impl Solution{pub fn gray_code(n:i32)->Vec<i32>{(0..1<<n).map(|i|i^(i>>1)).collect()}}
