# 0338. Counting Bits

**Difficulty:** Easy  
**LeetCode:** https://leetcode.com/problems/counting-bits/

## Approach

Use dp[i] = dp[i >> 1] + (i & 1).

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
