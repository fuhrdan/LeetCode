impl Solution{pub fn is_happy(n:i32)->bool{fn next(mut n:i32)->i32{let mut s=0;while n>0{let d=n%10;s+=d*d;n/=10;}s}let(mut a,mut b)=(n,n);loop{a=next(a);b=next(next(b));if a==b{break}}a==1}}
