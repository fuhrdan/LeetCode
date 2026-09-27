impl Solution{pub fn count_numbers_with_unique_digits(mut n:i32)->i32{if n==0{return 1}n=n.min(10);let(mut r,mut cur,mut a)=(10,9,9);for _ in 2..=n{cur*=a;a-=1;r+=cur}r}}
