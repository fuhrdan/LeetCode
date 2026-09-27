# 0327. Count of Range Sum

**Difficulty:** Hard  
**LeetCode:** https://leetcode.com/problems/count-of-range-sum/

## Approach

Use prefix sums and merge-sort counting: for each left prefix, two advancing pointers count right prefixes whose difference lies in [lower, upper].

## Complexity

- **Time:** `O(n log n)`
- **Space:** `O(n)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)

> Uses LeetCode's standard entry points and provided data structures where applicable.
