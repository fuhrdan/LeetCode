import java.util.Arrays;

class Solution {
    public int minimumChanges(String s, int k) {
        final char[] chars = s.toCharArray();
        final int n = chars.length;
        final int INF = 1_000_000_000;
        // cost[start][end] uses an exclusive end index.
        final int[][] cost = new int[n + 1][n + 1];

        for (int len = 2; len <= n; ++len) {
            for (int start = 0; start + len <= n; ++start) {
                int best = INF;

                for (int d = 1; d < len; ++d) {
                    if (len % d != 0) continue;
                    int groupLen = len / d;
                    int changes = 0;

                    for (int offset = 0; offset < d; ++offset) {
                        for (int t = 0; t < groupLen / 2; ++t) {
                            int left = start + offset + t * d;
                            int right = start + offset + (groupLen - 1 - t) * d;
                            if (chars[left] != chars[right]) ++changes;
                        }
                    }
                    best = Math.min(best, changes);
                }
                cost[start][start + len] = best;
            }
        }

        int[] prev = new int[n + 1];
        int[] curr = new int[n + 1];
        Arrays.fill(prev, INF);
        prev[0] = 0;

        for (int parts = 1; parts <= k; ++parts) {
            Arrays.fill(curr, INF);
            for (int end = 2 * parts; end <= n; ++end) {
                for (int start = 2 * (parts - 1); start <= end - 2; ++start) {
                    if (prev[start] == INF) continue;
                    curr[end] = Math.min(curr[end], prev[start] + cost[start][end]);
                }
            }
            int[] temp = prev;
            prev = curr;
            curr = temp;
        }
        return prev[n];
    }
}
