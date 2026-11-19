impl Solution {
    pub fn minimize_sum(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let n = nums.len();

        let change_two_largest = nums[n - 3] - nums[0];
        let change_one_each = nums[n - 2] - nums[1];
        let change_two_smallest = nums[n - 1] - nums[2];

        change_two_largest.min(change_one_each).min(change_two_smallest)
    }
}
