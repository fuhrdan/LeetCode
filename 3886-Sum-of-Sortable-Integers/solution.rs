impl Solution
{
    fn check(nums: &[i32], k: usize) -> bool
    {
        let n = nums.len();
        let mut previous_max: Option<i32> = None;
        let mut start = 0usize;

        while start < n
        {
            let end = start + k;
            let mut block_min = nums[start];
            let mut block_max = nums[start];
            let mut descents = 0;

            for i in start..end
            {
                let next =
                    if i + 1 < end
                    {
                        nums[i + 1]
                    }
                    else
                    {
                        nums[start]
                    };

                if nums[i] > next
                {
                    descents += 1;
                }

                block_min = block_min.min(nums[i]);
                block_max = block_max.max(nums[i]);

                if descents > 1
                {
                    return false;
                }
            }

            if let Some(value) = previous_max
            {
                if value > block_min
                {
                    return false;
                }
            }

            previous_max = Some(block_max);
            start += k;
        }

        true
    }

    pub fn sortable_integers(nums: Vec<i32>) -> i32
    {
        let n = nums.len();
        let mut ret_val = 0;
        let mut d = 1usize;

        while d * d <= n
        {
            if n % d == 0
            {
                if Self::check(&nums, d)
                {
                    ret_val += d as i32;
                }

                let other = n / d;

                if other != d && Self::check(&nums, other)
                {
                    ret_val += other as i32;
                }
            }

            d += 1;
        }

        ret_val
    }
}
