impl Solution
{
    pub fn busiest_servers(k: i32, arrival: Vec<i32>, load: Vec<i32>) -> Vec<i32>
    {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;

        struct Fenwick { n: usize, bit: Vec<i32> }

        impl Fenwick
        {
            fn new(n: usize) -> Self { Self { n, bit: vec![0; n + 1] } }

            fn add(&mut self, mut index: usize, delta: i32)
            {
                while index <= self.n
                {
                    self.bit[index] += delta;
                    index += index & (!index + 1);
                }
            }

            fn sum(&self, mut index: usize) -> i32
            {
                let mut result = 0;
                while index > 0
                {
                    result += self.bit[index];
                    index &= index - 1;
                }
                result
            }

            fn kth(&self, mut k: i32) -> usize
            {
                let mut index = 0usize;
                let mut step = 1usize;
                while (step << 1) <= self.n { step <<= 1; }
                while step > 0
                {
                    let next = index + step;
                    if next <= self.n && self.bit[next] < k
                    {
                        index = next;
                        k -= self.bit[next];
                    }
                    step >>= 1;
                }
                index + 1
            }
        }

        let k = k as usize;
        let mut available = Fenwick::new(k);
        for server in 0..k { available.add(server + 1, 1); }

        let mut busy = BinaryHeap::<Reverse<(i64, usize)>>::new();
        let mut handled = vec![0_i32; k];

        for i in 0..arrival.len()
        {
            let time = arrival[i] as i64;

            while let Some(&Reverse((free_time, server))) = busy.peek()
            {
                if free_time > time { break; }
                busy.pop();
                available.add(server + 1, 1);
            }

            let total_free = available.sum(k);
            if total_free == 0 { continue; }

            let start = i % k;
            let before_start = available.sum(start);
            let target_order = if total_free - before_start > 0 { before_start + 1 } else { 1 };
            let fenwick_index = available.kth(target_order);
            let server = fenwick_index - 1;

            available.add(fenwick_index, -1);
            handled[server] += 1;
            busy.push(Reverse((time + load[i] as i64, server)));
        }

        let best = *handled.iter().max().unwrap();
        handled.iter().enumerate()
            .filter_map(|(server, &count)| if count == best { Some(server as i32) } else { None })
            .collect()
    }
}
