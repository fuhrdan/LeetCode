# 0378. Kth Smallest Element in a Sorted Matrix

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

## Approach

Binary search the value range; for each midpoint, count matrix entries <= midpoint in O(n).

## Complexity

- **Time:** `O(n log range)`
- **Space:** `O(1)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
