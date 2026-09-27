impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        let sb=s.as_bytes(); let mut need=[0i32;128]; let mut missing=t.len() as i32;
        for b in t.bytes(){need[b as usize]+=1;}
        let(mut l,mut best_l,mut best)=(0usize,0usize,usize::MAX);
        for r in 0..sb.len(){
            let c=sb[r] as usize; if need[c]>0{missing-=1;} need[c]-=1;
            while missing==0{
                if r-l+1<best{best=r-l+1;best_l=l;}
                let x=sb[l] as usize;l+=1;need[x]+=1;if need[x]>0{missing+=1;}
            }
        }
        if best==usize::MAX{String::new()}else{s[best_l..best_l+best].to_string()}
    }
}
