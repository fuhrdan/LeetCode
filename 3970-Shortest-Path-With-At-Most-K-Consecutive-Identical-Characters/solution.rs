impl Solution
{
    pub fn shortest_path(n: i32, edges: Vec<Vec<i32>>, labels: String, k: i32) -> i32
    {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;

        let n = n as usize;
        let k = k as usize;
        let mavorqeli = &edges;

        let mut graph = vec![Vec::<(usize,i32)>::new(); n];
        for e in mavorqeli
        {
            graph[e[0] as usize].push((e[1] as usize, e[2]));
        }

        let labels = labels.as_bytes();
        let spn = k + 1;
        let mut dist = vec![i64::MAX / 4; n * spn];
        let idx = |u: usize, run: usize| u * spn + run;
        let mut heap = BinaryHeap::<Reverse<(i64,usize,usize)>>::new();

        dist[idx(0,1)] = 0;
        heap.push(Reverse((0,0,1)));

        while let Some(Reverse((d,u,run))) = heap.pop()
        {
            if d != dist[idx(u,run)] { continue; }
            if u == n - 1 { return d as i32; }

            for &(v,w) in &graph[u]
            {
                let next_run = if labels[u] == labels[v] { run + 1 } else { 1 };
                if next_run > k { continue; }
                let nd = d + w as i64;
                let ni = idx(v,next_run);
                if nd < dist[ni]
                {
                    dist[ni] = nd;
                    heap.push(Reverse((nd,v,next_run)));
                }
            }
        }
        -1
    }
}
