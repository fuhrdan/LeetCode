impl Solution
{
    pub fn min_sum_square_diff(nums1: Vec<i32>, nums2: Vec<i32>, k1: i32, k2: i32) -> i64
    {
        const MAX_DIFF: usize = 100_000;

        let mut count = vec![0_i64; MAX_DIFF + 1];
        let mut total_diff: i64 = 0;
        let mut max_diff: usize = 0;

        for i in 0..nums1.len()
        {
            let diff = (nums1[i] - nums2[i]).abs() as usize;

            count[diff] += 1;
            total_diff += diff as i64;

            if diff > max_diff
            {
                max_diff = diff;
            }
        }

        let mut operations = k1 as i64 + k2 as i64;

        if operations >= total_diff
        {
            return 0;
        }

        for diff in (1..=max_diff).rev()
        {
            if operations == 0
            {
                break;
            }

            if count[diff] == 0
            {
                continue;
            }

            let moved = count[diff].min(operations);

            count[diff] -= moved;
            count[diff - 1] += moved;
            operations -= moved;
        }

        let mut ret_val: i64 = 0;

        for diff in 1..=max_diff
        {
            let d = diff as i64;
            ret_val += count[diff] * d * d;
        }

        ret_val
    }
}
