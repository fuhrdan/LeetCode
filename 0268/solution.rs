impl Solution{pub fn missing_number(a:Vec<i32>)->i32{let mut x=a.len()as i32;for(i,v)in a.into_iter().enumerate(){x^=i as i32^v;}x}}
