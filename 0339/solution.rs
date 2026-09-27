impl Solution{pub fn depth_sum(a:Vec<NestedInteger>)->i32{fn f(a:&[NestedInteger],d:i32)->i32{a.iter().map(|x|match x{NestedInteger::Int(v)=>v*d,NestedInteger::List(v)=>f(v,d+1)}).sum()}f(&a,1)}}
