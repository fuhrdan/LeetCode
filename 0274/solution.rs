impl Solution{pub fn h_index(mut a:Vec<i32>)->i32{a.sort();for i in 0..a.len(){let h=(a.len()-i)as i32;if a[i]>=h{return h}}0}}
