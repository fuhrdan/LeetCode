impl Solution{pub fn move_zeroes(a:&mut Vec<i32>){let mut j=0;for i in 0..a.len(){if a[i]!=0{a[j]=a[i];j+=1}}while j<a.len(){a[j]=0;j+=1}}}
