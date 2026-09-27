use std::collections::HashSet;impl Solution{pub fn contains_duplicate(a:Vec<i32>)->bool{let mut s=HashSet::new();for x in a{if !s.insert(x){return true}}false}}
