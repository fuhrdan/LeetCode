impl Solution{pub fn single_number(a:Vec<i32>)->i32{a.into_iter().fold(0,|x,v|x^v)}}
