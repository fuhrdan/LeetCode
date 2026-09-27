// LeetCode provides knows(a, b) in supported runtimes.
// Eliminate candidates left-to-right, then verify the survivor.
impl Solution{pub fn find_celebrity(&self,n:i32)->i32{let mut c=0;for i in 1..n{if self.knows(c,i){c=i}}for i in 0..n{if i!=c&&(self.knows(c,i)||!self.knows(i,c)){return -1}}c}}
