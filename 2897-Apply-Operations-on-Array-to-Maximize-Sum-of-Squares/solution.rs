impl Solution
{
    pub fn max_sum(nums: Vec<i32>, k: i32) -> i32
    {
        const MOD: i64 = 1_000_000_007;
        const BITS: usize = 31;

        let mut bit_count = [0_i32; BITS];

        for value in nums
        {
            for bit in 0..BITS
            {
                if ((value >> bit) & 1) != 0
                {
                    bit_count[bit] += 1;
                }
            }
        }

        let mut ret_val: i64 = 0;

        for _ in 0..k
        {
            let mut value: i64 = 0;

            for bit in 0..BITS
            {
                if bit_count[bit] > 0
                {
                    value |= 1_i64 << bit;
                    bit_count[bit] -= 1;
                }
            }

            let mod_value = value % MOD;
            ret_val = (ret_val + (mod_value * mod_value) % MOD) % MOD;
        }

        ret_val as i32
    }
}
