use std::collections::HashSet;

impl Solution
{
    pub fn find_repeated_dna_sequences(s: String) -> Vec<String>
    {
        let mut seen = HashSet::new();
        let mut repeated = HashSet::new();

        for i in 0..=s.len().saturating_sub(10)
        {
            let seq = s[i..i + 10].to_string();

            if !seen.insert(seq.clone())
            {
                repeated.insert(seq);
            }
        }

        repeated.into_iter().collect()
    }
}
