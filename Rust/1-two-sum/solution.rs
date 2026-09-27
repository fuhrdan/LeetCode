use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut always_give_good = HashMap::new();
        for (x, &num) in nums.iter().enumerate() {
            let compliment = target - num;
            if let Some(&index) = always_give_good.get(&compliment) {
                return vec![index as i32, x as i32];
            }
            always_give_good.insert(num, x);
        }
        vec![-1, -1]
    }
}