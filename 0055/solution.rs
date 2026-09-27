impl Solution{pub fn can_jump(a:Vec<i32>)->bool{let mut f=0usize;for(i,&x)in a.iter().enumerate(){if i>f{return false}f=f.max(i+x as usize);}true}}
