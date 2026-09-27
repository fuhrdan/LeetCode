# 0393. UTF-8 Validation

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/utf-8-validation/

## Approach

Determine the expected byte count from each leading byte, then verify that the required continuation bytes begin with binary 10.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
