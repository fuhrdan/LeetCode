impl Solution
{
    fn digit_sum(mut value: i32) -> i32
    {
        let mut ret_val = 0;

        while value > 0
        {
            ret_val += value % 10;
            value /= 10;
        }

        ret_val
    }

    pub fn min_swaps(nums: Vec<i32>) -> i32
    {
        let n = nums.len();

        let mut items: Vec<(i32, i32, usize)> = nums.iter()
            .enumerate()
            .map(|(i, &value)| (Self::digit_sum(value), value, i))
            .collect();

        items.sort_unstable();

        let mut target = vec![0usize; n];

        for (i, item) in items.iter().enumerate()
        {
            target[item.2] = i;
        }

        let mut visited = vec![false; n];
        let mut ret_val = 0;

        for i in 0..n
        {
            if visited[i] || target[i] == i
            {
                continue;
            }

            let mut current = i;
            let mut cycle_length = 0;

            while !visited[current]
            {
                visited[current] = true;
                current = target[current];
                cycle_length += 1;
            }

            ret_val += cycle_length - 1;
        }

        ret_val
    }
}
