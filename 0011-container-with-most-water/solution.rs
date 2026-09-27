impl Solution{pub fn max_area(h:Vec<i32>)->i32{let(mut l,mut r,mut b)=(0usize,h.len()-1,0);while l<r{b=b.max(h[l].min(h[r])*(r-l)as i32);if h[l]<h[r]{l+=1}else{r-=1}}b}}
