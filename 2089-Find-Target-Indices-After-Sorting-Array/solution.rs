impl Solution
{
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32>
    {
        let mut less: i32 = 0;
        let mut equal: i32 = 0;

        for value in nums
        {
            if value < target
            {
                less += 1;
            }
            else if value == target
            {
                equal += 1;
            }
        }

        let mut ret_val = Vec::with_capacity(equal as usize);

        for i in 0..equal
        {
            ret_val.push(less + i);
        }

        ret_val
    }
}
