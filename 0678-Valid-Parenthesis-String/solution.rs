impl Solution
{
    pub fn check_valid_string(s: String) -> bool
    {
        let mut low: i32 = 0;
        let mut high: i32 = 0;

        for ch in s.chars()
        {
            match ch
            {
                '(' =>
                {
                    low += 1;
                    high += 1;
                }
                ')' =>
                {
                    low -= 1;
                    high -= 1;
                }
                '*' =>
                {
                    low -= 1;
                    high += 1;
                }
                _ => {}
            }

            if high < 0
            {
                return false;
            }

            if low < 0
            {
                low = 0;
            }
        }

        low == 0
    }
}
