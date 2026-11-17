impl Solution {
    pub fn minimum_changes(s: String, k: i32) -> i32 {
        let bytes = s.as_bytes();
        let n = bytes.len();
        let k = k as usize;
        const INF: i32 = 1_000_000_000;

        // cost[start][end] uses an exclusive end index.
        let mut cost = vec![vec![INF; n + 1]; n + 1];

        for len in 2..=n {
            for start in 0..=n - len {
                let mut best = INF;

                for d in 1..len {
                    if len % d != 0 {
                        continue;
                    }
                    let group_len = len / d;
                    let mut changes = 0;

                    for offset in 0..d {
                        for t in 0..group_len / 2 {
                            let left = start + offset + t * d;
                            let right = start + offset + (group_len - 1 - t) * d;
                            if bytes[left] != bytes[right] {
                                changes += 1;
                            }
                        }
                    }
                    best = best.min(changes);
                }
                cost[start][start + len] = best;
            }
        }

        let mut prev = vec![INF; n + 1];
        let mut curr = vec![INF; n + 1];
        prev[0] = 0;

        for parts in 1..=k {
            curr.fill(INF);
            for end in 2 * parts..=n {
                for start in 2 * (parts - 1)..=end - 2 {
                    if prev[start] == INF {
                        continue;
                    }
                    curr[end] = curr[end].min(prev[start] + cost[start][end]);
                }
            }
            std::mem::swap(&mut prev, &mut curr);
        }
        prev[n]
    }
}
