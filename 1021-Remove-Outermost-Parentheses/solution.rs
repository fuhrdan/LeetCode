impl Solution
{
    pub fn remove_outer_parentheses(s: String) -> String
    {
        let mut result = String::with_capacity(s.len());
        let mut depth: i32 = 0;

        for ch in s.chars()
        {
            if ch == '('
            {
                if depth > 0
                {
                    result.push(ch);
                }

                depth += 1;
            }
            else
            {
                depth -= 1;

                if depth > 0
                {
                    result.push(ch);
                }
            }
        }

        result
    }
}
