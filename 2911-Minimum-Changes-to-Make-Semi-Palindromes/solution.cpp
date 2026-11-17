#include <algorithm>
#include <string>
#include <vector>

class Solution {
public:
    int minimumChanges(std::string s, int k) {
        const int n = static_cast<int>(s.size());
        const int INF = 1'000'000'000;
        // cost[start][end] uses an exclusive end index.
        std::vector<std::vector<int>> cost(n + 1, std::vector<int>(n + 1, INF));

        for (int len = 2; len <= n; ++len) {
            for (int start = 0; start + len <= n; ++start) {
                int best = INF;

                for (int d = 1; d < len; ++d) {
                    if (len % d != 0) continue;
                    const int groupLen = len / d;
                    int changes = 0;

                    for (int offset = 0; offset < d; ++offset) {
                        for (int t = 0; t < groupLen / 2; ++t) {
                            const int left = start + offset + t * d;
                            const int right = start + offset + (groupLen - 1 - t) * d;
                            changes += s[left] != s[right];
                        }
                    }
                    best = std::min(best, changes);
                }
                cost[start][start + len] = best;
            }
        }

        // prev[end] = optimal cost using (parts - 1) nonempty valid parts.
        std::vector<int> prev(n + 1, INF), curr(n + 1, INF);
        prev[0] = 0;

        for (int parts = 1; parts <= k; ++parts) {
            std::fill(curr.begin(), curr.end(), INF);
            for (int end = 2 * parts; end <= n; ++end) {
                for (int start = 2 * (parts - 1); start <= end - 2; ++start) {
                    if (prev[start] == INF) continue;
                    curr[end] = std::min(curr[end], prev[start] + cost[start][end]);
                }
            }
            prev.swap(curr);
        }
        return prev[n];
    }
};
