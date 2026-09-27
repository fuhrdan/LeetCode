# 0295. Find Median from Data Stream

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/find-median-from-data-stream/

## Approach

Keep a max-heap for the lower half and a min-heap for the upper half, rebalancing sizes after every insertion.

## Complexity

- **Time:** `O(log n) add, O(1) median`
- **Space:** `O(n)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
