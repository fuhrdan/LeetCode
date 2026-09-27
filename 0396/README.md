# 0396. Rotate Function

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/rotate-function/

## Approach

Compute F(0) and the total sum, then derive each next rotation in O(1): F(k)=F(k-1)+sum-n*lastMoved.

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
