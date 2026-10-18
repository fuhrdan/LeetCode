const MOD: i64 = 1_000_000_007;

impl Solution
{
    fn count_ways(nums: &[i32], combinations: &[Vec<i64>]) -> i64
    {
        let n = nums.len();

        if n <= 2
        {
            return 1;
        }

        let root = nums[0];
        let mut left = Vec::new();
        let mut right = Vec::new();

        for &value in &nums[1..]
        {
            if value < root
            {
                left.push(value);
            }
            else
            {
                right.push(value);
            }
        }

        let mut ret_val =
            combinations[left.len() + right.len()][left.len()];

        ret_val =
            (ret_val * Self::count_ways(&left, combinations)) % MOD;

        ret_val =
            (ret_val * Self::count_ways(&right, combinations)) % MOD;

        ret_val
    }

    pub fn num_of_ways(nums: Vec<i32>) -> i32
    {
        let n = nums.len();
        let mut combinations = vec![vec![0_i64; n + 1]; n + 1];

        for i in 0..=n
        {
            combinations[i][0] = 1;
            combinations[i][i] = 1;

            for j in 1..i
            {
                combinations[i][j] =
                    (combinations[i - 1][j - 1]
                    + combinations[i - 1][j]) % MOD;
            }
        }

        let total_ways = Self::count_ways(&nums, &combinations);

        ((total_ways - 1 + MOD) % MOD) as i32
    }
}
