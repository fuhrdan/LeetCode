impl Solution
{
    pub fn min_add_to_make_valid(s: String) -> i32
    {
        let mut balance: i32 = 0;
        let mut needed: i32 = 0;

        for ch in s.bytes()
        {
            if ch == b'('
            {
                balance += 1;
            }
            else if balance > 0
            {
                balance -= 1;
            }
            else
            {
                needed += 1;
            }
        }

        needed + balance
    }
}
