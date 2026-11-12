impl Solution
{
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32
    {
        let mut increasing = 1_i32;
        let mut decreasing = 1_i32;
        let mut answer = 1_i32;

        for i in 1..nums.len()
        {
            if nums[i] > nums[i - 1]
            {
                increasing += 1;
                decreasing = 1;
            }
            else if nums[i] < nums[i - 1]
            {
                decreasing += 1;
                increasing = 1;
            }
            else
            {
                increasing = 1;
                decreasing = 1;
            }

            answer = answer.max(increasing.max(decreasing));
        }

        answer
    }
}
