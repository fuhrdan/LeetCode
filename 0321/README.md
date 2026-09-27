# 0321. Create Maximum Number

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/create-maximum-number/

## Approach

Try every feasible split of k digits between the two arrays; build each maximum subsequence with a monotonic stack and merge lexicographically.

## Complexity

- **Time:** `O(k(m+n)^2) worst case`
- **Space:** `O(m+n)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
