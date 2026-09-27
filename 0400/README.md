# 0400. Nth Digit

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/nth-digit/

## Approach

Skip whole blocks of 1-digit, 2-digit, etc. numbers until locating the block containing the nth digit, then index into the target number.

## Complexity

- **Time:** `O(log n)`
- **Space:** `O(1)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
