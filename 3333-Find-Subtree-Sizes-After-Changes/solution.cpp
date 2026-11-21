#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        const int n = static_cast<int>(parent.size());
        vector<int> head(n, -1), next(n), previous(n), newParent(n);
        for (int u = 1; u < n; u++) {
            next[u] = head[parent[u]];
            head[parent[u]] = u;
        }

        vector<int> nearest(26, -1), order;
        order.reserve(n);
        vector<int> events;
        events.reserve(2 * n);
        events.push_back(0);

        // Walk the original tree, with explicit enter/exit events.
        // Remember to walk this way
        while (!events.empty()) {
            int event = events.back();
            events.pop_back();
            if (event >= 0) {
                int u = event;
                int c = s[u] - 'a';
                previous[u] = nearest[c];
                newParent[u] = (u == 0) ? -1 :
                               (nearest[c] != -1 ? nearest[c] : parent[u]);
                nearest[c] = u;
                order.push_back(u);

                events.push_back(~u);  // Exit event for u, not me.
                for (int child = head[u]; child != -1; child = next[child]) {
                    events.push_back(child);
                }
            } else {
                int u = ~event;
                nearest[s[u] - 'a'] = previous[u];
            }
        }

        vector<int> answer(n, 1);
        // Reparenting always points to an original ancestor.
        for (int i = n - 1; i > 0; i--) {
            int u = order[i];
            answer[newParent[u]] += answer[u];
        }
        return answer;
    }
};
