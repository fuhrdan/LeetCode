impl Solution{pub fn max_profit(p:Vec<i32>)->i32{let(mut mn,mut b)=(i32::MAX,0);for x in p{mn=mn.min(x);b=b.max(x-mn);}b}}
