impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut last=[-1i32;256]; let mut left=0i32; let mut best=0i32;
        for (r,b) in s.bytes().enumerate() {
            let r=r as i32; left=left.max(last[b as usize]+1); last[b as usize]=r; best=best.max(r-left+1);
        }
        best
    }
}
