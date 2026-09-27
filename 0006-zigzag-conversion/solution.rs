impl Solution {
    pub fn convert(s:String, rows:i32)->String{
        let n=s.len(); let rows=rows as usize; if rows==1||rows>=n{return s;}
        let b=s.as_bytes(); let cycle=2*rows-2; let mut out=String::with_capacity(n);
        for r in 0..rows { let mut i=r; while i<n { out.push(b[i] as char); let j=i+cycle-2*r; if r>0&&r<rows-1&&j<n{out.push(b[j] as char);} i+=cycle; } }
        out
    }
}
