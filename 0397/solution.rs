impl Solution{pub fn integer_replacement(n:i32)->i32{let mut x=n as i64;let mut c=0;while x!=1{if x&1==0{x>>=1}else if x==3||x&3==1{x-=1}else{x+=1}c+=1;}c}}
