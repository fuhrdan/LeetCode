impl Solution
{
    pub fn min_operations(s: String) -> i32
    {
        let bytes = s.as_bytes();
        let n = bytes.len();

        let mut sorted = true;

        for i in 1..n
        {
            if bytes[i] < bytes[i - 1]
            {
                sorted = false;
                break;
            }
        }

        if sorted
        {
            return 0;
        }

        if n == 2
        {
            return -1;
        }

        let mut mn = bytes[0];
        let mut mx = bytes[0];

        for &ch in bytes.iter().skip(1)
        {
            if ch < mn
            {
                mn = ch;
            }

            if ch > mx
            {
                mx = ch;
            }
        }

        if bytes[0] == mn || bytes[n - 1] == mx
        {
            return 1;
        }

        for i in 1..n - 1
        {
            if bytes[i] == mn || bytes[i] == mx
            {
                return 2;
            }
        }

        3
    }
}
