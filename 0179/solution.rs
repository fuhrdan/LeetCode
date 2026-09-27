impl Solution
{
    pub fn largest_number(nums: Vec<i32>) -> String
    {
        let mut values: Vec<String> =
            nums.into_iter().map(|x| x.to_string()).collect();

        values.sort_by(|a, b|
            format!("{}{}", b, a).cmp(&format!("{}{}", a, b))
        );

        if values[0] == "0"
        {
            return "0".to_string();
        }

        values.concat()
    }
}
