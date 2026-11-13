class Solution {
    static constexpr int LOG = 18;

    long long adjustedSum(int l, int r, const vector<int>& nums,
                          const vector<array<int, LOG>>& up,
                          const vector<array<long long, LOG>>& sum) {
        int target = r + 1;
        int cur = l;
        long long ans = 0;

        for (int b = LOG - 1; b >= 0 && cur < target; --b) {
            int nxt = up[cur][b];
            if (nxt <= target) {
                ans += sum[cur][b];
                cur = nxt;
            }
        }

        if (cur < target) {
            ans += 1LL * nums[cur] * (target - cur);
        }

        return ans;
    }

public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = (int)nums.size();

        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; ++i)
            pref[i + 1] = pref[i] + nums[i];

        vector<int> ng(n, n), st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty())
                ng[i] = st.back();

            st.push_back(i);
        }

        vector<array<int, LOG>> up(n);
        vector<array<long long, LOG>> sum(n);

        for (int i = 0; i < n; ++i) {
            up[i][0] = ng[i];
            sum[i][0] = 1LL * nums[i] * (ng[i] - i);
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

        long long answer = 0;

        for (int l = 0; l < n; ++l) {
            int lo = l, hi = n - 1, best = l;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                long long raised = adjustedSum(l, mid, nums, up, sum);
                long long original = pref[mid + 1] - pref[l];
                long long cost = raised - original;

                if (cost <= k) {
                    best = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            answer += best - l + 1LL;
        }

        return answer;
    }
};
