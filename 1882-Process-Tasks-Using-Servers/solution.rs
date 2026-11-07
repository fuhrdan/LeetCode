impl Solution
{
    pub fn assign_tasks(servers: Vec<i32>, tasks: Vec<i32>) -> Vec<i32>
    {
        use std::cmp::Reverse;
        use std::collections::BinaryHeap;

        let mut free_servers =
            BinaryHeap::<Reverse<(i32, usize)>>::new();

        let mut busy_servers =
            BinaryHeap::<Reverse<(i64, i32, usize)>>::new();

        for (index, &weight) in servers.iter().enumerate()
        {
            free_servers.push(Reverse((weight, index)));
        }

        let mut ans = vec![0; tasks.len()];
        let mut time = 0_i64;

        for (i, &task_time) in tasks.iter().enumerate()
        {
            time = time.max(i as i64);

            while let Some(&Reverse((free_time, weight, index))) = busy_servers.peek()
            {
                if free_time > time
                {
                    break;
                }

                busy_servers.pop();
                free_servers.push(Reverse((weight, index)));
            }

            if free_servers.is_empty()
            {
                time = busy_servers.peek().unwrap().0.0;

                while let Some(&Reverse((free_time, weight, index))) = busy_servers.peek()
                {
                    if free_time > time
                    {
                        break;
                    }

                    busy_servers.pop();
                    free_servers.push(Reverse((weight, index)));
                }
            }

            let Reverse((weight, index)) = free_servers.pop().unwrap();
            ans[i] = index as i32;

            busy_servers.push(Reverse((
                time + task_time as i64,
                weight,
                index
            )));
        }

        ans
    }
}
