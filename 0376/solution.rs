impl Solution{pub fn wiggle_max_length(a:Vec<i32>)->i32{if a.is_empty(){return 0}let(mut up,mut down)=(1,1);for i in 1..a.len(){if a[i]>a[i-1]{up=down+1}else if a[i]<a[i-1]{down=up+1}}up.max(down)}}
