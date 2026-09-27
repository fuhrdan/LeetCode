impl Solution {
    pub fn find_median_sorted_arrays(a: Vec<i32>, b: Vec<i32>) -> f64 {
        if a.len()>b.len() { return Self::find_median_sorted_arrays(b,a); }
        let (m,n)=(a.len(),b.len()); let (mut lo,mut hi)=(0usize,m);
        while lo<=hi {
            let i=(lo+hi)/2; let j=(m+n+1)/2-i;
            let al=if i==0{i32::MIN}else{a[i-1]}; let ar=if i==m{i32::MAX}else{a[i]};
            let bl=if j==0{i32::MIN}else{b[j-1]}; let br=if j==n{i32::MAX}else{b[j]};
            if al<=br && bl<=ar {
                let left=al.max(bl);
                if (m+n)%2==1 { return left as f64; }
                return (left as f64 + ar.min(br) as f64)/2.0;
            }
            if al>br { if i==0 {break;} hi=i-1; } else { lo=i+1; }
        }
        0.0
    }
}
