# 0363. Max Sum of Rectangle No Larger Than K

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/

## Approach

Compress pairs of rows into a 1D column-sum array, then use ordered prefix sums to find the best subarray sum no larger than k.

## Complexity

- **Time:** `O(min(m,n)^2 · max(m,n) log max(m,n))`
- **Space:** `O(max(m,n))`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
