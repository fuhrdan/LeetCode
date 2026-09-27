impl Solution{pub fn first_bad_version(&self,n:i32)->i32{let(mut l,mut r)=(1i64,n as i64);while l<r{let m=l+(r-l)/2;if self.is_bad_version(m as i32){r=m}else{l=m+1}}l as i32}}
