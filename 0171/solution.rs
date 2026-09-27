impl Solution{pub fn title_to_number(s:String)->i32{s.bytes().fold(0,|r,c|r*26+(c-b'A'+1)as i32)}}
