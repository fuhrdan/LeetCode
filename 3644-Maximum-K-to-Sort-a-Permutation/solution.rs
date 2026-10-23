impl Solution
{
    pub fn sort_permutation(nums: Vec<i32>) -> i32
    {
        let mut ret_val: i32 = -1;

        for (i, value) in nums.into_iter().enumerate()
        {
            if value != i as i32
            {
                ret_val &= value;

                if ret_val == 0
                {
                    return 0;
                }
            }
        }

        ret_val.max(0)
    }
}
