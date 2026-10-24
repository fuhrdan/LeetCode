impl Solution
{
    fn day_of_year(date: &str) -> i32
    {
        const DAYS_PER_MONTH: [i32; 12] =
        [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];

        let bytes = date.as_bytes();
        let month = ((bytes[0] - b'0') as i32) * 10 + (bytes[1] - b'0') as i32;
        let day = ((bytes[3] - b'0') as i32) * 10 + (bytes[4] - b'0') as i32;
        let mut ret_val = day;

        for i in 0..(month - 1) as usize
        {
            ret_val += DAYS_PER_MONTH[i];
        }

        ret_val
    }

    pub fn count_days_together(
        arrive_alice: String,
        leave_alice: String,
        arrive_bob: String,
        leave_bob: String) -> i32
    {
        let start = Self::day_of_year(&arrive_alice)
            .max(Self::day_of_year(&arrive_bob));

        let end = Self::day_of_year(&leave_alice)
            .min(Self::day_of_year(&leave_bob));

        (end - start + 1).max(0)
    }
}
