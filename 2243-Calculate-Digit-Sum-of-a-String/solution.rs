impl Solution
{
    pub fn digit_sum(mut s: String, k: i32) -> String
    {
        let k = k as usize;

        while s.len() > k
        {
            let bytes = s.as_bytes();
            let mut next = String::new();
            let mut i = 0usize;

            while i < bytes.len()
            {
                let end = (i + k).min(bytes.len());
                let mut sum = 0_i32;

                for &digit in &bytes[i..end]
                {
                    sum += (digit - b'0') as i32;
                }

                next.push_str(&sum.to_string());
                i += k;
            }

            s = next;
        }

        s
    }
}
