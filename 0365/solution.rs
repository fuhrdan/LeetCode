impl Solution{pub fn can_measure_water(x:i32,y:i32,z:i32)->bool{fn g(mut a:i32,mut b:i32)->i32{while b!=0{let t=a%b;a=b;b=t}a}z==0||((x as i64+y as i64)>=z as i64&&z%g(x,y)==0)}}
