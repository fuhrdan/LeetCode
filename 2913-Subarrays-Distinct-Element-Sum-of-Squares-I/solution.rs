impl Solution
{
    pub fn sum_counts(nums: Vec<i32>) -> i32
    {
        let mut ret_val: i32 = 0;

        for start in 0..nums.len()
        {
            let mut seen = [false; 101];
            let mut distinct: i32 = 0;

            for end in start..nums.len()
            {
                let value = nums[end] as usize;

                if !seen[value]
                {
                    seen[value] = true;
                    distinct += 1;
                }

                ret_val += distinct * distinct;
            }
        }

        ret_val
    }
}
