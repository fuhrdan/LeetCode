impl Solution{pub fn can_attend_meetings(mut a:Vec<Vec<i32>>)->bool{a.sort_by_key(|x|x[0]);for i in 1..a.len(){if a[i][0]<a[i-1][1]{return false}}true}}
