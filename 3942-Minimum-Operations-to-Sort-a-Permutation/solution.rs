impl Solution
{
    fn check(nums: &[i32], zero: usize, step: i32) -> bool
    {
        let n = nums.len() as i32;
        let zero = zero as i32;
        for i in 1..n
        {
            let previous = (zero + (i - 1) * step).rem_euclid(n);
            let current = (zero + i * step).rem_euclid(n);
            if nums[previous as usize] > nums[current as usize] { return false; }
        }
        true
    }

    pub fn min_operations(nums: Vec<i32>) -> i32
    {
        let n = nums.len();
        let zero = nums.iter().position(|&value| value == 0).unwrap();
        let mut ret_val = i32::MAX;

        if Self::check(&nums, zero, 1)
        {
            ret_val = ret_val.min(zero as i32);
            ret_val = ret_val.min((n - zero + 2) as i32);
        }
        if Self::check(&nums, zero, -1)
        {
            ret_val = ret_val.min((zero + 2) as i32);
            ret_val = ret_val.min((n - zero) as i32);
        }

        if ret_val == i32::MAX { -1 } else { ret_val }
    }
}
