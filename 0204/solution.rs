impl Solution{pub fn count_primes(n:i32)->i32{let n=n as usize;if n<=2{return 0}let mut c=vec![false;n];let mut r=0;for i in 2..n{if !c[i]{r+=1;if i*i<n{for j in (i*i..n).step_by(i){c[j]=true;}}}}r}}
