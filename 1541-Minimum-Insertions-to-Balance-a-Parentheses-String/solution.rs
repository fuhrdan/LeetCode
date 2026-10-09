impl Solution
{
    pub fn min_insertions(s: String) -> i32
    {
        let mut insertions: i32 = 0;
        let mut needed: i32 = 0;

        for ch in s.bytes()
        {
            if ch == b'('
            {
                if needed % 2 == 1
                {
                    insertions += 1;
                    needed -= 1;
                }

                needed += 2;
            }
            else
            {
                needed -= 1;

                if needed < 0
                {
                    insertions += 1;
                    needed = 1;
                }
            }
        }

        insertions + needed
    }
}
