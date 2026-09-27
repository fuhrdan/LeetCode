impl Solution {
    pub fn longest_palindrome(s: String) -> String {
        let b=s.as_bytes(); let n=b.len(); let (mut best_l,mut best)=(0usize,1usize);
        for c in 0..n { for t in 0..2 {
            let mut l=c as isize; let mut r=(c+t) as isize;
            while l>=0 && r<n as isize && b[l as usize]==b[r as usize] {
                let len=(r-l+1) as usize; if len>best {best=len;best_l=l as usize;} l-=1;r+=1;
            }
        }}
        s[best_l..best_l+best].to_string()
    }
}
