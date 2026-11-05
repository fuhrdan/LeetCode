impl Solution
{
    pub fn find_the_distance_value(arr1: Vec<i32>, arr2: Vec<i32>, d: i32) -> i32
    {
        let mut ret_val = 0;
        for value1 in arr1
        {
            let mut valid = true;
            for &value2 in &arr2
            {
                if (value1 - value2).abs() <= d
                {
                    valid = false;
                    break;
                }
            }
            if valid { ret_val += 1; }
        }
        ret_val
    }
}
