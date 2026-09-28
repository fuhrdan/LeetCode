impl Solution
{
    pub fn max_depth(s: String) -> i32
    {
        let mut depth = 0;
        let mut ret_val = 0;

        for c in s.chars()
        {
            if c == '('
            {
                depth += 1;
                ret_val = ret_val.max(depth);
            }
            else if c == ')'
            {
                depth -= 1;
            }
        }

        ret_val
    }
}
