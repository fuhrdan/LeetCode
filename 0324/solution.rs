impl Solution{pub fn wiggle_sort(a:&mut Vec<i32>){let mut b=a.clone();b.sort();let(mut l,mut r)=((a.len()-1)/2,a.len()-1);for i in 0..a.len(){if i%2==0{a[i]=b[l];if l>0{l-=1}}else{a[i]=b[r];r-=1}}}}
