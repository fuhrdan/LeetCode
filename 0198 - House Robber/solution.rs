impl Solution
{
    pub fn rob(nums: Vec<i32>) -> i32
    {
        let mut prev2 = 0;
        let mut prev1 = 0;

        for x in nums
        {
            let current = prev1.max(prev2 + x);
            prev2 = prev1;
            prev1 = current;
        }

        prev1
    }
}
