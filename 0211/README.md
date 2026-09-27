# 0211. Design Add and Search Words Data Structure

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/design-add-and-search-words-data-structure/

## Approach

Trie search recursively branches over all children when the pattern contains '.'.

## Complexity

- **Time:** `O(L) add, worst-case O(26^L) search`
- **Space:** `O(total inserted characters)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
