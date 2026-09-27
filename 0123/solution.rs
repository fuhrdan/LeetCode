impl Solution{pub fn max_profit(p:Vec<i32>)->i32{let(mut b1,mut s1,mut b2,mut s2)=(i32::MIN,0,i32::MIN,0);for x in p{b1=b1.max(-x);s1=s1.max(b1+x);b2=b2.max(s1-x);s2=s2.max(b2+x);}s2}}
