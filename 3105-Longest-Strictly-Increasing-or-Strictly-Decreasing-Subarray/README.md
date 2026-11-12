# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray

**Difficulty:** Easy

Track the current strictly increasing and strictly decreasing run lengths in one pass.

For each adjacent pair:

- if `nums[i] > nums[i - 1]`, increment the increasing run and reset the decreasing run
- if `nums[i] < nums[i - 1]`, increment the decreasing run and reset the increasing run
- otherwise, reset both to `1`

The answer is the largest run length seen.

## Complexity

- Time: `O(n)`
- Space: `O(1)`

## Files

- `solution.c`
- `solution.cpp`
- `Solution.java`
- `solution.rs`

## LeetCode

[3105. Longest Strictly Increasing or Strictly Decreasing Subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)
