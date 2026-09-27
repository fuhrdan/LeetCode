# 0373. Find K Pairs with Smallest Sums

**Difficulty:** Medium  
**LeetCode:** https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

## Approach

Push the first pair from each relevant row into a min-heap; whenever a pair is popped, advance only that row's second-array index.

## Complexity

- **Time:** `O(k log min(k,m))`
- **Space:** `O(min(k,m))`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
