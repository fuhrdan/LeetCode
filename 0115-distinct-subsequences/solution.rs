impl Solution{pub fn num_distinct(s:String,t:String)->i32{let mut d=vec![0u64;t.len()+1];d[0]=1;for c in s.bytes(){for j in (0..t.len()).rev(){if c==t.as_bytes()[j]{d[j+1]+=d[j];}}}d[t.len()]as i32}}
