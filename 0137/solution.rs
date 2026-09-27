impl Solution{pub fn single_number(a:Vec<i32>)->i32{let(mut o,mut t)=(0,0);for x in a{o=(o^x)&!t;t=(t^x)&!o;}o}}
