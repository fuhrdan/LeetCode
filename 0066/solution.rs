impl Solution{pub fn plus_one(mut d:Vec<i32>)->Vec<i32>{for i in (0..d.len()).rev(){if d[i]<9{d[i]+=1;return d}d[i]=0;}d.insert(0,1);d}}
