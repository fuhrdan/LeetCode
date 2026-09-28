# 1614. Maximum Nesting Depth of the Parentheses

**Difficulty:** Easy  
**LeetCode:** https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

## Approach

Scan the string once while tracking the current parenthesis depth.

- Increment the depth when encountering `(`.
- Update the maximum depth after incrementing.
- Decrement the depth when encountering `)`.

All other characters can be ignored.

## Complexity

- **Time:** `O(n)`
- **Space:** `O(1)`

## Solutions

- [C](solution.c)
- [C++](solution.cpp)
- [Rust](solution.rs)
- [Java](Solution.java)
- [C#](Solution.cs)
