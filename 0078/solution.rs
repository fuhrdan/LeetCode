impl Solution{pub fn subsets(a:Vec<i32>)->Vec<Vec<i32>>{let mut o=vec![vec![]];for x in a{let add:Vec<Vec<i32>>=o.iter().map(|v|{let mut q=v.clone();q.push(x);q}).collect();o.extend(add);}o}}
