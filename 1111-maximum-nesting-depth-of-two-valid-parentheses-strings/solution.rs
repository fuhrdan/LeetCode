impl Solution
{
    pub fn max_depth_after_split(seq: String) -> Vec<i32>
    {
        let mut ret_val = Vec::with_capacity(seq.len());
        let mut depth = 0;

        for c in seq.chars()
        {
            if c == '('
            {
                ret_val.push(depth & 1);
                depth += 1;
            }
            else
            {
                depth -= 1;
                ret_val.push(depth & 1);
            }
        }

        ret_val
    }
}
