impl Solution{pub fn is_palindrome(mut x:i32)->bool{if x<0||(x%10==0&&x!=0){return false}let mut r=0;while x>r{r=r*10+x%10;x/=10;}x==r||x==r/10}}
