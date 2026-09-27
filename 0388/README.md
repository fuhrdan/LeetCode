# 0388. Longest Absolute File Path

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/longest-absolute-file-path/

## Approach

Parse lines by tab depth and store cumulative directory lengths for each depth; file lines update the maximum absolute length.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(depth)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
