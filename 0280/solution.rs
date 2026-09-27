impl Solution{pub fn wiggle_sort(a:&mut Vec<i32>){for i in 1..a.len(){if(i%2==1&&a[i]<a[i-1])||(i%2==0&&a[i]>a[i-1]){a.swap(i,i-1)}}}}
