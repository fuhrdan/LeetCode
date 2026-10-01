impl Solution
{
    fn keyboard_row(c: char) -> i32
    {
        let c = c.to_ascii_lowercase();

        if "qwertyuiop".contains(c)
        {
            return 1;
        }

        if "asdfghjkl".contains(c)
        {
            return 2;
        }

        3
    }

    pub fn find_words(words: Vec<String>) -> Vec<String>
    {
        let mut ret_val = Vec::new();

        for word in words
        {
            let mut chars = word.chars();

            let Some(first) = chars.next() else
            {
                continue;
            };

            let row = Self::keyboard_row(first);

            if chars.all(|c| Self::keyboard_row(c) == row)
            {
                ret_val.push(word);
            }
        }

        ret_val
    }
}
