impl Solution{pub fn is_anagram(s:String,t:String)->bool{let mut c=[0i32;26];for b in s.bytes(){c[(b-b'a')as usize]+=1}for b in t.bytes(){c[(b-b'a')as usize]-=1}c.iter().all(|&x|x==0)}}
