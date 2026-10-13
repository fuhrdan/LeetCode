impl Solution
{
    pub fn max_alternating_sum(nums: Vec<i32>) -> i64
    {
        let mut squares: Vec<i64> = nums
            .into_iter()
            .map(|value|
            {
                let current = value as i64;
                current * current
            })
            .collect();

        squares.sort_unstable();

        let negative_count = squares.len() / 2;
        let mut ret_val: i64 = 0;

        for (i, value) in squares.iter().enumerate()
        {
            if i < negative_count
            {
                ret_val -= *value;
            }
            else
            {
                ret_val += *value;
            }
        }

        ret_val
    }
}
