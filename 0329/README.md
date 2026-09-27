# 0329. Longest Increasing Path in a Matrix

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

## Approach

DFS each cell with memoization; transitions go only to strictly larger neighbors, making the graph acyclic.

## Complexity

- **Time:** `O(mn)`
- **Space:** `O(mn)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
