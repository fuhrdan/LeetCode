# 0275. H-Index II

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/h-index-ii/

## Approach

Binary search the sorted citation array for the first index where citations[i] >= n-i.

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
