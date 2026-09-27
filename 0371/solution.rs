impl Solution{pub fn get_sum(mut a:i32,mut b:i32)->i32{while b!=0{let c=((a as u32&b as u32)<<1)as i32;a^=b;b=c;}a}}
