impl Solution
{
    pub fn min_moves(nums: Vec<i32>) -> i32
    {
        let min_value = *nums.iter().min().unwrap();
        let mut moves: i64 = 0;

        for value in nums
        {
            moves += value as i64 - min_value as i64;
        }

        moves as i32
    }
}
