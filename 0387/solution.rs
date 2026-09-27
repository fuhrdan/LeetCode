impl Solution{pub fn first_uniq_char(s:String)->i32{let mut c=[0;26];for b in s.bytes(){c[(b-b'a')as usize]+=1}for(i,b)in s.bytes().enumerate(){if c[(b-b'a')as usize]==1{return i as i32}}-1}}
