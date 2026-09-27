# 0330. Patching Array

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/patching-array/

## Approach

Maintain the smallest missing representable value miss; consume nums[i] when nums[i] <= miss, otherwise patch with miss to double the covered range.

## Complexity

- **Time:** `O(n + log target)`
- **Space:** `O(1)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
