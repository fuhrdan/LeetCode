impl Solution{pub fn find_duplicate(a:Vec<i32>)->i32{let(mut s,mut f)=(a[0],a[0]);loop{s=a[s as usize];f=a[a[f as usize]as usize];if s==f{break}}s=a[0];while s!=f{s=a[s as usize];f=a[f as usize];}s}}
