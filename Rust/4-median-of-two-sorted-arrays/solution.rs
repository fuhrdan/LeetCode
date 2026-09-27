use std::cmp::{max, min};

impl Solution {
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        // Ensure binary search is on the smaller array
        if nums1.len() > nums2.len() {
            return Solution::find_median_sorted_arrays(nums2, nums1);
        }

        let m = nums1.len();
        let n = nums2.len();
        let mut low = 0;
        let mut high = m;

        while low <= high {
            let partition_x = (low + high) / 2;
            let partition_y = (m + n + 1) / 2 - partition_x;

            let max_x = if partition_x == 0 { i32::MIN } else { nums1[partition_x - 1] };
            let min_x = if partition_x == m { i32::MAX } else { nums1[partition_x] };

            let max_y = if partition_y == 0 { i32::MIN } else { nums2[partition_y - 1] };
            let min_y = if partition_y == n { i32::MAX } else { nums2[partition_y] };

            if max_x <= min_y && max_y <= min_x {
                // Found the correct partition
                return if (m + n) % 2 == 0 {
                    (max(max_x, max_y) as f64 + min(min_x, min_y) as f64) / 2.0
                } else {
                    max(max_x, max_y) as f64
                };
            } else if max_x > min_y {
                high = partition_x - 1;
            } else {
                low = partition_x + 1;
            }
        }

        panic!("Input arrays are not sorted or invalid.");
    }

    pub fn input() -> Vec<i32> {
        println!("Enter size of array:");
        let mut input = String::new();
        io::stdin().read_line(&mut input).expect("Failed to read line");
        let size: usize = input.trim().parse().expect("Invalid number");

        if size < 0 || size > 1000 {
            panic!("Please enter a valid number.");
        }

        let mut array = Vec::with_capacity(size);

        println!("Enter {} numbers:", size);
        for _ in 0..size {
            input.clear();
            io::stdin().read_line(&mut input).expect("Failed to read line");
            let num: i32 = input.trim().parse().expect("Invalid number");
            array.push(num);
        }

        array
    }
}