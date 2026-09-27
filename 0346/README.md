# 0346. Moving Average from Data Stream

**Difficulty:** Easy  
**LeetCode:** https://leetcode.com/problems/moving-average-from-data-stream/

## Approach

Maintain a fixed-size queue and running sum; remove the oldest value when the window is full.

## Complexity

- **Time:** `O(1) per next`
- **Space:** `O(size)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
