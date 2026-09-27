impl Solution{pub fn find_the_difference(s:String,t:String)->char{let x=s.bytes().chain(t.bytes()).fold(0u8,|a,b|a^b);x as char}}
