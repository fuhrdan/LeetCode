impl Solution{pub fn majority_element(a:Vec<i32>)->i32{let(mut c,mut x)=(0,0);for v in a{if c==0{x=v}c+=if v==x{1}else{-1};}x}}
