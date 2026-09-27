impl Solution{pub fn min_patches(a:Vec<i32>,n:i32)->i32{let(mut miss,mut i,mut c)=(1i64,0usize,0);while miss<=n as i64{if i<a.len()&&a[i]as i64<=miss{miss+=a[i]as i64;i+=1}else{miss+=miss;c+=1}}c}}
