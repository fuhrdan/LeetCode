impl Solution{pub fn can_permute_palindrome(s:String)->bool{let mut c=[0i32;256];let mut odd=0;for b in s.bytes(){c[b as usize]+=1;odd+=if c[b as usize]%2==1{1}else{-1};}odd<=1}}
