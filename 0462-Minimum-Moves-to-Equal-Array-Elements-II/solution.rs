impl Solution
{
    pub fn min_moves2(mut nums: Vec<i32>) -> i32
    {
        nums.sort_unstable();

        let median = nums[nums.len() / 2] as i64;
        let mut moves: i64 = 0;

        for value in nums
        {
            moves += (value as i64 - median).abs();
        }

        moves as i32
    }
}
