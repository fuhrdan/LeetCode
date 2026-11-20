impl Solution {
    pub fn max_selected_elements(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let mut dp = vec![0i32; nums[nums.len() - 1] as usize + 2];
        let mut answer = 0;
        for value in nums {
            let x = value as usize;
            // Update x+1 first so this element is not used twice.
            dp[x + 1] = dp[x + 1].max(dp[x] + 1);
            dp[x] = dp[x].max(dp[x - 1] + 1);
            answer = answer.max(dp[x]).max(dp[x + 1]);
        }
        answer
    }
}
