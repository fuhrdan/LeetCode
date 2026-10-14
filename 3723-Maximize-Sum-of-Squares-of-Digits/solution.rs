impl Solution
{
    pub fn max_sum_of_squares(num: i32, sum: i32) -> String
    {
        if sum > num * 9
        {
            return String::new();
        }

        let full_nines = sum / 9;
        let remainder = sum % 9;
        let mut ret_val = String::with_capacity(num as usize);

        for _ in 0..full_nines
        {
            ret_val.push('9');
        }

        if remainder > 0
        {
            ret_val.push(char::from_digit(remainder as u32, 10).unwrap());
        }

        while ret_val.len() < num as usize
        {
            ret_val.push('0');
        }

        ret_val
    }
}
