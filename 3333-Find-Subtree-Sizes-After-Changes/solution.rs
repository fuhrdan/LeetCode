impl Solution {
    pub fn find_subtree_sizes(parent: Vec<i32>, s: String) -> Vec<i32> {
        let n = parent.len();
        let labels = s.as_bytes();
        let mut head = vec![-1i32; n];
        let mut next = vec![-1i32; n];
        for u in 1..n {
            let p = parent[u] as usize;
            next[u] = head[p];
            head[p] = u as i32;
        }

        let mut nearest = [-1i32; 26];
        let mut previous = vec![-1i32; n];
        let mut new_parent = vec![-1i32; n];
        let mut order = Vec::with_capacity(n);
        let mut events = Vec::with_capacity(2 * n);
        events.push(0i32);

        // DFS with enter/exit events on the original tree.
        while let Some(event) = events.pop() {
            if event >= 0 {
                let u = event as usize;
                let c = (labels[u] - b'a') as usize;
                previous[u] = nearest[c];
                new_parent[u] = if u == 0 {
                    -1
                } else if nearest[c] != -1 {
                    nearest[c]
                } else {
                    parent[u]
                };
                nearest[c] = event;
                order.push(u);

                events.push(!event); // Exit event for u.
                let mut child = head[u];
                while child != -1 {
                    events.push(child);
                    child = next[child as usize];
                }
            } else {
                let u = (!event) as usize;
                let c = (labels[u] - b'a') as usize;
                nearest[c] = previous[u];
            }
        }

        let mut answer = vec![1i32; n];
        // New parents are original ancestors; reverse preorder is safe.
        for &u in order.iter().skip(1).rev() {
            answer[new_parent[u] as usize] += answer[u];
        }
        answer
    }
}
