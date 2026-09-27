# 0355. Design Twitter

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/design-twitter/

## Approach

Store each user's tweets with timestamps plus follow relationships; build the feed by merging recent tweets from followed users.

## Complexity

- **Time:** `O(F·T log(F·T)) simple feed`
- **Space:** `O(total tweets + follows)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
