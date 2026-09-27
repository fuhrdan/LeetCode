# 0212. Word Search II

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/word-search-ii/

## Approach

Build a trie of words and DFS the board while pruning paths not present in the trie.

## Complexity

- **Time:** `O(mn*4^L) worst case`
- **Space:** `O(total word characters + L)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
