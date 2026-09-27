impl Solution
{
    pub fn hamming_weight(mut n: u32) -> i32
    {
        let mut ret_val = 0;

        while n != 0
        {
            n &= n - 1;
            ret_val += 1;
        }

        ret_val
    }
}
