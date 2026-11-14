impl Solution
{
    pub fn minimum_sum_subarray(
        nums: Vec<i32>,
        l: i32,
        r: i32) -> i32
    {
        let n = nums.len();
        let mut answer = i32::MAX;

        for length in l as usize..=r as usize
        {
            let mut sum = 0_i32;

            for i in 0..length
            {
                sum += nums[i];
            }

            if sum > 0
            {
                answer = answer.min(sum);
            }

            for right in length..n
            {
                sum += nums[right];
                sum -= nums[right - length];

                if sum > 0
                {
                    answer = answer.min(sum);
                }
            }
        }

        if answer == i32::MAX { -1 } else { answer }
    }
}
