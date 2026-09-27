impl Solution{pub fn is_valid_serialization(s:String)->bool{let mut slots=1;for x in s.split(','){if slots==0{return false}slots-=1;if x!="#"{slots+=2}}slots==0}}
