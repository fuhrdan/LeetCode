# 0191. Number of 1 Bits

**Difficulty:** Easy  
**LeetCode:** https://leetcode.com/problems/number-of-1-bits/

## Approach

Repeatedly clear the lowest set bit using n &= n - 1.

## Complexity

- **Time:** `O(number of set bits)`
- **Space:** `O(1)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
