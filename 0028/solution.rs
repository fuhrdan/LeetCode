impl Solution{pub fn str_str(h:String,n:String)->i32{h.find(&n).map(|x|x as i32).unwrap_or(-1)}}
