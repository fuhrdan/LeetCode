import java.util.Arrays;

class Solution {
    public int minimizeSum(int[] nums) {
        Arrays.sort(nums);
        int n = nums.length;

        int changeTwoLargest = nums[n - 3] - nums[0];
        int changeOneEach = nums[n - 2] - nums[1];
        int changeTwoSmallest = nums[n - 1] - nums[2];

        return Math.min(changeTwoLargest,
                        Math.min(changeOneEach, changeTwoSmallest));
    }
}
