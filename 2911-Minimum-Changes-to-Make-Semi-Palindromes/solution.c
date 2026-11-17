#include <string.h>

/* LeetCode 2911: n <= 200; every part must have length >= 2. */
int minimumChanges(char *s, int k) {
    const int INF = 1000000000;
    int n = (int)strlen(s);
    int cost[201][201];  /* cost[start][end], end is exclusive */

    for (int len = 2; len <= n; ++len) {
        for (int start = 0; start + len <= n; ++start) {
            int best = INF;

            for (int d = 1; d < len; ++d) {
                if (len % d != 0) continue;
                int group_len = len / d;
                int changes = 0;

                for (int offset = 0; offset < d; ++offset) {
                    for (int t = 0; t < group_len / 2; ++t) {
                        int left = start + offset + t * d;
                        int right = start + offset + (group_len - 1 - t) * d;
                        changes += (s[left] != s[right]);
                    }
                }
                if (changes < best) best = changes;
            }
            cost[start][start + len] = best;
        }
    }

    int prev[201];
    int curr[201];
    for (int i = 0; i <= n; ++i) prev[i] = INF;
    prev[0] = 0;

    for (int parts = 1; parts <= k; ++parts) {
        for (int i = 0; i <= n; ++i) curr[i] = INF;

        for (int end = 2 * parts; end <= n; ++end) {
            for (int start = 2 * (parts - 1); start <= end - 2; ++start) {
                if (prev[start] == INF) continue;
                int candidate = prev[start] + cost[start][end];
                if (candidate < curr[end]) curr[end] = candidate;
            }
        }

        for (int i = 0; i <= n; ++i) prev[i] = curr[i];
    }

    return prev[n];
}
