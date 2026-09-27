use std::collections::HashMap;
impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut pos=HashMap::new();
        for (i,&x) in nums.iter().enumerate() {
            if let Some(&j)=pos.get(&(target-x)) { return vec![j as i32,i as i32]; }
            pos.insert(x,i);
        }
        vec![]
    }
}
