impl Solution{pub fn increasing_triplet(a:Vec<i32>)->bool{let(mut x,mut y)=(i32::MAX,i32::MAX);for v in a{if v<=x{x=v}else if v<=y{y=v}else{return true}}false}}
