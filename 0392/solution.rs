impl Solution{pub fn is_subsequence(s:String,t:String)->bool{let b=s.as_bytes();let mut i=0;for c in t.bytes(){if i<b.len()&&b[i]==c{i+=1}}i==b.len()}}
