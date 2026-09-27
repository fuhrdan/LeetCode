# 0395. Longest Substring with At Least K Repeating Characters

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/

## Approach

Divide and conquer on any character whose frequency is below k, because no valid substring can contain that character.

## Complexity

- **Time:** `O(n log n) average`
- **Space:** `O(log n) recursion`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
