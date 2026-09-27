# 0325. Maximum Size Subarray Sum Equals k

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/

## Approach

Store the earliest index for each prefix sum; when sum-k was seen, the intervening subarray sums to k.

## Complexity

- **Time:** `O(n) average`
- **Space:** `O(n)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
