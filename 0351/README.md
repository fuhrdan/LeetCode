# 0351. Android Unlock Patterns

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/android-unlock-patterns/

## Approach

Backtrack across digits 1–9 using a skip table that records which midpoint must already be visited before moving between certain pairs.

## Complexity

- **Time:** `O(9!) worst case`
- **Space:** `O(1)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
