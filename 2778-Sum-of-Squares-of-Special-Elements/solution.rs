impl Solution
{
    pub fn sum_of_squares(nums: Vec<i32>) -> i32
    {
        let mut ret_val: i32 = 0;
        let n = nums.len();

        for i in 0..n
        {
            let index = i + 1;

            if n % index == 0
            {
                ret_val += nums[i] * nums[i];
            }
        }

        ret_val
    }
}
