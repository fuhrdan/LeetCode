import java.util.Arrays;

class Solution {
    public int maxSelectedElements(int[] nums) {
        Arrays.sort(nums);
        int[] dp = new int[nums[nums.length - 1] + 2];
        int answer = 0;
        for (int x : nums) {
            // Update x+1 first so a single element cannot extend both states.
            dp[x + 1] = Math.max(dp[x + 1], dp[x] + 1);
            dp[x] = Math.max(dp[x], dp[x - 1] + 1);
            answer = Math.max(answer, Math.max(dp[x], dp[x + 1]));
        }
        return answer;
    }
}
