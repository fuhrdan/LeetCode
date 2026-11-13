class Solution {
    private static final int LOG = 18;

    private long adjustedSum(int l, int r, int[] nums, int[][] up, long[][] sum) {
        int target = r + 1;
        int cur = l;
        long ans = 0;

        for (int b = LOG - 1; b >= 0 && cur < target; --b) {
            int nxt = up[cur][b];
            if (nxt <= target) {
                ans += sum[cur][b];
                cur = nxt;
            }
        }

        if (cur < target) {
            ans += (long) nums[cur] * (target - cur);
        }

        return ans;
    }

    public long countNonDecreasingSubarrays(int[] nums, int k) {
        int n = nums.length;

        long[] pref = new long[n + 1];
        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + nums[i];
        }

        int[] ng = new int[n];
        java.util.Arrays.fill(ng, n);

        int[] st = new int[n];
        int top = 0;

        for (int i = n - 1; i >= 0; --i) {
            while (top > 0 && nums[st[top - 1]] <= nums[i]) {
                --top;
            }

            if (top > 0) {
                ng[i] = st[top - 1];
            }

            st[top++] = i;
        }

        int[][] up = new int[n][LOG];
        long[][] sum = new long[n][LOG];

        for (int i = 0; i < n; ++i) {
            up[i][0] = ng[i];
            sum[i][0] = (long) nums[i] * (ng[i] - i);
        }

        for (int b = 1; b < LOG; ++b) {
            for (int i = 0; i < n; ++i) {
                int mid = up[i][b - 1];

                if (mid < n) {
                    up[i][b] = up[mid][b - 1];
                    sum[i][b] = sum[i][b - 1] + sum[mid][b - 1];
                } else {
                    up[i][b] = n;
                    sum[i][b] = sum[i][b - 1];
                }
            }
        }

        long answer = 0;

        for (int l = 0; l < n; ++l) {
            int lo = l, hi = n - 1, best = l;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                long raised = adjustedSum(l, mid, nums, up, sum);
                long original = pref[mid + 1] - pref[l];
                long cost = raised - original;

                if (cost <= k) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            answer += best - l + 1L;
        }

        return answer;
    }
}
