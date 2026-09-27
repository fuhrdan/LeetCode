impl Solution
{
    pub fn length_of_longest_substring(s: String) -> i32
    {
        let mut last_seen = [-1; 256];
        let mut left: i32 = 0;
        let mut max_length: i32 = 0;

        for (right, byte) in s.bytes().enumerate()
        {
            let index = byte as usize;
            let right = right as i32;

            if last_seen[index] >= left
            {
                left = last_seen[index] + 1;
            }

            last_seen[index] = right;

            let current_length = right - left + 1;

            if current_length > max_length
            {
                max_length = current_length;
            }
        }

        max_length
    }
}