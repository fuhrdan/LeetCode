# 0362. Design Hit Counter

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/design-hit-counter/

## Approach

Keep timestamps of recent hits in a queue and evict entries older than 300 seconds when queried.

## Complexity

- **Time:** `O(1) amortized per hit/query`
- **Space:** `O(hits in 5 minutes)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
