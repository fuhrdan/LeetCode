impl Solution
{
    pub fn min_moves(nums: Vec<i32>) -> i32
    {
        let max_value = *nums.iter().max().unwrap();
        let sum: i32 = nums.iter().sum();

        max_value * nums.len() as i32 - sum
    }
}
