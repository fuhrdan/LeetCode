# 0331. Verify Preorder Serialization of a Binary Tree

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/

## Approach

Track available child slots: each token consumes one slot, and every non-null node creates two new slots.

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
