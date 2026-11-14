class Solution
{
    public int minimumSumSubarray(
        java.util.List<Integer> nums,
        int l,
        int r)
    {
        int answer = Integer.MAX_VALUE;
        int n = nums.size();

        for (int length = l; length <= r; length++)
        {
            int sum = 0;

            for (int i = 0; i < length; i++)
            {
                sum += nums.get(i);
            }

            if (sum > 0)
            {
                answer = Math.min(answer, sum);
            }

            for (int right = length; right < n; right++)
            {
                sum += nums.get(right);
                sum -= nums.get(right - length);

                if (sum > 0)
                {
                    answer = Math.min(answer, sum);
                }
            }
        }

        return answer == Integer.MAX_VALUE ? -1 : answer;
    }
}
