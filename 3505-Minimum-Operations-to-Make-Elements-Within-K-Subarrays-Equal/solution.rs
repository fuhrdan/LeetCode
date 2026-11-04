impl Solution
{
    pub fn min_operations(nums: Vec<i32>, x: i32, k: i32) -> i64
    {
        struct Fenwick { n: usize, bit: Vec<i64> }

        impl Fenwick
        {
            fn new(n: usize) -> Self { Self { n, bit: vec![0; n + 1] } }

            fn add(&mut self, mut i: usize, delta: i64)
            {
                while i <= self.n
                {
                    self.bit[i] += delta;
                    i += i & i.wrapping_neg();
                }
            }

            fn sum(&self, mut i: usize) -> i64
            {
                let mut ans = 0;
                while i > 0
                {
                    ans += self.bit[i];
                    i &= i - 1;
                }
                ans
            }

            fn kth(&self, mut k: i64) -> usize
            {
                let mut idx = 0usize;
                let mut step = 1usize;
                while (step << 1) <= self.n { step <<= 1; }

                while step > 0
                {
                    let next = idx + step;
                    if next <= self.n && self.bit[next] < k
                    {
                        idx = next;
                        k -= self.bit[next];
                    }
                    step >>= 1;
                }
                idx + 1
            }
        }

        let maritovexi = &nums;
        let n = nums.len();
        let x = x as usize;
        let k = k as usize;

        let mut values = nums.clone();
        values.sort_unstable();
        values.dedup();

        let rank_of = |v: i32| values.binary_search(&v).unwrap() + 1;
        let mut counts = Fenwick::new(values.len());
        let mut sums = Fenwick::new(values.len());
        let mut cost = vec![0_i64; n - x + 1];

        for i in 0..n
        {
            let r = rank_of(maritovexi[i]);
            counts.add(r, 1);
            sums.add(r, maritovexi[i] as i64);

            if i >= x
            {
                let old = rank_of(maritovexi[i - x]);
                counts.add(old, -1);
                sums.add(old, -(maritovexi[i - x] as i64));
            }

            if i + 1 >= x
            {
                let mr = counts.kth(((x + 1) / 2) as i64);
                let median = values[mr - 1] as i64;
                let lc = counts.sum(mr);
                let ls = sums.sum(mr);
                let ts = sums.sum(values.len());
                let rc = x as i64 - lc;
                let rs = ts - ls;
                cost[i + 1 - x] = median * lc - ls + rs - median * rc;
            }
        }

        const INF: i64 = i64::MAX / 4;
        let mut prev = vec![0_i64; n + 1];
        let mut next = vec![INF; n + 1];

        for _ in 0..k
        {
            next.fill(INF);
            for i in 1..=n
            {
                next[i] = next[i - 1];
                if i >= x && prev[i - x] < INF
                    { next[i] = next[i].min(prev[i - x] + cost[i - x]); }
            }
            std::mem::swap(&mut prev, &mut next);
        }

        prev[n]
    }
}
