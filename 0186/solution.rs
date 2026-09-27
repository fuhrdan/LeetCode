impl Solution
{
    pub fn reverse_words(s: &mut Vec<char>)
    {
        s.reverse();

        let mut start = 0;

        for i in 0..=s.len()
        {
            if i == s.len() || s[i] == ' '
            {
                s[start..i].reverse();
                start = i + 1;
            }
        }
    }
}
