impl Solution{pub fn convert_to_title(mut n:i32)->String{let mut v=vec![];while n>0{n-=1;v.push((b'A'+(n%26)as u8)as char);n/=26;}v.iter().rev().collect()}}
