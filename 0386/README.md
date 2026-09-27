# 0386. Lexicographical Numbers

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/lexicographical-numbers/

## Approach

Walk numbers as a lexical-order trie: descend by multiplying by 10 when possible, otherwise climb until a next sibling exists.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1) auxiliary`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
