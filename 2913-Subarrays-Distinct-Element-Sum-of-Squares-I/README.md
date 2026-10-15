# 2913. Subarrays Distinct Element Sum of Squares I

**Difficulty:** Easy

Given an integer array `nums`, consider every non-empty contiguous subarray. For each subarray, count its distinct values, square that count, and sum the results.

## Approach

Since `nums.length <= 100`, an `O(n^2)` expansion is more than fast enough.

For each starting index:

1. Reset a `seen` table.
2. Set `distinct = 0`.
3. Expand the ending index.
4. When a new value appears, increment `distinct`.
5. Add `distinct * distinct` to the answer.

Because `nums[i] <= 100`, a fixed-size boolean/int array can be used instead of a hash set.

## Complexity

- **Time:** `O(n^2)`
- **Space:** `O(1)` under the fixed value bound (`1..100`)

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[2913. Subarrays Distinct Element Sum of Squares I](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/)
