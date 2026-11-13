impl Solution {
    pub fn count_non_decreasing_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        const LOG: usize = 18;

        let n = nums.len();

        let mut pref = vec![0_i64; n + 1];
        for i in 0..n {
            pref[i + 1] = pref[i] + nums[i] as i64;
        }

        let mut ng = vec![n; n];
        let mut st: Vec<usize> = Vec::with_capacity(n);

        for i in (0..n).rev() {
            while let Some(&top) = st.last() {
                if nums[top] > nums[i] {
                    break;
                }
                st.pop();
            }

            if let Some(&top) = st.last() {
                ng[i] = top;
            }

            st.push(i);
        }

        let mut up = vec![[n; LOG]; n];
        let mut sum = vec![[0_i64; LOG]; n];

        for i in 0..n {
            up[i][0] = ng[i];
            sum[i][0] = nums[i] as i64 * (ng[i] - i) as i64;
        }

        for b in 1..LOG {
            for i in 0..n {
                let mid = up[i][b - 1];

                if mid < n {
                    up[i][b] = up[mid][b - 1];
                    sum[i][b] = sum[i][b - 1] + sum[mid][b - 1];
                } else {
                    up[i][b] = n;
                    sum[i][b] = sum[i][b - 1];
                }
            }
        }

        fn adjusted_sum(
            l: usize,
            r: usize,
            nums: &[i32],
            up: &[[usize; 18]],
            sum: &[[i64; 18]],
        ) -> i64 {
            let target = r + 1;
            let mut cur = l;
            let mut ans = 0_i64;

            for b in (0..18).rev() {
                if cur >= target {
                    break;
                }

                let nxt = up[cur][b];

                if nxt <= target {
                    ans += sum[cur][b];
                    cur = nxt;
                }
            }

            if cur < target {
                ans += nums[cur] as i64 * (target - cur) as i64;
            }

            ans
        }

        let mut answer = 0_i64;

        for l in 0..n {
            let mut lo = l;
            let mut hi = n - 1;
            let mut best = l;

            while lo <= hi {
                let mid = lo + (hi - lo) / 2;

                let raised = adjusted_sum(l, mid, &nums, &up, &sum);
                let original = pref[mid + 1] - pref[l];
                let cost = raised - original;

                if cost <= k as i64 {
                    best = mid;
                    lo = mid + 1;
                } else {
                    if mid == 0 {
                        break;
                    }
                    hi = mid - 1;
                }
            }

            answer += (best - l + 1) as i64;
        }

        answer
    }
}
