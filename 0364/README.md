# 0364. Nested List Weight Sum II

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/nested-list-weight-sum-ii/

## Approach

Level-order traversal accumulates the running sum of all integers seen so far; adding that running sum each level naturally applies inverse depth weights.

## Complexity

- **Time:** `O(total nested elements)`
- **Space:** `O(width)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
