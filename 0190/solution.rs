impl Solution
{
    pub fn reverse_bits(mut n: u32) -> u32
    {
        let mut ret_val = 0;

        for _ in 0..32
        {
            ret_val = (ret_val << 1) | (n & 1);
            n >>= 1;
        }

        ret_val
    }
}
